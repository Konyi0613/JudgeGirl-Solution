#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;

Node* build(int array[], int n, int root_id)
{
    Node* root = (Node *)malloc(sizeof(Node));
    root->label = array[root_id];
    if (root_id * 2 + 1 < n)
        root->left = build(array, n, root_id * 2 + 1);
    else
        root->left = NULL;
    if (root_id * 2 + 2 < n)
        root->right = build(array, n, root_id * 2 + 2);
    else
        root->right = NULL;
    return root;
}
Node* construct(int array[], int n)
{
    return build(array, n, 0);
}