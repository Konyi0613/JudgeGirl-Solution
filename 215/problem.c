#include <stdio.h>

int main()
{
    int s,f,t,x,y,z;
    scanf("%d%d%d",&s,&f,&t);
    z=s-t;
    y=(f-8*z-2*t)/2;
    x=s-y-z;
    if(f%2 != 0 || x < 0 || y < 0 || z < 0)
    printf("0");
    else
    printf("%d\n%d\n%d",x,y,z);
}