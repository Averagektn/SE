#include <stdio.h>
#include <conio.h>

void main() {
    float x,y,z;

    printf("Enter X \n");
    scanf("%f",&x);

    printf("Enter Y \n");
    scanf("%f",&y);

    if (x > y)
        z = x -y;
    else
        z = y -x + 1;

    printf("Z = %g",z);

    getch();
}
