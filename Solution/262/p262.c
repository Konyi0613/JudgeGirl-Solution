#include <stdio.h>
#include <stdbool.h>
int main()
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        bool first = true;
        int max = 0, now = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((num & 1) == 1)
            {
                now++;
                if (first)
                    max++;
            }
            else
            {
                first = false;
                if (now > max)
                    max = now;
                now = 0;
            }
            num >>= 1;
        }
        printf("%d\n", max);
    }
}