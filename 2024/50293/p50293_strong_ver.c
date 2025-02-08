#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int temp, adj, sum, max = 0, maxk, first, firsts = 0;
    scanf("%d", &adj);
    sum = adj;
    first = adj;
    int ex = 0;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp == adj)
        {
            sum += temp;
        }
        else
        {
            if (ex == 0)
            {
                firsts = sum;
            }
            if (sum > max || (sum == max && adj < maxk))
            {
                maxk = adj;
                max = sum;
            }
            adj = temp;
            sum = temp;
            ex = 1;
        }
    }

    if (first == adj)
    {
        sum += firsts;
    }
    if (sum > max || (sum == max && adj < maxk))
    {
        maxk = adj;
        max = sum;
    }
    printf("%d %d", maxk, max / maxk);
    return 0;
}