#include <stdio.h>

int balance(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = 0;
        for (int j = 0; j < i; j++)
            left += a[j] * (i - j);
        for (int j = i + 1; j < n; j++)
            right += a[j] * (j - i);
        if (left == right)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int balance_point = -1;
    for (int i = 0; i < n / 2 + 1; i++)
    {
        balance_point = balance(a, n);
        if (balance_point != -1)
            break;
        else
        {
            int tmp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i == balance_point)
            printf("v");
        else
            printf("%d", a[i]);
        if (i != n - 1)
            printf(" ");
    }
}