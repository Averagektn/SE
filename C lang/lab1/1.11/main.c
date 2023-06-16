#include <stdio.h>
#include <math.h>

void main() {
    double a,n,res_1,res_2;

    printf("Enter a \n");
    scanf("%lf",&a);

    printf("Enter n \n");
    scanf("%lf",&n);

    res_1 = pow(a,n);

    res_2 = a;
    for(int i = 1; i < n; i++)
        res_2 *= a + i;

    printf("a^n = %g \n",res_1);
    printf("a * (a + 1)...(a + n - 1) = %g",res_2);

}
