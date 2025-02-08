#include <stdio.h>
#include <stdbool.h>

int main()
{
    int input, odd = 0, even = 0, zero = 0, digit = 0;
    while (scanf("%d", &input) != EOF)
    {
        if (digit % 2 == 0)
            even += input;
        else
            odd += input;
        digit++;
        if (input == 0)
            zero++;
    }
    printf("%d\n%d\n%d\n%d\n", digit, (input % 2 == 0) ? 1 : 0, zero, (odd == even) ? 1 : 0);
}