#include <stdio.h>
#include <stdbool.h>

int main()
{
    int set[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &set[i]);
    int set_size = 10;
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
    printf("%d", set[0]);
    for (int i = 1; i < set_size; i++)
        printf(" %d", set[i]);
    printf("\n");
}