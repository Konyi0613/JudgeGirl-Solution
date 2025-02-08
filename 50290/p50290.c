#include <stdio.h>

int main()
{
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    int t = (A+B+C)/2;
    printf("%d\n%d\n%d", t-A,t-B,t-C);
}