#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 0


void Fill(int n, int a[n][n]){
    printf("Array:\n");
    for (int i = MIN; i < n; i++)
    {
        for (int j = MIN; j < n; j++)
        {
            a[i][j] = (rand() % 89) + 10;
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, ind = 1, guess;

    printf("Enter number:\n");
    scanf("%d",&n);

    int arr_1[n][n], arr_2[n][n];

    srand(time(0));
    Fill(n,arr_1);

    guess = arr_1[MIN + 1][MIN];
    for (int j = MIN; j <= n / 2; j++){
        for (int i = MIN + ind; i < n - ind; i++){
            if (guess > arr_1[i][j]){
                guess = arr_1[i][j];
            }
        }
        ind++;
    }

    ind = 1;

    for (int j = n - 1; j > n / 2 + 1; j--){
        for (int i = MIN + ind; i < n - ind; i++){
            if (guess > arr_1[i][j]){
                guess = arr_1[i][j];
            }
        }
        ind++;
    }

    printf("Number: %d\n",guess);

    Fill(n,arr_2);

    guess = arr_2[n - 1][MIN + 1];
    ind = 1;
    for (int i = n - 1; i > n / 2; i--){
        for (int j = MIN + ind; j < n - ind; j++){
            if (guess > arr_2[i][j]){
                guess = arr_2[i][j];
            }
        }
        ind++;
    }
    printf("Number: %d\n",guess);
}
