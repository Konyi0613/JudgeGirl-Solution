#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
#define MAIN
typedef struct node Node;

void Build(char *code, char str, Node *root)
{
    if (*code == '\0')
    {
        root->data = str;
        return;
    }
    root->data = '?';
    if (*code == '.')
    {
        if (root->left == NULL)
        {
            root->left = (Node *)malloc(sizeof(Node));
            root->left->left = NULL;
            root->left->right = NULL;
        }
        Build(code + 1, str, root->left);
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = (Node *)malloc(sizeof(Node));
            root->right->left = NULL;
            root->right->right = NULL;
        }
        Build(code + 1, str, root->right);
    }
    return;
}

void build_tree(char **code, char *str, struct node *root, int n)
{
    for (int i = 0; i < n; i++)
        Build(code[i], str[i], root);
}

char ask(char *code, struct node *root)
{
    if (*code == '\0')
        return root->data;
    if (*code == '.')
    {
        if (root->left == NULL)
            return 'E';
        ask(code + 1, root->left);
    }
    else
    {
        if (root->right == NULL)
            return 'E';
        ask(code + 1, root->right);
    }
}

#ifdef MAIN
void print(struct node *root)
{
    printf("%c", root->data);
    if (root->left != NULL)
    {
        printf("l");
        print(root->left);
        printf("b");
    }
    if (root->right != NULL)
    {
        printf("r");
        print(root->right);
        printf("b");
    }
}
int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    ;
    root->left = NULL;
    root->right = NULL;
    root->data = '?';
    int mode;
    scanf("%d", &mode);
    if (mode == 1)
    {
        int n;
        scanf("%d", &n);
        char *code[2005], str[2005];
        for (int i = 0; i < n; i++)
        {
            code[i] = (char *)malloc(sizeof(char) * 2005);
            scanf("%s %c", code[i], &str[i]);
        }
        build_tree(code, str, root, n);
        print(root);
    }
    if (mode == 2)
    {
        int n;
        scanf("%d", &n);
        char *code[2005], str[2005];
        for (int i = 0; i < n; i++)
        {
            code[i] = (char *)malloc(sizeof(char) * 2005);
            scanf("%s %c", code[i], &str[i]);
        }
        build_tree((char **)code, str, root, n);
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            char c[2005];
            scanf("%s", c);
            printf("%c", ask(c, root));
        }
    }
    return 0;
}
#endif