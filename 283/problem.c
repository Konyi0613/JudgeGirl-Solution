#include <stdio.h>

int main()
{
    int s,f,t,x,y,z;
    scanf("%d%d%d",&s,&f,&t);
    z=s-t;
    y=(f-8*z-2*t)/2;
    x=s-y-z;
    printf("%d\n%d\n%d",x,y,z);
}