#include <stdio.h>
#include <math.h>

void main() {
    const int MIN = 1, MAX = 50;
    double res;

    for (int i = MIN; i <= MAX; i++)
        res += 1/pow(i,3);

    printf("Result = %g",res);
}
