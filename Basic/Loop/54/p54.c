#include <stdio.h>

int main()
{
    int N, M, time = 0;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < 6; i++)
    {
        if (M % 100 == N)
            time++;
        M /= 10;
    }
    printf("%d", time);
}