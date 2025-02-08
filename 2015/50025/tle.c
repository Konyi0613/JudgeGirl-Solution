#include <stdio.h>
#include <stdbool.h>

bool find_sol(int n, int m, int *people, int *chosen, int chosen_num, int index)
{
    if (chosen_num == m)
    {
        printf("%d", chosen[0]);
        for (int i = 1; i < m; i++)
            printf(" %d", chosen[i]);
        printf("\n");
        return true;
    }
    if (chosen_num + (n - index) < m)
        return false;
    bool valid = true;
    for (int i = 0; i < chosen_num; i++)
        if (people[chosen[i] * n + index] == 1)
        {
            valid = false;
            break;
        }
    if (valid)
    {
        chosen[chosen_num] = index;
        if (find_sol(n, m, people, chosen, chosen_num + 1, index + 1))
            return true;
    }
    if (find_sol(n, m, people, chosen, chosen_num, index + 1))
        return true;
    return false;
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int people[n * n], chosen[m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &people[i * n + j]);
        if (!find_sol(n, m, people, chosen, 0, 0))
            printf("no solution\n");
    }
}