#include <stdio.h>
#include <conio.h>

void main() {
    int n;

    do {
        printf("Enter number:\n");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Natural dividends: 1");

    for (int i = 2; i <= n/2; i++)
        if (n % i == 0)
            printf(" %d",i);

    if (n > 1)
        printf(" %d",n);
    getch();
}
