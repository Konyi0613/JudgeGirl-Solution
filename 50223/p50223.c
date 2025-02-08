#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int w,a,b,c,d,e;
    scanf("%d%d%d%d%d%d",&w,&a,&b,&c,&d,&e);
    int x;
    if (b > 0)
        x = a + 2 * d + 1 + b + 2 * e + 1 + c;
    else if (d > e)
        x = a + d + 2 + d + c;
    else
        x = a + e + 2 + e + c;
    printf("%d", w * w + x * x); 
}