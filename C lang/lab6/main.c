#include <stdio.h>
#include <string.h>
#define LEN 20

struct person{
    char surname[LEN];
    char place[LEN];
    double mark;
};

int more(char *param1, const char *param2)
{
    for (int i = 0; i < strlen(param1); i++)
        if (param1[i] != param2[i])
            return param1[i] > param2[i];
    return param1[0] > param2[0];
}

int less(int param1, int param2)
{
    return param1 < param2;
}

void qs(struct person *s_arr, int first, int last,int (*op)(char*,const char*))
{
    if (first < last)
    {
        int left = first, right = last;
        char *middle = s_arr[(left + right) / 2].surname;
        do
        {
            while (op(middle, s_arr[left].surname))
                left++;
            while (op(s_arr[right].surname, middle))
                right--;

            if (left <= right)
            {
                struct  person tmp = s_arr[left];
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
    int size;
    double average = 0;
    printf("Enter the number of students\n");
    scanf_s("%d",&size);

    struct person people[size];
    for (int i = 0; i < size; i++){
        printf("Enter surname of the student\n");
        scanf("%s",people[i].surname);
        printf("Enter place of birth of the student\n");
        scanf_s("%s",people[i].place);
        printf("Enter average mark of the student\n");
        scanf_s("%lf",&people[i].mark);
    }

    for (int i = 0; i < size; i++){
        average += people[i].mark;
    }
    average /= size;
    qs(people,0,2,more);
    printf("\nStudents with marks above average\n");
    for (int i = 0; i < 3; i++)
        if (people[i].mark >= average) {
            printf("%s\n", people[i].surname);
            printf("%s\n",people[i].place);
            printf("%0.2lf\n",people[i].mark);
        }
    printf("\n%0.2lf",average);


}
