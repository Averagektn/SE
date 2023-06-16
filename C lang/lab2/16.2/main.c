#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0

int more(int param1, int param2)
{
    return param1 > param2;
}

int less(int param1, int param2)
{
    return param1 < param2;
}

void qs(int *s_arr, int first, int last,int (*op)(int, int))
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (op(middle, s_arr[left])) left++;
            while (op(s_arr[right], middle)) right--;

            if (left <= right)
            {
                int tmp = s_arr[left];
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

int main()
{
    int n;
    printf("Enter number:\n");
    scanf("%d",&n);

    int arr[n][n], buf[n];
    srand(time(0));

    printf("Array:\n");
    for (int i = MIN; i < n; i++)
    {
        for (int j = MIN; j < n; j++)
        {
            arr[i][j] = (rand() % 89) + 10;
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

    int a_odd[n],a_even[n];

    for (int i = MIN; i < n; i++)
    {
        int odd = MIN, even = MIN, ind_odd = MIN, ind_even = MIN;

        for (int j = MIN; j < n; j++)
        {
            if (arr[i][j] % 2 == 1)
            {
                buf[j] = 1;
                a_odd[odd] = arr[i][j];
                odd++;
            }
            else
            {
                buf[j] = 0;
                a_even[even] = arr[i][j];
                even++;
            }
        }

        qs(a_even,MIN,even - 1,less);
        qs(a_odd,MIN,odd - 1,more);



        for (int j = MIN; j < n; j++)
            if (buf[j])
            {
                arr[i][j] = a_odd[ind_odd];
                ind_odd++;
            }
            else
            {
                arr[i][j] = a_even[ind_even];
                ind_even++;
            }
    }

    printf("Array:\n");
    for (int i = MIN; i < n; i++)
    {
        for (int j = MIN; j < n; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }

}
