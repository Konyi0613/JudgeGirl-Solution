#include <stdio.h>
typedef struct table_item
{
    int write_tape;
    int move_head; // L = -1, N = 0, R = 1
    int next_state;
} Item;
void fill_item(Item table[], int index, int w_t, int m_h, int n_s)
{
    table[index].write_tape = w_t;
    table[index].move_head = m_h;
    table[index].next_state = n_s;
}
void Turing_Machine(int *head, int K)
{
    int state = 0;
    int value = *(head);
    Item table[12]; // current state/tape_value;
    fill_item(table, 0, 0, 1, 2);
    fill_item(table, 1, 1, 1, 1);
    fill_item(table, 2, 2, 1, 2);
    fill_item(table, 3, 3, 1, 1);
    fill_item(table, 4, 1, -1, 2);
    fill_item(table, 5, 2, 1, 0);
    fill_item(table, 6, 3, -1, 2);
    fill_item(table, 7, 0, 1, 0);
    fill_item(table, 8, 2, 0, 1);
    fill_item(table, 9, 3, -1, 0);
    fill_item(table, 10, 0, 1, 1);
    fill_item(table, 11, 1, 0, 0);
    while (K--)
    {
        int tmp1 = state;
        int tmp2 = value;
        *head = table[state * 4 + value].write_tape;
        state = table[tmp1 * 4 + tmp2].next_state;
        head += table[tmp1 * 4 + tmp2].move_head;
        value = *head;
    }
}
