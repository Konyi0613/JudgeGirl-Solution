#include <stdio.h>
#include <stdbool.h>

void print(int set_size, int set[])
{
    printf("%d", set[0]);
    for (int i = 1; i < set_size; i++)
        printf(" %d", set[i]);
    printf("\n");
}

void merge_sort(int set_size, int set[])
{
    if (set_size == 1)
    {
        printf("%d\n", set[0]);
        return;
    }
    print(set_size, set);
    merge_sort(set_size / 2, set);
    merge_sort(set_size - (set_size / 2), &(set[set_size / 2]));
    int former_head = 0, latter_head = set_size / 2;
    bool former_end = true;
    int tmp[set_size];
    int tmp_counter = 0;
    while (former_head < set_size / 2 && latter_head < set_size)
    {
        if (set[former_head] < set[latter_head])
        {
            tmp[tmp_counter] = set[former_head];
            former_head++;
        }
        else
        {
            tmp[tmp_counter] = set[latter_head];
            latter_head++;
        }
        tmp_counter++;
        if (latter_head == set_size)
            former_end = false;
    }
    if (former_end)
        for (; latter_head < set_size; tmp_counter++, latter_head++)
            tmp[tmp_counter] = set[latter_head];
    else
        for (; former_head < set_size / 2; tmp_counter++, former_head++)
            tmp[tmp_counter] = set[former_head];
    for (int i = 0; i < set_size; i++)
        set[i] = tmp[i];
    print(set_size, set);
    return;
}

int main()
{
    int set_size = 0;
    int set[100000];
    while (scanf("%d", &set[set_size]) != EOF)
        set_size++;
    merge_sort(set_size, set);
}