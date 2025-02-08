#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

    // put the condition in the for loop inside and adjust it
    int a, b, c;
    long long temp1, temp2, temp3;
    scanf("%d%d%d", &a, &b, &c);
    if (c == 0)
    {
        // x(x^2+ax+b)
        if (b == 0)
        {
            if (a >= 0)
                printf("0 0 %d", a);
            else
                printf("%d 0 0", a);
            exit(0);
        }
        temp1 = 0;
        for (int j = llabs(b); j >= (-1) * llabs(b); j--)
        {
            if (j == 0)
                continue;
            else if (b % j != 0)
                continue;
            temp2 = j;
            temp3 = b / j;
            if (temp2 + temp3 == a)
            {
                int max = (((temp1 > temp2) ? temp1 : temp2) > temp3) ? ((temp1 > temp2) ? temp1 : temp2) : temp3;
                int min = (((temp1 < temp2) ? temp1 : temp2) < temp3) ? ((temp1 < temp2) ? temp1 : temp2) : temp3;
                int mid = temp1 + temp2 + temp3 - max - min;
                printf("%d %d %d", min, mid, max);
                exit(0);
            }
        }
    }
    for (int i = abs(c); i >= (-1) * abs(c); i--)
    {
        // c = 0 is a special case
        if (i == 0)
            continue;
        else if (c % i != 0)
            continue;
        temp1 = i;
        for (int j = llabs(c / temp1); j >= (-1) * llabs(c / temp1); j--)
        {
            if (j == 0)
                continue;
            else if ((c / temp1) % j != 0)
                continue;
            temp2 = j;
            temp3 = c / temp1 / temp2;
            if ((temp1 + temp2 + temp3 == a) && (temp1 * temp2 + temp1 * temp3 + temp2 * temp3 == (long long)b))
            {
                int max = (((temp1 > temp2) ? temp1 : temp2) > temp3) ? ((temp1 > temp2) ? temp1 : temp2) : temp3;
                int min = (((temp1 < temp2) ? temp1 : temp2) < temp3) ? ((temp1 < temp2) ? temp1 : temp2) : temp3;
                int mid = temp1 + temp2 + temp3 - max - min;
                printf("%d %d %d", min, mid, max);
                exit(0);
            }
        }
    }
}