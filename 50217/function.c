#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "function.h"

#define INSERT 0
#define DELETE_HEAD 1
#define DELETE_TAIL 2

void insert(LinkedList *list, int data)
{
    if (list->head == NULL)
    {
        list->head = (ListNode *)malloc(sizeof(ListNode));
        list->head->data = data;
        list->head->prev = NULL;
        list->head->next = NULL;
        return;
    }
    else if (list->tail == NULL)
    {
        list->tail = (ListNode *)malloc(sizeof(ListNode));
        list->tail->data = data;
        list->tail->prev = list->head;
        list->head->next = list->tail;
        list->tail->next = NULL;
        if (list->head->data > list->tail->data)
        {
            int tmp = list->tail->data;
            list->tail->data = list->head->data;
            list->head->data = tmp;
        }
        return;
    }
    else
    {
        ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
        new_node->data = data;
        ListNode *now_node = list->head;
        for (; now_node != NULL; now_node = now_node->next)
            if (now_node->data >= data)
                break;
        if (now_node == NULL)
        {
            now_node = list->tail;
            now_node->next = new_node;
            new_node->prev = now_node;
            list->tail = new_node;
            new_node->next = NULL;
        }
        else if (now_node->prev == NULL)
        {
            now_node->prev = new_node;
            new_node->next = now_node;
            list->head = new_node;
            new_node->prev = NULL;
        }
        else
        {
            new_node->next = now_node;
            new_node->prev = now_node->prev;
            now_node->prev->next = new_node;
            now_node->prev = new_node;
        }
        return;
    }
}
void delete_head(LinkedList *list)
{
    ListNode *old_head = list->head;
    if (old_head == NULL)
        return;
    ListNode *new_head = list->head->next;
    free(old_head);
    if (new_head == NULL)
    {
        list->head = NULL;
        list->tail = NULL;
        return;
    }
    new_head->prev = NULL;
    list->head = new_head;
}
void delete_tail(LinkedList *list)
{
    ListNode *old_tail = list->tail;
    if (old_tail == NULL)
    {
        delete_head(list);
        return;
    }
    ListNode *new_tail = list->tail->prev;
    free(old_tail);
    if (new_tail == NULL)
    {
        list->tail = NULL;
        list->head = NULL;
        return;
    }
    new_tail->next = NULL;
    list->tail = new_tail;
}
/*
void head_traverse(LinkedList *list)
{
    ListNode *node = list->head;
    for (; node != NULL; node = node->next)
        printf("%d%c", node->data, (node->next == NULL) ? '\n' : ' ');
}

void tail_traverse(LinkedList *list)
{
    ListNode *node = list->tail;
    for (; node != NULL; node = node->prev)
        printf("%d%c", node->data, (node->prev == NULL) ? '\n' : ' ');
}

int main()
{

    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    int func, val;

    while (scanf("%d%d", &func, &val) != EOF)
    {
        switch (func)
        {
        case INSERT:
            insert(list, val);
            break;
        case DELETE_HEAD:
            delete_head(list);
            break;
        case DELETE_TAIL:
            delete_tail(list);
            break;
        }
    }

    head_traverse(list);
    tail_traverse(list);

    return 0;
}
*/
