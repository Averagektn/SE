#include <stdio.h>
#include <malloc.h>

void main() {
    int n, count = 0, sum = 0;

    printf("Enter length of the array\n");
    scanf("%d",&n);

    int arr[n];
    srand(n);
    printf("Array:");

    for (int i = 0; i < n; i++){
        arr[i] = rand() % 200 - 100;
        printf(" %d",arr[i]);
    }

    for (int i = 0; i < n; i++){
        if (arr[i] < 0)
            count++;
        else
            sum += arr[i];
    }

    printf("\nSum of positive: %d\n",sum);
    printf("Number of negative: %d",count);

}