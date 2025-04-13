#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 32  /* the maximal number of processes in the system */
#define MAX_NAME_LEN  32

/* Process control block - 
 * holding all process relevant informations 
 */
struct pcb{
	int pid;                   /* ID of the proces */
	int prio;                  /* process priority */
	int attached;              /* 1 if attached to processlist, else 0 */
	int *function;             /* pointer to the process function */
	char name[MAX_NAME_LEN];   /* Name of the process */
};

static struct pcb processlist[MAX_PROCESSES];
int process0(int);
int process1(int);

int process_attach(char *name, int prio, void *function)
{
	int i = 0;
	int ret = -1;
	printf("[dbg] process_attach\n");
	while(i < MAX_PROCESSES)
	{
		if(strlen(name) > MAX_NAME_LEN)
		{
			printf("[err] wrong stringlen\n");
			return ret;
		}

		if(processlist[i].attached != 1)
		{
			printf("attach process at %d\n", i);
			processlist[i].pid = i;
			strcpy(processlist[i].name, name);
			processlist[i].prio = prio;
			processlist[i].function = function;
			processlist[i].attached = 1;
			ret = 0;
			break;
		}
		printf("\n");
		i++;
	}
	return ret; 
}

int process_detach(int pid)
{
	processlist[pid].attached = 0;
	printf("detaching the process id : %d\n", pid);
	return 0;
}

/*
 * basic implementation of a RR scheduler 
 */
int scheduler()
{
	int i = 0, x = 0;
	int (*p)(int);

	while(1)
	{
		for(i = 0; i < MAX_PROCESSES; i++)
		{
			if(processlist[i].attached == 1)
			{
				p = (void *)processlist[i].function;
				printf("pid : %d and return %d\n", i, (*p)(i));
			}
		}

		if (x > 5) {
			for(i = 0; i < MAX_PROCESSES; i++)
				if (processlist[i].attached == 1)
					process_detach(i);
			break;
		}
		x++;
	}
	return 0;
}

/*** Testdriver ***/
int process0(int pid)
{
	printf("pid : %d\n", pid);
	sleep(1);
	return 0;
}

int process1(int pid)
{
	printf("pid : %d\n", pid);
	sleep(1);
	return 0;
}

int main()
{
	/*
	 * test run here
	 * */
	printf("basic_scheduler Demo\n");
	process_attach("process0", 100, process0);
	process_attach("process1", 50,  process1);
	scheduler();
	return 0;
}
