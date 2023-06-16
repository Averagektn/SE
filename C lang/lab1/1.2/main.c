#include <stdio.h>
#include <conio.h>

void main() {
    float x,y;

    printf("Enter X \n");
    scanf("%f",&x);

    printf("Enter Y \n");
    scanf("%f",&y);

    if (x > y)
        printf("X = %g",x);
    else
        printf("X = %g , Y = %g",x,y);

    getch();
}
