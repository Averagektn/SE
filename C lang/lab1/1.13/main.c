#include <stdio.h>
#include <math.h>

void main() {
    const int MAX = 10, MIN = 1;
    double value = 0.1,res = MIN;

    for (int i = MIN; i <= MAX; i++)
        res *= (1 + sin(value * i));

    printf("Result = %g",res);

}
