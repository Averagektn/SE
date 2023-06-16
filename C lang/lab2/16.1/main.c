#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 0

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int n;
    do
    {
        printf("Enter odd number:\n");
        scanf("%d", &n);
    }while (n % 2 == 0);

    int arr[n][n];
    srand(time(0));

    printf("Array:\n");
    for (int i = MIN; i < n; i++)
    {
        for (int j = MIN; j < n; j++)
        {
            arr[i][j] = (rand() % 89) + 10;
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

    int ind_l = MIN;
    int ind_c = MIN;

    for(int i = MIN + 1; i < n; i++)
    {
        if (arr[i][i] > arr[ind_l][ind_c])
        {
            ind_l = i;
            ind_c = i;
        }
    }

    for(int i = MIN ; i < n; i++)
    {
        if (arr[i][n - i - 1] > arr[ind_l][ind_c])
        {
            ind_l = i;
            ind_c = n - i - 1;
        }
    }

    printf("Swapped element: %d\n",arr[ind_l][ind_c]);
    swap(&arr[n / 2][n / 2],&arr[ind_l][ind_c]);

    printf("Swapped array:\n");
    for (int i = MIN; i < n; i++)
    {
        for (int j = MIN; j < n; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }

}
