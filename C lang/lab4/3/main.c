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

int condShort(const int a, const int b){
    return a < b;
}

void insert(char src[],char dest[], int pos){
    int l = countLen(src);
    for (int i = pos, j = 0; i < l + pos; i++, j++)
        dest[i] = src[j];
}

void qs(char **s_arr, int first, int last,int (*op)(int, int))
{
    if (first < last)
    {
        int left = first, right = last;
        char *middle = s_arr[(left + right) / 2];
        do
        {
            while (op(countLen(middle), countLen(s_arr[left]))) left++;
            while (op(countLen(s_arr[right]), countLen(middle) )) right--;

            if (left <= right)
            {
                char *tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }

        } while (left <= right);

        qs(s_arr, first, right, op);
        qs(s_arr, left, last, op);
    }
}

int main() {
    char str[LEN] = {0}, **words = NULL;
    int length, num;

    printf("Entered words:\n");
    gets(str);

    length = countLen(str);
    num = countWords(str);

    words = (char **)malloc(sizeof(char) * num);
    for (int i = 0; i < num; i++)
        words[i] = (char *) malloc(sizeof(char) * length);

    getWords(str,words);

    qs(words,0,num-1,condShort);

    int p = 0;
    for (int i = 0; i < num; i++) {
        insert(words[i], str, p);
        p += countLen(words[i]) + 1;
        str[p - 1] = ' ';
    }
    str[countLen(str)] = 0;
    puts(str);

}