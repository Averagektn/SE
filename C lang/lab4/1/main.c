#include <stdio.h>
#include <stdlib.h>
#define LEN 255

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

void copy(const char src[], char dest[], int pos, int len){
    int j = 0;
    for (int i = pos; i < pos + len; i++) {
        dest[j] = src[i];
        j++;
    }
    dest[j] = 0;
}

int findPos(const char src[], char s, int pos){
    while (src[pos] != s)
        pos++;
    return pos;
}

void getWords (char src[], char **dest){
    int pos = 0, n = countWords(src), l = countLen(src);
    for (int i = 0; i < n - 1; i++) {
        copy(src, dest[i], pos, findPos(src, ' ', pos) - pos);
        pos += countLen(dest[i]) + 1;
    }
    copy(src,dest[n - 1], pos, l - pos);
}

void swap(char a[], char  b[]){
    char tmp;
    for(int i = 0, j = 0; i < countLen(a) + 1 || j < countLen(b) + 1; i++, j++){
        tmp = a[i];
        a[i] = b[j];
        b[j] = tmp;
    }

}

int find(char **a, int n, int (*op)(const int, const int)){
    int ind = 0;
    for (int i = 1; i < n; i++)
        if (op(countLen(a[i]), countLen(a[ind])))
            ind = i;
    return ind;
}

int condLong(const int a, const int b){
    return a > b;
}

int condShort(const int a, const int b){
    return a < b;
}

void insert(char src[],char dest[], int pos){
    int l = countLen(src);
    for (int i = pos, j = 0; i < l + pos; i++, j++)
        dest[i] = src[j];
}

int main() {
    char str[LEN] = {0}, **words;
    int length, num, ind_l, ind_s;

    printf("Entered words\n");
    //scanf("%s",str);
    gets(str);
    length = countLen(str);
    num = countWords(str);

    words = (char **)malloc(sizeof(char) * num);
    for (int i = 0; i < num; i++)
        words[i] = (char *) malloc(sizeof(char) * length);

    getWords(str,words);

    ind_l = find(words,num,condLong);
    ind_s = find(words,num,condShort);
    swap(words[ind_l],words[ind_s]);

    int p = 0;
    for (int i = 0; i < num; i++) {
        insert(words[i], str, p);
        p += countLen(words[i]) + 1;
        str[p - 1] = ' ';
    }
    puts(str);

}