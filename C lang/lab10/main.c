#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}node;

node *init(int elem){
    node *tmp;
    tmp = (node*)malloc(sizeof(node));
    tmp->number = elem;
    tmp->next = NULL;
    return tmp;
}

node* push(node *ptr, int elem){
    node *tmp;
    tmp = (node*)malloc(sizeof(node));
    tmp->number = elem;
    tmp->next = ptr;
    return tmp;
}

void swap(node *ptr){
    int tmp;
    tmp = ptr->number;
    ptr->number = ptr->next->number;
    ptr->next->number = tmp;
}

void sort(node *ptr){
    while (ptr->next != NULL && ptr->number > ptr->next->number){
        swap(ptr);
        ptr = ptr->next;
    }
}

node* add(node *ptr, int elem){
    if (ptr == NULL)
        ptr = init(elem);
    else
        ptr = push(ptr, elem);
    sort(ptr);
    return ptr;
}

void print(node *ptr){
    while(ptr->next != NULL) {
        printf("%d\n", ptr->number);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->number);
}

int main(){
    node *head = NULL;
    int isAdd = 1, num;
    while(isAdd){
        printf("Enter number\n");
        scanf_s("%d",&num);
        head = add(head, num);
        print(head);
        printf("Would you like to add another element?\n1: yes\n0: no\n");
        scanf_s("%d", &isAdd);
    }
}