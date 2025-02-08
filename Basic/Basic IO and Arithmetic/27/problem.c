#include <stdio.h>

int main()
{
    int area,volume,a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    area = 2*(a*b+b*c+c*a)+2*(2*((c-2*e)*d+(a-2*e)*d)+2*((b-2*e)*d+(c-2*e)*d)+2*((a-2*e)*d+(b-2*e)*d));
    volume = a*b*c-2*((a-2*e)*d*(c-2*e)+(a-2*e)*d*(b-2*e)+(b-2*e)*d*(c-2*e));
    printf("%d\n%d",area,volume);
}