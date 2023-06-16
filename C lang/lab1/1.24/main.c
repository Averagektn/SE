#include <stdio.h>
#include <malloc.h>

void main() {
    int n, count = 0;

    printf("Enter length of the array\n");
    scanf("%d",&n);

    int arr[n];
    srand(n);
    printf("Array:");

    for (int i = 0; i < n; i++){
        arr[i] = rand() % 10;
        printf(" %d",arr[i]);
    }

    for (int i = 0; i < n; i++){
        if (arr[i] > 7){
            arr[i] = 7;
            count++;
        }
    }

    printf("\nNew array:");

    for (int i = 0; i < n; i++)
        printf(" %d",arr[i]);

    printf("\nNumber of changed elements: %d",count);

}
