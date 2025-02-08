#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a, b, x;
    while (scanf("%d%d%d", &a, &b, &x) != EOF)
    {
        while (true)
        {
            int digit1 = x % 10;
            int x_copy = x;
            x_copy /= 10;
            int digit2;
            while (x_copy != 0)
            {
                digit2 = x_copy % 10;
                if (digit2 != digit1)
                    break;
                x_copy /= 10;
            }
            if (x_copy == 0)
                break;
            while (x_copy != 0)
            {
                x_copy /= 10;
                int digit3 = x_copy % 10;
                if (digit3 != digit1 && digit3 != digit2)
                    break;
            }
            if (x_copy == 0)
                break;
            x = (a * x) % b;
        }
        printf("%d\n", x);
    }
}