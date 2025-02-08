#include <stdio.h>

int *get_a()
{
    int a[3];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    return &(a[0]);
}

int main()
{
    int *a = get_a;
    printf("%d %d %d\n", a[0], a[1], a[2]);
}