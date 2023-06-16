#include <stdio.h>
#include <stdlib.h>

int comp (const int *i, const int *j)
{
    return *i - *j;
}

void main() {
    const int SIZE = 100, MIN = 0;
    float arr[SIZE], diff;

    printf("Array:");

    for (int i = MIN; i < SIZE; i++) {
        arr[i] = rand() % 1000;
        arr[i] = (float) arr[i] / 100;
        printf(" %g",arr[i]);
    }

    qsort(arr,SIZE,sizeof(float),comp);

    printf("\nSorted array:");
    for (int i = MIN; i < SIZE; i++) {

        printf(" %g",arr[i]);
    }

    diff = arr[SIZE - 1] - arr[MIN];
    printf("\nDifference between the biggest and the least is %g",diff);
}