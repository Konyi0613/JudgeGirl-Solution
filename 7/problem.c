#include <stdio.h>
#include <stdbool.h>

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d", !(x%15==0 && x%7 != 0));
}