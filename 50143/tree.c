#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;

Node *treeAND(Node *root1, Node *root2)
{
    Node *result;
    if (root1 != NULL && root2 != NULL)
    {
        result = (Node *)malloc(sizeof(Node));
        result->val = root1->val * root2->val;
        result->left = treeAND(root1->left, root2->left);
        result->right = treeAND(root1->right, root2->right);
    }
    else
        result = NULL;
    return result;
}

Node *treeOR(Node *root1, Node *root2)
{
    Node *result;
    if (root1 != NULL && root2 != NULL)
    {
        result = (Node *)malloc(sizeof(Node));
        result->val = root1->val + root2->val;
        result->left = treeOR(root1->left, root2->left);
        result->right = treeOR(root1->right, root2->right);        
    }
    else if (root1 != NULL)
    {
        result = (Node *)malloc(sizeof(Node));
        result->val = root1->val;
        result->left = root1->left;
        result->right = root1->right;
    }
    else if (root2 != NULL)
    {
        result = (Node *)malloc(sizeof(Node));
        result->val = root2->val;
        result->left = root2->left;
        result->right = root2->right;
    }
    else
        result = NULL;
    return result;
}