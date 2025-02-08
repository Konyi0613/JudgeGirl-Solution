#include <stdio.h>

int main()
{
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int perimeter = 2 * (a + b + c + d + e + f);
    int area = (a + c + e) * (b + d + f) - b * (c + e) - d * e;
    printf("%d\n%d", perimeter, area);
}