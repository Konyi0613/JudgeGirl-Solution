#include <stdio.h>

int main()
{
    for (int i = 0; i < 2; i++)
    {
        int x[3], y[3];
        int quardrant[3];
        for (int j = 0; j < 3; j++)
        {
            scanf("%d%d", &x[j], &y[j]);
            if (x[j] > 0 && y[j] > 0)
                quardrant[j] = 1;
            else if (x[j] < 0 && y[j] > 0)
                quardrant[j] = 2;
            else if (x[j] < 0 && y[j] < 0)
                quardrant[j] = 3;
            else
                quardrant[j] = 4;
        }
        int total = 0;
        for (int j = 0; j < 3; j++)
        {
            int p1 = j, p2 = (j + 1) % 3;
            if (quardrant[p1] - quardrant[p2] == 1 || quardrant[p1] - quardrant[p2] == -1 || quardrant[p1] - quardrant[p2] == 3 || quardrant[p1] - quardrant[p2] == -3)
                total += 2;
            else if (quardrant[p1] != quardrant[p2])
            {
                total += 3;
                if (y[p1]*x[p2] == x[p1]*y[p2])
                    total -= 1;
            }
            else
                total += 1;
        }
        printf("%d\n", total);
    }
}