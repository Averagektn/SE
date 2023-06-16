#include <stdio.h>
#define LEN 255

int findPos(const char src[], char s, int pos){
    while (src[pos] != s)
        pos++;
    return pos;
}

int countLen(const char a[]){
    int i = 0;
    while(a[i] != 0)
        i++;
    return i;
}

int countWords(const char a[]){
    int i = 0, k = 1;
    while(a[i] != 0){
        if (a[i] == ' ')
            k++;
        i++;
    }
    return k;
}

int main() {
    char str[LEN] = {0};
    int length, num;

    printf("Enter words\n");
    gets(str);

    length = countLen(str);
    num = countWords(str);
    str[length] = ' ';
    int p = 0, elem = 0;
    for (int i = 0; i < num; i++) {
        str[elem] -= 'a' - 'A';
        elem = findPos(str, ' ', p) + 1;
        p = elem;
    }

    puts(str);
}
