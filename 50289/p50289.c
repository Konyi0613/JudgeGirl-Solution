#include <stdio.h>

int main()
{
    int L, W, l, w;
    scanf("%d%d%d%d", &L, &W, &l, &w);
    int a = (L / l) * (W / w);
    printf("%d\n%d", a, L*W-a*l*w);
}