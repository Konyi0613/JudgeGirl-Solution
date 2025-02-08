#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sort_list.h"
// #define MAIN

typedef struct node Node;
void print(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%ld ", (ptr - head));
        ptr = ptr->next_node;
    }
    printf("\n");
}
struct node *sort_list(struct node *head)
{
    int size = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        size++;
        ptr = ptr->next_node;
    }
    Node *new_head = head;
    Node *front;
    Node *back;
    Node *front_prev;
    Node *back_next;
    for (int i = size - 1; i >= 1; i--)
    {
        front = new_head;
        front_prev = NULL;
        back = front->next_node;
        back_next = back->next_node;
        for (int j = 0; j < i; j++)
        {
            bool change = ((front - new_head) > (back - new_head));
            if (j == 0)
            {
                if (change)
                {
                    new_head = back;
                    back->next_node = front;
                    front->next_node = back_next;

                    front_prev = back;
                    front = front->next_node;
                    back = back->next_node;

                    Node *tmp = front;
                    front = back;
                    back = tmp;
                }
                else
                {
                    front_prev = front;
                    front = front->next_node;
                    back = back_next;
                }
                if (size > 2)
                    back_next = back_next->next_node;
            }
            else if (j == i - 1)
            {
                if (change)
                {
                    front_prev->next_node = back;
                    back->next_node = front;
                    front->next_node = back_next;
                }
            }
            else
            {
                if (change)
                {
                    back->next_node = front;
                    front->next_node = back_next;
                    front_prev->next_node = back;

                    Node *tmp = front;
                    front = back;
                    back = tmp;

                    front_prev = front;
                    front = front->next_node;
                    back = back->next_node;
                    back_next = back->next_node;
                }
                else
                {
                    front_prev = front;
                    front = front->next_node;
                    back = back->next_node;
                    back_next = back->next_node;
                }
            }
        }
    }
    return new_head;
}

#ifdef MAIN
int main()
{
    struct node ptr_list[30000];
    int n;
    scanf("%d", &n);

    // below is just to randomized addresses
    srand(time(NULL));
    for (int i = 0; i < 30000; i++)
    {
        ptr_list[i].next_node = ptr_list + rand() % 30000;
    }
    //

    int cur;
    scanf("%d", &cur);
    int head = cur;
    for (int i = 1; i < n; i++)
    {
        int next;
        scanf("%d", &next);
        ptr_list[cur].next_node = ptr_list + next;
        cur = next;
    }
    ptr_list[cur].next_node = NULL;
    struct node *cur_node = ptr_list + head;
    struct node *new_head = sort_list(cur_node);
    printf("%d", (int)(new_head - ptr_list));
    for (int i = 0; i < n - 1; i++)
    {
        new_head = new_head->next_node;
        printf(" %d", (int)(new_head - ptr_list));
    }
    printf("\n");
}
#endif