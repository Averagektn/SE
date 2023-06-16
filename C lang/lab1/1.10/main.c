#include <stdio.h>
#include <math.h>

void main() {
    double n,res;

    printf("Enter n \n");
    scanf("%lf",&n);

    res = pow(2,n);

    printf("2^n = %g",res);
}
