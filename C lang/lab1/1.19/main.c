#include <stdio.h>
#include <math.h>

void main() {
    const int DEGREE = 5, MIN = 1;

    double res_1 = 0, res_2 = 0;
    int n;

    printf("Enter N \n");
    scanf("%d",&n);

    for (int i = MIN; i <= n; i++)
        res_1 += 1/pow(i,DEGREE);

    printf("Result 1 = %g \n",res_1);

    for (int i = MIN; i <= n; i++)
        res_2 += pow(-1,i) / ((2 * i + 1) * i);

    printf("Result 2 = %g",res_2);
}
