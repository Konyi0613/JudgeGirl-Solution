#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    char val;
    struct list *next;
    struct list *prev;
} List;

List* InsertHead(List *list, char c);
List* InsertTail(List *list, char c);
List* DeleteHead(List *list);
List* DeleteTail(List *list);
List* Clean(List *list, char c);
int ReturnLength(List *list);

List* InsertHead(List *list, char c)
{
    List* new = (List *)malloc(sizeof(List));
    new->val = c;
    new->next = list;
    new->prev = NULL;
    if (list != NULL)
        list->prev = new;
    return new;
}

List* InsertTail(List *list, char c)
{
    if (list == NULL)
        return InsertHead(list, c);
    List* head = list;
    int len = ReturnLength(list);
    for (int i = 0; i < len - 1; i++)
        list = list->next;
    List* new = (List *)malloc(sizeof(List));
    new->val = c;
    new->next = NULL;
    new->prev = list;
    list->next = new;
    return head;
}

List* DeleteHead(List *list)
{
    if (list == NULL)
    {
        printf("0\n");
        return NULL;
    }
    else if (list->next == NULL)
    {
        printf("1 %c\n", list->val);
        return NULL;
    }
    printf("1 %c\n", list->val);
    List *new = list->next;
    free(list);
    new->prev = NULL;
    return new;
}

List* DeleteTail(List *list)
{
    if (list == NULL || list->next == NULL)
        return DeleteHead(list);
    List* head = list;
    int len = ReturnLength(list);
    for (int i = 0; i < len - 2; i++)
        list = list->next;
    printf("1 %c\n", list->next->val);
    free(list->next);
    list->next = NULL;
    return head;
}

List* Clean(List *list, char c)
{
    if (list == NULL)
    {
        printf("0\n");
        return NULL;
    }
    List* new = NULL;
    List* now = list;
    int len = ReturnLength(list), count = 0;
    for (int i = 0; i < len - 1; i++)
        now = now->next;
    while (now != NULL)
    {
        List *next = now->prev;
        if (now->val != c)
        {
            now->next = new;
            if (new != NULL)
                new->prev = now;
            new = now;
            new->prev = NULL;
        }
        else
        {
            count++;
            free(now);
        }
        now = next;
    }
    printf("%d", count);
    if (count > 0)
        printf(" %c", c);
    printf("\n");
    return new;
}

int ReturnLength(List *list)
{
    int len = 0;
    while (list != NULL)
    {
        list = list->next;
        len++;
    }
    return len;
}

int main()
{
    int Q;
    scanf("%d", &Q);
    List *mylist = NULL;
    for (int i = 0; i < Q; i++)
    {
        int ipd;
        char ipc;
        scanf("%d", &ipd);
        if (ipd == 1)
        {
            scanf(" %c", &ipc);
            mylist = InsertHead(mylist, ipc);
        }
        else if (ipd == 2)
        {
            scanf(" %c", &ipc);
            mylist = InsertTail(mylist, ipc);   
        }
        else if (ipd == 3)
            mylist = DeleteHead(mylist);
        else if (ipd == 4)
            mylist = DeleteTail(mylist);
        else if (ipd == 5)
        {
            scanf(" %c", &ipc);
            mylist = Clean(mylist, ipc);
        }
        else
            printf("%d\n", ReturnLength(mylist));
    }
}