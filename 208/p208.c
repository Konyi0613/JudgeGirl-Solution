#include <stdio.h>
#include <stdbool.h>

int main()
{
    int width, height;
    scanf("%d%d", &width, &height);
    char op0, op1;
    scanf(" %c %c", &op1, &op0);
    unsigned int u;
    int time = 0;
    int size = sizeof(unsigned int) * 8;
    unsigned int cmp = 1;
    for (int i = 0; i < size - 1; i++)
        cmp <<= 1;
    while (scanf("%u", &u) != EOF)
    {
        for (int i = 0; i < size; i++)
        {
            if (time == width * height)
                break;
            if ((u & cmp) == 0)
                printf("%c", op0);
            else
                printf("%c", op1);
            time++;
            if (time % width == 0 && time != 0)
                printf("\n");
            u <<= 1;
        }
    }
}