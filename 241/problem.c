#include <stdio.h>
#include <stdbool.h>
int cross_product(int x1,int y1,int x2,int y2)
{
    return (x1*y2-x2*y1);
}
int main()
{
    int a,b,c,d,e,f,g,h;
    scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
    bool within = (cross_product(a,b,c,d)>0 && cross_product(c,d,e,f)>0 && cross_product(e,f,g,h)>0 && cross_product(g,h,a,b)>0);
    printf("%d",within);
}