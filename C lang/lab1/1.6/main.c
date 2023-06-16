#include <stdio.h>
#include <math.h>

void main() {
    double a,b,c,disc,root;

    do {
    printf("Enter A (A <> 0) \n");
    scanf("%lf",&a);
    } while(a == 0);

    printf("Enter B \n");
    scanf("%lf",&b);

    printf("Enter C \n");
    scanf("%lf",&c);

    disc = b * b - 4 * a * c;

    if (disc < 0)
        printf("No real roots");
    else{
        root = (-b + sqrt(disc)) / (2 * a);
        printf("First root = %g \n",root);

        root = (-b - sqrt(disc)) / (2 * a);
        printf("Second root = %g",root);
    }

}
