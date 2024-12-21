#define _GNU_SOURCE

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

typedef enum {
	MECH,
	CIVIL,
	ECE,
	EEE,
	NOP,
} dept_t;

struct enStringDept {
	dept_t st_dept;
	char *dpt;
};

struct enStringDept Dept[5] = {
	{ MECH, "Mechanical" },
	{ CIVIL, "Civil" },
	{ ECE, "Electronics and Communication Engg" },
	{ EEE, "Electronics and Electrical Engg" },
	{ NOP, NULL },
};

typedef struct std {
	char *st_name;
	uint32_t st_rollNo;
	dept_t st_dept;
	struct std *next;
} std_t;

char *enumToString(dept_t dpt) {
	return Dept[dpt].dpt;
}

std_t *head = NULL;

bool checkDatabase(std_t **ptr, uint32_t rollNo) {
	bool find = false;
	std_t *temp = NULL;
	temp = *ptr;

	while(temp != NULL) {
		if (temp->st_rollNo == rollNo) {
			*ptr = temp;
			find = true;
			break;
		}
		temp = temp->next;
	}
	return find;
}

void searchNode(uint32_t rollNo) {
	std_t *ptr = NULL;
	
	if (head == NULL) {
		printf("database is empty\n");
		return;
	} else {
		ptr = head;
		if (checkDatabase(&ptr, rollNo)) {
			for(int i=0; i<70; i++) printf("*");
			printf("\n%*s %*s - %*s\n", 5, "", -20, "Parameter", -45, "Response");
			for(int i=0; i<70; i++) printf("*");

			printf("\n%*s %*s - %*d\n", 5, "", -20, "RegNo", -45, ptr->st_rollNo);
			printf("%*s %*s - %*s\n", 5, "", -20, "Name", -45, ptr->st_name);
			printf("%*s %*s - %*s\n\n", 5, "", -20, "Dept", -45, enumToString(ptr->st_dept));
			
			for(int i=0; i<70; i++) printf("*");
			printf("\n");
		} else {
			printf("\nprovided date doesn't match with database\n\n");
		}
	}
}

void display(void) {
	std_t *ptr = NULL;

	if (head == NULL) {
		printf("database is empty\n");
		return;
	} else {
		ptr = head;
		printf("\n\n");
		for(int i=0; i<70; i++) printf("*");
		printf("\n%*s %*s - %*s\n", 5, "", -20, "Parameter", -45, "Response");
		for(int i=0; i<70; i++) printf("*");
		printf("\n");

		while(ptr != NULL) {
			 printf("%*s %*s - %*d\n", 5, "", -20, "RegNo", -45, ptr->st_rollNo);
			 printf("%*s %*s - %*s\n", 5, "", -20, "Name", -45, ptr->st_name);
			 printf("%*s %*s - %*s\n\n", 5, "", -20, "Dept", -45, enumToString(ptr->st_dept));
			 ptr = ptr->next;
		}
		for(int i=0; i<70; i++) printf("*");
		printf("\n");
	}
	free(ptr);
}

#if 0
std_t *stdMemAlloc(void) {
	std_t *ptr = NULL;

	ptr = (std_t *) malloc(sizeof(std_t));
	if (ptr == NULL) {
		printf("memory allocation getting failed\n");
		return NULL;
	}
	return ptr;
}
#endif

void addData(char *name, uint32_t rollNo, dept_t dep) {
	std_t *ptr, *temp;
#if 0
	ptr = stdMemAlloc();
	if (ptr == NULL) {
		return;
	}
#endif
	ptr = (std_t *) malloc(sizeof(std_t));
	if (ptr == NULL) {
		printf("memory allocation getting failed\n");
		return;
	}

	asprintf(&ptr->st_name, "%s", name);
	ptr->st_rollNo = rollNo;
	ptr->st_dept = dep;
	ptr->next = NULL;

	if (head == NULL) {
		head = ptr;
	} else {
		temp = head;
		if (!checkDatabase(&temp, rollNo)) {
			while(temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = ptr;
		} else {
			printf("\n%d User data already available in database\n\n", rollNo);
			return;
		}
	}
	printf("\nUser data added in database successfully\n\n");
}

void updateData(char *name, uint32_t rollNo, dept_t dep) {
	std_t *ptr = NULL;
	if (head == NULL) {
		printf("database is empty can't modify data\n");
		return;
	} else {
		ptr = head;

		if (checkDatabase(&ptr, rollNo)) {
			asprintf(&ptr->st_name, "%s", name);
			ptr->st_dept = dep;
			printf("\nUser data modified in database successfully\n\n");
		} else
			printf("\nprovided date doesn't match with database\n\n");
	}
}

void deleteData(uint32_t rollNo) {
	std_t *ptr, *temp;
	bool find = false;
	if (head == NULL) {
		printf("database is empty can't delete data\n");
		return;
	}
	if (head->st_rollNo == rollNo) {
		ptr = head->next;
		find = true;
		free(head);
		head = ptr;
		printf("\nUser data deleted in database successfully\n\n");
	} else {
		ptr = head;
		while(ptr != NULL) {
			if (ptr->st_rollNo == rollNo) {
				temp->next = ptr->next;
				free(ptr);
				ptr = NULL;
				find = true;
				printf("\nUser data deleted in database successfully\n\n");
				break;
			}
			temp = ptr;
			ptr = ptr->next;
		}
	}
	if (!find) {
		printf("\nprovided date doesn't match with database\n\n");
	}
}

void searchDelete(bool del) {
	uint32_t rollNo;
	
	printf("Roll No    : ");
	if (scanf("%d", &rollNo) > 6) {
		while (getchar() != '\n');
		printf("\n\nsomething wrong with input try again\n\n");
		return;
	}

	if (del) {
		deleteData(rollNo);
	} else {
		searchNode(rollNo);
	}
}

void studDetails(bool add) {
	char name[50];
	uint32_t rollNo;
	int dept;
	
	printf("Roll No    : ");
	if (scanf("%d[1-1000]", &rollNo) != 1) {
		while (getchar() != '\n');
		printf("\n\nsomething wrong with input try again\n\n");
		return;
	}
	
	printf("\nEnter Name : ");
	scanf("%s",name);
	while (getchar() != '\n');
	
	for(uint8_t i = 0; i < NOP; i++) {
		printf("\n%d. %s", i, enumToString(i));
	}
DEPT:
	printf("\n\nEnter Dept : ");
	if (scanf("%d", &dept) != 1) {
		while (getchar() != '\n');
	}

	if (NOP <= dept || 0 > dept) {
		printf("invalid dept\nchoose again\n");
		goto DEPT;
	}
	
	if (add)
		addData(name, rollNo, dept);
	else
		updateData(name, rollNo, dept);
}

void main(void) {

	int option;

DASH:
	printf("\n\tStudent Database Dashboard\n\n");
	printf("1. Add Student\t\t2. Remove Student\n3. Search Student\t4. Modify Student\n5. Display Database\t6. Exit\n\nChoose option : ");

	if (scanf("%d", &option) != 1) {
		printf("\nInvalid Option Choose right option given below\n\n");
		while (getchar() != '\n');
		goto DASH;
	}

	
	switch(option) {
		case 1:
			studDetails(true);
			break;
		case 2:
			searchDelete(true);
			break;
		case 3:
			searchDelete(false);
			break;
		case 4:
			studDetails(false);
			break;
		case 5:
			display();
			break;
		case 6:
			break;
		default:
			printf("Wrong selection\n\n");
			goto DASH;
			break;
	}

	if (0 < option && 6 > option)
		goto DASH;

#if 0
	addData("vijay", 12345, ECE);
	addData("pradap", 12345, ECE);

	addData("sai", 12346, ECE);
	addData("sri", 12347, ECE);
	addData("jai", 12348, ECE);
	
	display();
	
	updateData("pradap", 12345, ECE);
	display();
	deleteData(12348);
	display();

	searchNode(12345);
#endif

	printf("\n\t\tSigning OFF\n\n");

	while(head != NULL) {
		free(head->st_name);
		head = head->next;
	}

	free(head);
}
