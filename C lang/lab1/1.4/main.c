#include <stdio.h>
#include <conio.h>


void main() {
    const int MAX = 3, RIGHT = 3, LEFT = 1;
    float arr[MAX];
    int i;

    printf("Enter three numbers \n");

    for(i = 0; i < MAX; i++){
        scanf("%f", &arr[i]);
    }

    for(i = 0; i < MAX; i++){
        if (arr[i] >= LEFT && arr[i] <= RIGHT)
            printf("%g ",arr[i]);
    }
    getch();
}
