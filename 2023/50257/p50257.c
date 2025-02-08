#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    while (n != 1)
    {
        n = (n % 2 == 0) ? (n / 2) : (3 * n + 1);
        printf("%d\n", n);
    }
}