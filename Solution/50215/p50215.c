#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define all_good 0x00003FFFFFF
int minimum_cost(int alphabet, int set_size, char set[set_size][51], int index, int now_cost, int has_alphabet)
{
    if (alphabet == all_good)
        return now_cost;
    if (index == set_size)
    {
        if (has_alphabet != alphabet)
            return INT32_MAX;
        return now_cost;
    }
    int new_cost = 0;
    int new_alphabet = alphabet;
    int len = strlen(&(set[index][0]));
    for (int i = 0; i < len; i++)
    {
        new_cost += (set[index][i] - 'a' + 1);
        new_alphabet |= (1 << (set[index][i] - 'a'));
        has_alphabet |= (1 << (set[index][i] - 'a'));
    }
    int choose = minimum_cost(new_alphabet, set_size, set, index + 1, now_cost + new_cost, has_alphabet);
    int not_choose = minimum_cost(alphabet, set_size, set, index + 1, now_cost, has_alphabet);
    return (choose < not_choose) ? choose : not_choose;
}
int main()
{
    int set_size;
    while (scanf("%d", &set_size) != EOF)
    {
        char set[set_size][51];
        for (int i = 0; i < set_size; i++)
            scanf("%s", set[i]);
        printf("%d\n", minimum_cost(0, set_size, set, 0, 0, 0));
    }
}