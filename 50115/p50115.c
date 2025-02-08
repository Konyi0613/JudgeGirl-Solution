#include <stdio.h>

int main()
{
    int a, b, h, c, d;
    //c*d*h' = a*b*(h'-h)
    //cdh'=abh'-abh
    //(cd-ab)h'=-abh
    //h'=abh/(ab-cd)
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    printf("%d\n", a*b*h/(a*b-c*d));
}