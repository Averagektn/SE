#include <stdio.h>
#define SIZE 255

int main() {
    FILE *f1, *f2, *f3;
    char nameF1[] = "f1.txt", nameF2[] = "f2.txt", nameF3[] = "f3.txt";
    char str[SIZE] = {0};

    f1 = fopen(nameF1, "r");
    f3 = fopen(nameF3, "w");
    printf("First file:\n");
    while (fgets(str, SIZE, f1) != NULL) {
        fputs(str, f3);
        printf_s(str);
    }
    fclose(f1);
    fclose(f3);

    f1 = fopen(nameF1, "w");
    f2 = fopen(nameF2, "r");
    printf("\n\nSecond file:\n");
    while (fgets(str, SIZE, f2) != NULL) {
        fputs(str, f1);
        printf_s(str);
    }
    fclose(f1);
    fclose(f2);

    f2 = fopen(nameF2, "w");
    f3 = fopen(nameF3, "r");
    while (fgets(str, SIZE, f3) != NULL)
        fputs(str, f2);
    fclose(f2);
    fclose(f3);
    remove(nameF3);
}
