struct Node
{
    int val;
    struct Node *nxt;
};
int split_cycle(struct Node *head, int A, int K);