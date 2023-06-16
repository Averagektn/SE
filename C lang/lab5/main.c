#include <stdio.h>
#include <string.h>
#define LEN 255

int main() {
    char str[LEN] = {0};
    printf("Entered words\n");
    gets(str);
    printf("\n");

    int i = 0, j = (int)strlen(str) - 1;

    while (i <= j) {
        while (str[i] != str[i + 1] && i <= j) {
            printf("%c", str[i]);
            i++;
        }
        while (str[i] == str[i + 1])
            i++;
        i++;
        if (i <= j)
            printf("_");
        while (str[j] != str[j - 1] && i <= j) {
            printf("%c", str[j]);
            j--;
        }
        if (i <= j)
            printf("_");

        while (str[j] == str[j - 1])
            j--;
        j--;
    }

}
