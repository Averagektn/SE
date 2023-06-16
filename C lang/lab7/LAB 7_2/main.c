#include <stdio.h>
#define NAME 16
#define GROUP 30

struct student{
    char firstName[NAME], lastName[NAME];
    int age;
};

void swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct student arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[largest].age)
        largest = left;

    if (right < n && arr[right].age < arr[largest].age)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(struct student arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}



int main() {
    struct student students[GROUP];
    FILE *f1, *f;
    char nameF1[] = "f1.txt", nameF[] = "f.txt";
    int i = 0;

    f1 = fopen(nameF1, "r");
    while (fgets(students[i].firstName, NAME - 1, f1) != NULL && i < GROUP) {
        fgets(students[i].lastName, NAME - 1, f1);
        fscanf_s(f1, "%d", &students[i].age);
        printf("%s", students[i].firstName);
        printf("%s", students[i].lastName);
        printf("%d\n", students[i].age);
        fgetc(f1);
        i++;
    }
    fclose(f1);

    heapSort(students, i);

    i = 0;
    int tmp = students[i].age;
    f = fopen(nameF, "w");
    printf("Result:\n");
    while (students[i].age == tmp){
        fputs(students[i].firstName, f);
        fputs(students[i].lastName, f);
        fprintf(f, "%d\n", students[i].age);
        printf("%s", students[i].firstName);
        printf("%s", students[i].lastName);
        printf("%d\n", students[i].age);
        i++;
    }
    fclose(f);
}