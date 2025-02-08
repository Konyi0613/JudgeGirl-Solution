#include <stdio.h>
int gcd(int a, int b)
{
    while (a % b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
}
int main()
{
    int n1, n2;
    scanf("%d", &n1);
    while (scanf("%d", &n2) != EOF)
    {
        int gcd12 = gcd(n1, n2);
        int lcm = n1 * n2 / gcd12;
        n1 = lcm;
    }
    printf("%d", n1);
}