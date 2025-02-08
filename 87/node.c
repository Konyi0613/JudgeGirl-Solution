#include <stdio.h>
#include <stdlib.h>
#include "node.h"
// #define MAIN

struct node *merge(struct node *list1, struct node *list2)
{
    if (list2 == NULL)
        return list1;
    struct node *next2 = list2->next;
    struct node *ptr = list1;
    struct node *prev = NULL;
    while (ptr != NULL && ptr->value < list2->value)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL)
    {
        list2->next = list1;
        return merge(list2, next2);
    }
    else
    {
        prev->next = list2;
        list2->next = ptr;
        return merge(list1, next2);
    }
}

#ifdef MAIN
#define LEN 1000

struct node *build(int v[], int n)
{
    struct node *head, *ptr;
    int i;

    if (!n)
        return 0;

    head = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    head->value = v[0];
    for (i = 1; i < n; i++)
    {
        ptr->next = (struct node *)malloc(sizeof(struct node));
        ptr = ptr->next;
        ptr->value = v[i];
    }
    ptr->next = 0;
    return head;
}

void print(struct node *ptr)
{
    printf("%d", ptr->value);
    if (ptr->next)
    {
        putchar(' ');
        print(ptr->next);
    }
}

int main()
{
    int n1, n2;
    int v1[LEN], v2[LEN];
    int i;
    struct node *list1, *list2;

    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
        scanf("%d", &v1[i]);
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
        scanf("%d", &v2[i]);
    list1 = build(v1, n1);
    list2 = build(v2, n2);

    print(merge(list1, list2));
    putchar('\n');
    return 0;
}
#endif