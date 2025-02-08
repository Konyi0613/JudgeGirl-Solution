#include <stdio.h>

int main()
{
    int input;
    scanf("%d", &input);
    int counter = 1;
    int sign = (input > 0) ? 1 : -1;
    while (scanf("%d", &input) != EOF)
    {
        if (sign * input > 0)
            counter++;
        else
        {
            if (sign == 1)
                printf("%d ", counter);
            else
                printf("-%d ", counter);
            sign *= (-1);
            counter = 1;
        }
    }
    if (sign == 1)
        printf("%d ", counter);
    else
        printf("-%d ", counter);
}