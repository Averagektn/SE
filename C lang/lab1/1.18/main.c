#include <stdio.h>
#include <math.h>

void main() {
    const int MIN = 1;
    double res_1 = 0, res_2 = 0;
    int n;

    printf("Enter n \n");
    scanf("%d",&n);

    for (int i = MIN; i <= n; i++)
        res_1 += (float)1/i;

    printf("Result 1 = %g \n",res_1);

    for (int i = MIN; i <= n; i++)
        res_2 += 1/pow(2 * i + 1,2);

    printf("Result 2 = %g \n",res_2);
}
