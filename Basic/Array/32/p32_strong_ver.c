#include <stdio.h>
#include <stdbool.h>
bool palindrome(int a[], int head, int tail)
{
    for (int i = 0; i < (tail - head + 1) / 2; i++)
    {
        if (a[head + i] != a[tail - i])
            return false;
    }
    return true;
}

int main()
{
    int a[100];
    int counter = 0, tmp;
    while (scanf("%d", &tmp) != EOF)
    {
        a[counter] = tmp;
        counter++;
    }
    int max_length = 2, start = 0;
    for (int i = 0; i < counter - 1; i++)
    {
        for (int j = i; j < counter - 1; j++)
        {
            if (palindrome(a, i, j))
            {
                for (int k = j + 1; k < counter; k++)
                {
                    if (palindrome(a, j + 1, k) && k - i + 1 >= max_length)
                    {
                        max_length = k - i + 1;
                        start = i;
                    }
                }
            }
        }
    }
    for (int i = 0; i < max_length; i++)
    {
        printf("%d%s", a[start + i], (i == max_length - 1) ? "\n" : " ");
    }
}