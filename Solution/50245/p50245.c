#include <stdio.h>
#include <stdbool.h>
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

typedef struct square
{
    int color[4];
} Square;

void print(int n, int solution[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", solution[i * n]);
        for (int j = 1; j < n; j++)
            printf(" %d", solution[i * n + j]);
        printf("\n");
    }
}

bool can_put(int n, Square square[], int solution[], int layer, int target)
{
    int row = layer / n;
    int col = layer % n;
    if (row > 0 && square[solution[layer - n]].color[DOWN] != square[target].color[UP])
        return false;
    if (col > 0 && square[solution[layer - 1]].color[RIGHT] != square[target].color[LEFT])
        return false;
    return true;
}

bool find_solution(int n, Square square[], int layer, bool *end, int solution[], bool used[])
{
    if (layer == n * n)
    {
        print(n, solution);
        *end = true;
        return true;
    }
    for (int i = 0; i < n * n; i++)
    {
        if (*end == true)
            break;
        if (!used[i] && can_put(n, square, solution, layer, i))
        {
            solution[layer] = i;
            used[i] = true;
            find_solution(n, square, layer + 1, end, solution, used);
            used[i] = false;
        }
    }
    if (*end == true)
        return true;
    else
        return false;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        Square square[n * n];
        bool used[n * n];
        for (int i = 0; i < n * n; i++)
        {
            scanf("%d%d%d%d", &square[i].color[0], &square[i].color[1], &square[i].color[2], &square[i].color[3]);
            used[i] = false;
        }
        bool end = false;
        int solution[n * n];
        if (!find_solution(n, square, 0, &end, solution, used))
            printf("no solution\n");
    }
}