#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d\n%d\n%d",(x/100),((x-x/100*100)/10),(x%10));
}