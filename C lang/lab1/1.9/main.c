#include <stdio.h>

void main() {
    const float LEFT = 0, RIGHT = 1;
    float x,f;

    printf("Enter X \n");
    scanf("%f",&x);

    if (x <= LEFT)
        f = 0;
    else {
        if (x <= RIGHT)
            f = x;
        else
            f = x * x * x * x;
    }

    printf("f(x) = %g",f);

}
