#include <stdio.h>

void main() {
    const int LEFT = -2, RIGHT = 2;
    double x;

    printf("Enter X \n");
    scanf("%lf",&x);

    if (x >= LEFT && x < RIGHT)
        x *= x;
    else
        x = 4;

    printf("Result = %g",x);
}
