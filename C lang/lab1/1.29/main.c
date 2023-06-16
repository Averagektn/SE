#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <conio.h>

int main() {
    const int SIZE = 50, MIN = 0;
    int num, ind;
    float arr[SIZE], diff;

    printf("Enter number\n");
    scanf("%d",&num);
    printf("Array:");

    for (int i = MIN; i < SIZE; i++) {
        arr[i] = rand() % 100;
        arr[i] = (float) arr[i] / 10;
        printf(" %g",arr[i]);
    }

    ind = 0;
    diff = fabs(arr[0] - num);
    for (int i = MIN + 1; i < SIZE; i++){
        if (fabs(arr[i] - num) < diff){
            diff = fabs(arr[i] - num);
            ind = i;
        }
    }

    printf("\nThe closest number to %d is %g in %d position",num,arr[ind],ind);
    getch();
}
