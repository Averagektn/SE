#include <stdio.h>

const int MIN = 1;

long long factorial(int n){
    long long res = 1;

    if (n <= MIN){
        printf("Incorrect data for factorial \n");
        return 0;
    }
    else{
        for (int i = MIN; i <= n; i++)
            res *= i;
        return res;
    }

}

void main() {
    double k,n,num,denom,res;

    printf("Enter K \n");
    scanf("%lf",&k);

    printf("Enter N \n");
    scanf("%lf",&n);

    denom = factorial(k);
    num = n;

    for (int i = MIN; i < k; i++)
        num *= n - i;

    res = num / denom;

    printf("Result = %g",res);
}
