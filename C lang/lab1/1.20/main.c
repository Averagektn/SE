#include <stdio.h>
#include <malloc.h>

int check(int num, int base){
    int res;

    if (num % base == 0)
        res = 1;
    else
        res = 0;

    return res;
}

void main() {
    int n, count_a = 0, count_b = 0;

    printf("Enter size of the array \n");
    scanf("%d",&n);
    srand(n);
    printf("Array:");
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf(" %d",arr[i]);
    }

    printf("\nOdd numbers:");

    for (int i = 0; i < n; i++)
        if (!check(arr[i], 2)){

            printf("\n%d ",arr[i]);
            count_a++;

            if (check(arr[i],3))

                if (!check(arr[i],5)){
                    count_b++;
                    printf(" Number %d is divisible by 3 but not divisible by 5",arr[i]);
                }

        }

    printf("\nAmount of odd numbers: %d \n",count_a);
    printf("Amount of numbers that are divisible by 3 but not divisible by 5: %d \n",count_b);


}
