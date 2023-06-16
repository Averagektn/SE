#include <stdio.h>

int main() {
    const int MAX = 3, MIN = 0;
    float arr[MAX];

    printf("Enter three numbers \n");

    for (int i = MIN; i < MAX; i++){
        scanf("%f",&arr[i]);

        if (arr[i] < 0)
            arr[i] *= arr[i];
    }

    printf("Result: ");

    for (int i = MIN; i < MAX; i++)
        printf("%g ",arr[i]);
}
