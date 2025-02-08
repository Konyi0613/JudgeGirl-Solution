#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #define MAIN

struct Node
{
    int val;
    struct Node *nxt;
};

int split_cycle(struct Node *head, int A, int K)
{
    int len = 0;
    struct Node* ptr = head;
    struct Node* prev = NULL;
    do
    {
        len++;
        prev = ptr;
        ptr = ptr->nxt;
    } while (ptr != head);
    if (len <= K)
    {
        int sum = 0;
        ptr = head;
        for (int i = 0; i < len; i++)
        {
            sum += ptr->val;
            ptr = ptr->nxt;
        }
        return (sum * A);
    }
    else
    {
        ptr = head;
        int time = (len + 1) / 2 - 1;
        for (int i = 0; i < time; i++)
            ptr = ptr->nxt;
        struct Node* new_head = ptr->nxt;
        ptr->nxt = head;
        prev->nxt = new_head;
        return split_cycle(head, A + 1, K) + split_cycle(prev, A + 2, K);
    }
}

#ifdef MAIN
int main()
{
    int n, A, K;
    scanf("%d %d %d\n", &n, &A, &K);
    struct Node *a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &a[i]->val);
    }
    for (int i = 0; i < n; i++)
    {
        a[i]->nxt = a[(i + 1) % n];
    }
    int ans = split_cycle(a[0], A, K);
    printf("%d\n", ans);
    return 0;
}
#endif