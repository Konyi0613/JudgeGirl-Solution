#include <stdio.h>

int main()
{
    int k, L;
    scanf("%d%d", &k, &L);
    int input, left = L;
    while (scanf("%d", &input) != EOF)
    {
        if (input == 0)
            break;
        int tmp = input;
        int len = 0;
        while (tmp > 0)
        {
            tmp /= 10;
            len++;
        }
        int time = input % k;
        if (left >= len * time)
            left -= len * time;
        else
        {
            if (L >= len * time)
            {
                printf("\n");
                left = L - len * time;
            }
            else
                continue;
        }
        for (int i = 0; i < time; i++)
            printf("%d", input);
    }
}