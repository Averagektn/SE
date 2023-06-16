#include <stdio.h>
#include <malloc.h>

void main() {
    int n;

    printf("Enter length of the array\n");
    scanf("%d",&n);

    int arr[n];
    srand(n);
    printf("Array:");

    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100;
        printf(" %d",arr[i]);
    }

    printf("\nDoubled odds:");

    for (int i = 0; i < n; i++){
        if ((arr[i] % 4 != 0) && (arr[i] % 2 == 0))
            printf(" %d",arr[i]);
    }

    printf("\nNumbers that are when divided by 7 give a remainder of 1, 2 or 5:");

    for (int i = 0; i < n; i++){
        if ((arr[i] % 7 == 1) || (arr[i] % 7 == 2) || (arr[i] % 7 == 5))
            printf(" %d",arr[i]);
    }

}
