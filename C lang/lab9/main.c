#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEL 15
#define SURNAME 15

typedef struct telephone{
    char surname[SURNAME];
    char number[TEL];
    int year;
    struct telephone *next;
}telephone;

telephone *init(telephone elem){
    telephone *tmp;
    tmp = (telephone *)malloc(sizeof(telephone));
    strcpy(tmp->number, elem.number);
    strcpy(tmp->surname, elem.surname);
    tmp->year = elem.year;
    tmp->next = NULL;
    return tmp;
}

int check(telephone *ptr, char *number, char *surname){
    while(ptr->next != NULL){
        if (strcmp(ptr->number, number) == 0 || strcmp(ptr->surname, surname) == 0) {
            printf("THIS NUMBER/SURNAME IS ALREADY EXISTS\n");
            return 1;
        }
        ptr = ptr->next;
    }
    if (strcmp(ptr->number, number) == 0 || strcmp(ptr->surname, surname) == 0) {
        printf("THIS NUMBER/SURNAME IS ALREADY EXISTS\n");
        return 1;
    }
    return 0;
}

void push(telephone *ptr, telephone elem){
    telephone *tmp;
    tmp = (telephone*)malloc(sizeof(telephone));

    while (ptr->next != NULL)
        ptr = ptr->next;
    strcpy(tmp->number, elem.number);
    strcpy(tmp->surname, elem.surname);
    tmp->year = elem.year;
    tmp->next = NULL;
    ptr->next = tmp;
}

telephone readData(){
    telephone elem;
    printf("Enter surname\n");
    scanf_s("%s", elem.surname);
    strcat(elem.surname, "\n");
    printf("Enter telephone number\n");
    scanf_s("%s", elem.number);
    strcat(elem.number, "\n");
    printf("Enter date\n");
    scanf_s("%d",&elem.year);
    return elem;
}

void out(telephone *ptr){
    printf("\nSurname: %s", ptr->surname);
    printf("Telephone: %s", ptr->number);
    printf("Year: %d\n", ptr->year);
}

void print(telephone *ptr){
    if (ptr == NULL)
        return;
    while(ptr->next != NULL){
        out(ptr);
        ptr = ptr->next;
    }
    out(ptr);
}

void fromYear(telephone *ptr, int year){
    while(ptr->next != NULL){
        if (ptr->year >= year)
            out(ptr);
        ptr = ptr->next;
    }
    if (ptr->year >= year)
        out(ptr);
}

void findSurname(telephone *ptr, char *surname){
    strcat(surname, "\n");
    while(ptr->next != NULL && strcmp(ptr->surname, surname) != 0){
        ptr = ptr->next;
    }
    if (strcmp(ptr->surname, surname) == 0)
        out(ptr);
    else
        printf("No matches\n");
}

telephone *delete(telephone *ptr, char *surname){
    telephone *curr = ptr, *prev = NULL;
    strcat(surname, "\n");
    if (ptr == NULL)
        return NULL;
    while (strcmp(curr->surname, surname) != 0 && curr != NULL){
        prev = curr;
        curr = curr->next;
    }
    if (curr == ptr){
        free(ptr);
        return curr->next;
    }
    if (curr == NULL)
        return ptr;
    prev->next = curr->next;
    free(curr);
    return ptr;
}

int main() {
    FILE *f1;
    char nameF1[] = "F1.txt";
    telephone *head = NULL;
    telephone tmp;
    telephone elements;
    f1 = fopen(nameF1, "r");
    while (fgets(elements.surname, SURNAME, f1) != NULL) {
        fgets(elements.number, TEL, f1);
        fscanf_s(f1, "%d", &elements.year);
        fgetc(f1);
        tmp = elements;
        if (head == NULL)
            head = init(tmp);
        else {
            if (!check(head, tmp.number, tmp.surname))
                push(head, tmp);
        }
    }
    fclose(f1);
    int isExit = 0;
    while(!isExit) {
        int selector;
        printf("\nChoose option:\n"
               "1. Add element\n"
               "2. Find from year\n"
               "3. Find surname\n"
               "4. Delete element\n"
               "5. Print whole list\n"
               "6. Exit\n");
        scanf_s("%d", &selector);
        switch (selector) {
            case 1: {
                tmp = readData();
                if (head == NULL)
                    head = init(tmp);
                else {
                    if (!check(head, tmp.number, tmp.surname))
                        push(head, tmp);
                }
                break;
            }
            case 2: {
                int year;
                printf("Enter year\n");
                scanf_s("%d", &year);
                fromYear(head, year);
                break;
            }
            case 3: {
                char surname[SURNAME];
                printf("Enter surname\n");
                scanf_s("%s", surname);
                findSurname(head, surname);
                break;
            }
            case 4: {
                char surname[SURNAME];
                printf("Enter surname\n");
                scanf_s("%s", surname);
                head = delete(head, surname);
                break;
            }
            case 5:
                print(head);
                break;
            default: isExit = 1;
        }
    }
    f1 = fopen(nameF1, "w");
    while(head->next != NULL){
        fprintf(f1, "%s", head->surname);
        fprintf(f1, "%s", head->number);
        fprintf(f1, "%d\n", head->year);
        head = head->next;
    }
    fprintf(f1, "%s", head->surname);
    fprintf(f1, "%s", head->number);
    fprintf(f1, "%d\n", head->year);
    fclose(f1);
}