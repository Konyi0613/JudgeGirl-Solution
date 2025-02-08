#include <stdio.h>

int main()
{
    int A, B, C, D, E, F, G;
    scanf("%d%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F, &G);
    int edge = A + B + C + D + (A + B + C) * E + (C + D) * F + E * G + F + G;
    int path = (A + B + C) * E * G + (C + D) * F;
    printf("%d\n%d", edge, path);
}