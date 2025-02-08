#include <stdio.h>

int material(int a, int b, int c, int D[], int E[], int F[])
{
    if (a == 0 && b == 0 && c == 0)
        return 1;
    if (a < 0 || b < 0 || c < 0)
        return 0;

    return material(a - D[0], b - D[1], c - D[2], D, E, F) || material(a - E[0], b - E[1], c - E[2], D, E, F) || material(a - F[0], b - F[1], c - F[2], D, E, F);
}

void scandata(int n, int D[], int E[], int F[])
{
    if (n == 0)
        return;

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int valid = material(a, b, c, D, E, F);
    if (valid)
        printf("yes\n");
    else
        printf("no\n");
    scandata(n - 1, D, E, F);
}

int main()
{
    int D[3], E[3], F[3];
    scanf("%d%d%d", &D[0], &D[1], &D[2]);
    scanf("%d%d%d", &E[0], &E[1], &E[2]);
    scanf("%d%d%d", &F[0], &F[1], &F[2]);

    int n;
    scanf("%d", &n);
    scandata(n, D, E, F);

    return 0;
}