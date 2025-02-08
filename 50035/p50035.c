#include <stdio.h>
#include <stdlib.h>
// #define DEBUG


typedef struct list
{
    int x;
    int y;
    struct list *next;
} List;

List* GetNode(int x, int y, List* next)
{
    List* node = (List *)malloc(sizeof(List));
    node->x = x;
    node->y = y;
    node->next = next;
    return node;
}

void build_list(int n, int m, List* prev, List* sol, int x, int y)
{
#ifdef DEBUG
printf("%d %d\n", x, y);
#endif
    int next_x, next_y;
    if (x == 0 && y < m - 1)
    {
        next_x = 0;
        next_y = y + 1;
    }
    else if ((m - 1 - y) % 2 == 0 && x < n - 1)
    {
        next_x = x + 1;
        next_y = y;
    }
    else if ((m - 1 - y) % 2 == 1 && x > 1)
    {
        next_x = x - 1;
        next_y = y;
    }
    else if (y > 0)
    {
        next_x = x;
        next_y = y - 1;
    }
    else
    { 
        prev->next = (List *)malloc(sizeof(List));
        List* ptr = prev->next;
        ptr->x = x;
        ptr->y = y;
        ptr->next = sol;   
        return;
    }
    prev->next = (List *)malloc(sizeof(List));
    List* ptr = prev->next;
    ptr->x = x;
    ptr->y = y;
    build_list(n, m, ptr, sol, next_x, next_y);
    return;
}

List* find(List* sol, int x, int y)
{
    while (!(sol->x == x && sol->y == y))
        sol = sol->next;
    return sol;
}

void print(List* head)
{
    int sx = head->x, sy = head->y;
    do
    {
        printf("%d %d\n", head->x, head->y);
        head = head->next;
    } while (!(sx == head->x && sy == head->y));
    printf("%d %d\n", sx, sy);
    return;
}

int main()
{
    int n, m, x, y;
    while (scanf("%d%d%d%d", &n, &m, &x, &y) != EOF)
    {
        List* sol = GetNode(0, 0, NULL);
        build_list(n, m, sol, sol, 0, 1);
        List* head = find(sol, x, y);
        print(head);
    }
}