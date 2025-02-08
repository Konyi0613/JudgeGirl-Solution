#include <stdio.h>

typedef struct object
{
    int value;
    int weight;
} Object;

int best(int capacity, Object object[], int n, int index, int *now_best, int now_num)
{
    if (index >= n)
    {
        if (now_num > *now_best)
        {
            *now_best = now_num;
            return now_num;
        }
        else
            return *now_best;
    }
    if (object[index].weight > capacity)
        return (best(capacity, object, n, index + 1, now_best, now_num));
    int placed = best(capacity - object[index].weight, object, n, index + 1, now_best, now_num + object[index].value);
    int not_placed = best(capacity, object, n, index + 1, now_best, now_num);
    return (placed > not_placed) ? placed : not_placed;
}

int main()
{
    int n, W;
    scanf("%d%d", &n, &W);
    Object object[n];
    for (int i = 0; i < n; i++)
        scanf("%d%d", &(object[i].weight), &(object[i].value));
    int now_best = 0;
    printf("%d", best(W, object, n, 0, &(now_best), 0));
}