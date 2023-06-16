#include <stdio.h>

void main() {
    const float BORDER = 2;
    float x,f;

    printf("Enter X \n");
    scanf("%f",&x);

    if (x <= BORDER)
        f = x*x + 4*x + 5;
    else
        f = 1 / (x*x + 4*x + 5);

    printf ("f(x) = %g",f);


}
