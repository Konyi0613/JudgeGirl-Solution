#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *getNode(struct node *head, unsigned int i)
{
    unsigned int size = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }
    if (i > size - 1)
        return NULL;
    unsigned int time = size - i - 1;
    ptr = head;
    while (time > 0)
    {
        ptr = ptr->next;
        time--;
    }
    return ptr;
}