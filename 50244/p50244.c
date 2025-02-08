#include <stdio.h>
#include <stdbool.h>

// #define DEBUG
// #define DEBUG2
typedef struct solution
{
    int value;
    int size;
} Solution;

void find_max_component(int N, int cubic[], Solution *best, int now_value, int *now_size, int layer, int id, bool find_head, int head_layer, int head_id)
{
    if (layer == N)
        return;
    int next_id, next_layer;
    if (id == (layer + 1) * (layer + 1) - 1)
    {
        next_id = 0;
        next_layer = layer + 1;
    }
    else
    {
        next_id = id + 1;
        next_layer = layer;
    }
    if (find_head == true)
    {
        if (cubic[layer * N * N + id] == -1)
        {
            find_max_component(N, cubic, best, now_value, now_size, next_layer, next_id, true, head_layer, head_id);
            return;
        }
        else
        {
            now_value = cubic[layer * N * N + id];
            cubic[layer * N * N + id] = -1;
            *now_size = 1;
            find_head = false;
            head_layer = layer;
            head_id = id;
        }
    }
    int side_length = layer + 1;
    int row = id / side_length;
    int col = id % side_length;
#ifdef DEBUG
    printf("layer: %d, id: %d , now_value: %d, now_size: %d\n", layer, id, now_value, *now_size);
#endif
    if (row > 0)
    {
        if (cubic[layer * N * N + id - side_length] == now_value)
        {
            cubic[layer * N * N + id - side_length] = -1;
            (*now_size)++;
            find_max_component(N, cubic, best, now_value, now_size, layer, id - side_length, false, head_layer, head_id);
        }
    }
    if (row < side_length - 1)
    {
        if (cubic[layer * N * N + id + side_length] == now_value)
        {
            cubic[layer * N * N + id + side_length] = -1;
            (*now_size)++;
            find_max_component(N, cubic, best, now_value, now_size, layer, id + side_length, false, head_layer, head_id);
        }
    }
    if (col > 0)
    {
        if (cubic[layer * N * N + id - 1] == now_value)
        {
            cubic[layer * N * N + id - 1] = -1;
            (*now_size)++;
            find_max_component(N, cubic, best, now_value, now_size, layer, id - 1, false, head_layer, head_id);
        }
    }
    if (col < side_length - 1)
    {
        if (cubic[layer * N * N + id + 1] == now_value)
        {
            cubic[layer * N * N + id + 1] = -1;
            (*now_size)++;
            find_max_component(N, cubic, best, now_value, now_size, layer, id + 1, false, head_layer, head_id);
        }
    }
    if (layer > 0)
    {
        if (cubic[(layer - 1) * N * N + row * (side_length - 1) + col] == now_value)
        {
            cubic[(layer - 1) * N * N + row * (side_length - 1) + col] = -1;
            (*now_size)++;
            find_max_component(N, cubic, best, now_value, now_size, layer - 1, row * (side_length - 1) + col, false, head_layer, head_id);
        }
    }
    if (layer < N - 1)
    {
        if (cubic[(layer + 1) * N * N + row * (side_length + 1) + col] == now_value)
        {
            cubic[(layer + 1) * N * N + row * (side_length + 1) + col] = -1;
            (*now_size)++;
            find_max_component(N, cubic, best, now_value, now_size, layer + 1, row * (side_length + 1) + col, false, head_layer, head_id);
        }
    }
    if (layer == head_layer && id == head_id)
    {
        if (*now_size > best->size || (*now_size == best->size && now_value > best->value))
        {
            best->size = *now_size;
            best->value = now_value;
#ifdef DEBUG2
            printf("now_size: %d, now_value: %d\n", *now_size, now_value);
            for (int i = 0; i < N; i++)
            {
                for (int r = 0; r < i + 1; r++)
                {
                    for (int c = 0; c < i + 1; c++)
                        printf("%d ", cubic[i * N * N + r * (i + 1) + c]);
                    printf("\n");
                }
            }
#endif
        }
        find_max_component(N, cubic, best, now_value, now_size, next_layer, next_id, true, head_layer, head_id);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int cubic[N * N * N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < (i + 1) * (i + 1); j++)
            scanf("%d", &cubic[i * N * N + j]);
    Solution best = {-1, 0};
    int now_size = 0;
    find_max_component(N, cubic, &(best), 0, &(now_size), 0, 0, true, 0, 0);
#ifdef DEBUG
    for (int i = 0; i < N; i++)
    {
        for (int r = 0; r < i + 1; r++)
        {
            for (int c = 0; c < i + 1; c++)
                printf("%d ", cubic[i * N * N + r * (i + 1) + c]);
            printf("\n");
        }
    }
#endif
    printf("%d %d\n", best.value, best.size);
}