#include <stdio.h>
#include <math.h>
#include <conio.h>

void main(){
    const int MIN = 1, MAX = 30;
    double sum = 0;

    for (int i = MIN; i <= MAX; i++)
        if (i % 2 == 0)
            sum += pow(i/2 - pow(i,3), 2);
        else
            sum += pow(i - pow(i,2), 2);

    printf("Result: %f",sum);
    getch();
}
