#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int last2, last1, now, cost = 0;
    scanf("%d%d", &last2, &last1);
    if (last2 > last1)
        cost = 2 * (last2 - last1);
    else
        cost = 3 * (last1 - last2);
    for (int i = 0; i < n - 2; i++)
    {
        scanf("%d", &now);
        if (now > last1)
        {
            if (last1 > last2)
                cost += (4 * (now - last1));
            else
                cost += (3 * (now - last1));
        }
        else
        {
            if (last1 > last2)
                cost += (3 * (last1 - now));
            else
                cost += (2 * (last1 - now));
        }
        last2 = last1;
        last1 = now;
    }
    printf("%d\n", cost);
}