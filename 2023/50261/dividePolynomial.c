#include <stdio.h>
#include "dividePolynomial.h"
#define MAX 2000 + 1
void dividePolynomial(int f[], int g[])
{
    int degree_f = f[0];
    int now_f = 0;
    int degree_g = g[0];
    int new_quo_coe = 0;
    for (int i = 0; i < degree_f - degree_g + 1; i++)
    {
        now_f++;
        new_quo_coe = f[now_f] / g[1];
        if (new_quo_coe == 0)
        {
            f[now_f] = 0;
            continue;
        }
        for (int j = 1; j < degree_g + 1; j++)
        {
            f[now_f + j] -= g[j + 1] * new_quo_coe;
        }
        f[now_f] = new_quo_coe;
    }

    if (degree_g != 0)
    {
        for (int i = 0; i < degree_g; i++)
        {
            g[1 + i] = f[degree_f - degree_g + 2 + i];
        }
        int i = 1;
        int tmp[degree_g + 1];
        while (g[i] == 0 && i <= degree_g)
        {
            i++;
        }
        for (int counter = 0; counter < degree_g - i + 1; counter++)
        {
            tmp[i + counter] = g[i + counter];
        }
        for (int counter = 0; counter < degree_g - i + 1; counter++)
        {
            g[1 + counter] = tmp[i + counter];
        }
        degree_f -= degree_g;
        f[0] = degree_f;
        degree_g = degree_g - i;
        g[0] = degree_g;
    }
    else
    {
        g[1] = 0;
        degree_g = 0;
        g[0] = 0;
    }
}

/*void readPolynomial(int p[])
{
    scanf("%d", &p[0]);
    for (int i = 1; i <= p[0] + 1; i++)
        scanf("%d", &p[i]);
}

void printPolynomial(int p[])
{
    for (int i = 0; i <= p[0]; i++)
        printf("%d ", p[i]);
    printf("%d", p[p[0] + 1]);
}

int main()
{
    int n, f[MAX], g[MAX];
    scanf("%d", &n);
    while (n--)
    {
        readPolynomial(f);
        readPolynomial(g);

        dividePolynomial(f, g);

        printPolynomial(f);
        printf("\n");
        printPolynomial(g);
        if (n)
            printf("\n");
    }
    return 0;
}
*/
