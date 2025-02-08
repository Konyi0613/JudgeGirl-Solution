#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 4001

typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
} Treenode;

typedef struct value
{
    int value;
    int next;
} Value;

void HLHR(Treenode *root);
void HRHL(Treenode *root);

Value findvalue(char tree[], int start)
{
    int v = 0;
    while (isdigit(tree[start]))
    {
        v = v * 10 + tree[start] - '0';
        start++;
    }
    return (Value){v, start};
}
int build(char tree[], int start, Treenode *root)
{
    if (isdigit(tree[start]))
    {
        Value e = findvalue(tree, start);
        root->data = e.value;
        root->left = NULL;
        root->right = NULL;
        return e.next;
    }
    Treenode *left = (Treenode *)malloc(sizeof(Treenode));
    Treenode *right = (Treenode *)malloc(sizeof(Treenode));
    root->left = left;
    root->right = right;
    int n;
    n = build(tree, start + 1, left);
    n = build(tree, n + 1, right);
    root->data = left->data + right->data;
    return (n + 1);
}

void HLHR(Treenode *root)
{
    if (root == NULL)
        return;
    printf("%d\n", root->data);
    HRHL(root->left);
    printf("%d\n", root->data);
    HRHL(root->right);
}

void HRHL(Treenode *root)
{
    if (root == NULL)
        return;
    printf("%d\n", root->data);
    HLHR(root->right);
    printf("%d\n", root->data);
    HLHR(root->left);
}

int main()
{
    char tree[MAX];
    scanf("%s", tree);
    Treenode root;
    build(tree, 0, &root);
    HLHR(&root);
    return 0;
}