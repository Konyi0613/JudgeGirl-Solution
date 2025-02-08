#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

void find_the_path(struct node *root, int *path, int layer)
{
    if (root == NULL)
        return;
    path[layer] = root->data;
    layer++;
    if (root->left == NULL && root->right == NULL)
    {
        printf("%d", path[0]);
        for (int i = 1; i < layer; i++)
            printf(" %d", path[i]);
        printf("\n");
        return;
    }
    if (root->left != NULL)
        find_the_path(root->left, path, layer);
    if (root->right != NULL)
        find_the_path(root->right, path, layer);
    return;
}

void print_all_paths(struct node *root){
    int path[1001];
    find_the_path(root, path, 0);
}