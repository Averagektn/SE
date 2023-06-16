#include <stdio.h>
#include <malloc.h>
#include <math.h>

int check(int num, int base){
    if (num % base == 0)
        return 1;
    else
        return 0;
}

void main() {
    int n, count_a = 0, count_b = 0;
    double mod,tmp;

    printf("Enter length of the array\n");
    scanf("%d",&n);

    int arr[n];

    srand(n);
    printf("Array:");

    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100;
        printf(" %d",arr[i]);
    }

    printf("\nEven squares:");

    for (int i = 0; i < n; i += 2){
        if (check(arr[i],2)) {
            mod = modf(sqrt(arr[i]),&tmp);
            if (mod == 0) {
                printf(" %d", arr[i]);
                count_a++;
            }
        }
    }

    printf("\nNumber of even squares: %d",count_a);
    printf("\nOdd numbers in even positions:");

    for (int i = 1; i < n; i += 2)
        if (!check(arr[i],2)){
            printf("\n%d in %d position",arr[i],i + 1);
            count_b++;
        }

    printf("\nNumber of odd numbers in even positions: %d",count_b);
}
