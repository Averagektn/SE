#include <stdio.h>
#include <math.h>

const int MIN = 1, MAX = 13;

int factorial(int num){
    long long res = MIN;

    if (num < 1) {
        printf("Factorial is impossible");
        return 0;
    }
    else {
        for (int i = MIN; i <= num; i++)
            res *= i;
        return res;
    }
}

void main() {

    double x, res = 0;
    double tmp;

    printf("Enter x \n");
    scanf("%lf", &x);

    tmp = x;

    for (int i = MIN; i <= MAX; i += 2) {
        res += tmp / factorial(i);
        tmp *= -1 * pow(x,2);
    }

    printf("Result = %g",res);
}