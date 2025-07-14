/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node *next;
} node_t;

int insert(node_t **head, int data) {
    
    node_t *ptr = NULL, *tmp = NULL;
    
    ptr = (node_t *)malloc(sizeof(node_t));
    if (ptr == NULL) {
        printf("malloc() failed to allocate mem\n");
        return -1;
    }
    
    ptr->a = data;
    
    if (*head == NULL) {
        *head = ptr;
        ptr->next = *head;
    } else {
        tmp = *head;
        while (tmp->next != *head) {
            tmp = tmp->next;
        }
        tmp->next = ptr;
        ptr->next = *head;
    }
    
    return 0;
}

int main()
{
    node_t *head = NULL;
    
    for(int i = 0; i < 10; i++) {
        if (insert(&head, i) != 0) {
            printf("failed to insert data in list\n");
            return -1;
        }
    }
    
    node_t *tmp = head;
    
    printf("display : ");
    do {
        printf("%d ", tmp->a);
        tmp = tmp->next;
    } while(tmp != head);

    free(head);
    return 0;
}