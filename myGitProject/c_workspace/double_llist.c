#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void printVal(void) {
    struct node *ptr = head;
    printf("\ndisplaying database : ");
    while(ptr != NULL) {
        printf("%d ", ptr->a);
        ptr = ptr->next;
    }
    printf("\n");
}

void addBegin(int a) {
    struct node *ptr = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("memory allocation failed\n");
        return;
    }
    ptr->a = a;
    ptr->prev = NULL;
    
    if (head == NULL) {
        ptr->next = NULL;
    } else {
        ptr->next = head;
        head->prev = ptr; // Update the previous head's prev pointer
    }
    head = ptr;
    printVal();
}

void addLast(int a) {
    struct node *ptr = NULL, *tmp = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("memory allocation failed\n");
        return;
    }
    ptr->a = a;
    ptr->next = NULL;
    
    if (head == NULL) {
        ptr->prev = NULL;
        head = ptr;
    } else {
        tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        ptr->prev = tmp;
        tmp->next = ptr;
    }
    printVal();
}

void delBegin(void) {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    } else if (head->next == NULL) {
        free(head);
        head = NULL; // Set head to NULL after freeing
        printf("\nOne node was there and removed\n");
        return;
    } else {
        struct node *ptr = head;
        head = ptr->next; // Update head before setting ptr->prev to NULL
        head->prev = NULL; // Update the new head's prev pointer
        free(ptr);
        ptr = NULL;
    }
    printVal();
}

void delLast(void) {
    struct node *ptr = NULL;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    } else if (head->next == NULL) {
        free(head);
        head = NULL; // Set head to NULL after freeing
        printf("\nOne node was there and removed\n");
        return;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        // Now ptr is pointing to the last node
        if (ptr->prev != NULL) {
            ptr->prev->next = NULL;
        }
        free(ptr);
        ptr = NULL; // Set ptr to NULL after freeing
    }
    printVal();
}

int main() {
    addBegin(15);
    addBegin(10);
    // addBegin(5);
    
    delLast();
    addLast(20);
    addBegin(5);
    delBegin();
    delLast();

    return 0;
}