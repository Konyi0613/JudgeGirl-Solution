#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",2*(a*b+b*c+c*a));
    printf("%d",a*b*c);
}