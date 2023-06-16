#include <stdio.h>
#include <conio.h>

int fact(int num){
    int res = 1;

    if (num > 1){
        for (int i = 2; i < num; i++)
            res *= i;
        return res;
    }
    else
        return 0;
}

int main() {
    int n,m;
    float res;
    int num, denom;

    printf("Enter N\n");
    scanf("%d",&n);

    printf("Enter M\n");
    scanf("%d",&m);

    num = fact(n) + fact(m);
    denom = fact(n + m);
    res = (float)num/denom;

    printf("(n! + m!) / (n + m)! = %g",res);
    getch();
}
