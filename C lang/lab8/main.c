#include <stdio.h>
#include <malloc.h>
#include <time.h>

#define ONE 1

typedef struct numbers{
    double number;
    struct numbers *next;
}numbers;

numbers* init(double n){
    numbers *tmp;
    tmp = (numbers*)malloc(sizeof(numbers));
    tmp->number = n;
    tmp->next = NULL;
    return tmp;
}

numbers* add(numbers *elem, double n){
    numbers *tmp, *ptr;
    tmp = (numbers*)malloc(sizeof(numbers));
    ptr = elem->next;
    elem->next = tmp;
    tmp->number = n;
    tmp->next = ptr;
    return tmp;
}

void push(numbers *elem, double n){
    numbers *tmp;
    tmp = (numbers*)malloc(sizeof(numbers));

    while (elem->next != NULL){
        elem = elem->next;
    }
    tmp->number = n;
    tmp->next = NULL;
    elem->next = tmp;

}

double findMax(numbers *elem){
    double found = 0;
    while(elem->next != NULL){
        if (elem->number > found)
            found = elem->number;
        elem = elem->next;
    }
    if (elem->number > found)
        found = elem->number;
    return found;
}

void replace(numbers *elem){
    double max;
    max = findMax(elem);
    while(elem->next != NULL){
        if (elem->number == ONE)
            elem = add(elem, max);
        elem = elem->next;
    }
    if (elem->number == ONE)
        elem = add(elem, max);
}

void print(numbers *elem){
    while (elem->next != NULL) {
        printf("%g\n", elem->number);
        elem = elem->next;
    }
    printf("%g\n", elem->number);
}

int main() {
    struct numbers *head;
    double test;
    srand(time(NULL));

    head = init((double) rand() / RAND_MAX * 10);
    for (int i = 0; i < 7; i++) {
        if (i % 3 == 0)
            push(head, 1);
        else
            push(head, (double) rand() / RAND_MAX * 10);
    }

    printf("Before:\n");
    print(head);

    test = findMax(head);
    printf("\nMax element is: %g\n", test);
    replace(head);

    printf("\nAfter:\n");
    print(head);
}
