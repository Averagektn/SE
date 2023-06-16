#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() {
    int n,tmp = 0;

    do {
        printf("Enter number\n");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Numbers:");

    for (int q = 2; pow(q,2) <= n; q++) {
        if ((n % (int) pow(q, 2) == 0) && (n % (int) pow(q, 3) != 0)) {
            printf(" %d", q);
            tmp++;
        }
    }

    if (!tmp)
        printf(" No numbers");
    getch();
}
