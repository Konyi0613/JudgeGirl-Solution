#include <stdio.h>

int recursion(int i)
{
    if (i == 1)
        return 1;
    return (recursion(i - 1) + i * i);
}

int main()
{
    int n;
    scanf("%d", &n);
    int sum = recursion(n);
    printf("%d", sum);
}