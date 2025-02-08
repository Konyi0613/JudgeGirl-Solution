#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int sum = 0, outside = 0;
    for (int i = a; i <= b; i++)
        for (int j = 0; j < i; j++)
        {
            sum++;
            if (i == a || i == b || j == 0 || j == i - 1)
                outside++;
        }
    printf("%d\n%d\n", sum, outside);
}