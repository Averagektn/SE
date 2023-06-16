#include <stdio.h>

void main() {
    double a,n,res_1,res_2,tmp;

    printf("Enter a \n");
    scanf("%lf",&a);

    printf("Enter n \n");
    scanf("%lf",&n);

    tmp = a;

    for (int i = 1; i <= n + 1; i++) {
        res_1 += 1/tmp;
        tmp *= a + i;
    }

    tmp = a;

    for (int i = 1; i <= n + 1; i++) {
        res_2 += 1 / tmp;
        tmp *= tmp;
    }

    printf("1/a + 1/(a * (a + 1)) +...+1/(a * (a + 1)...(a + n)) = %g \n",res_1);
    printf("1/a + 1/a^2 + 1/a^4...+1/a^2*n = %g",res_2);

}
