#include <stdio.h>
#include <math.h>

void main() {
    const int MIN = 1, MAX = 100;
    double res;

    for (int i = MIN; i <= MAX; i++)
        res += 1/pow(i,2);

    printf("Result = %g",res);
}
