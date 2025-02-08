#include <stdio.h>

int main()
{
    int M, N, X1, Y1, E1, N1, F1, X2, Y2, E2, N2, F2;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &M, &N, &X1, &Y1, &E1, &N1, &F1, &X2, &Y2, &E2, &N2, &F2);
    int step1 = 0, step2 = 0;
    int time = 0;
    while (time >= 0)
    {
        time++;
        if (F1 == 0 && F2 == 0)
        {
            printf("robots will not explode\n");
            return 0;
        }
        if (F1 > 0)
        {
            if (step1 == N1 + E1)
                step1 = 0;
            if (step1 < N1)
            {
                step1++;
                Y1++;
            }
            else if (step1 - N1 < E1)
            {
                step1++;
                X1++;
            }
            if (X1 == M)
                X1 = 0;
            if (Y1 == N)
                Y1 = 0;
            F1--;
        }
        if (F2 > 0)
        {
            if (step2 == N2 + E2)
                step2 = 0;
            if (step2 < E2)
            {
                step2++;
                X2++;
            }
            else if (step2 - E2 < N2)
            {
                step2++;
                Y2++;
            }
            if (X2 == M)
                X2 = 0;
            if (Y2 == N)
                Y2 = 0;
            F2--;
        }
        if (X1 == X2 && Y1 == Y2)
        {
            printf("robots explode at time %d\n", time);
            return 0;
        }
    }
}