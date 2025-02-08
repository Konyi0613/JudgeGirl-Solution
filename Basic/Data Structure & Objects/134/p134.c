#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #define DEBUG

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node;

typedef struct subtask
{
    int data;
    int level;
} Subtask;

Node* genNode(int data, Node* left, Node* right)
{
    Node* node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

Node* insert(Node* root, Subtask *subtask, int now)
{
    if (root == NULL && now == subtask->level)
        return genNode(subtask->data, NULL, NULL);
    if (now < subtask->level && subtask->data > root->data)
        root->right = insert(root->right, subtask, now + 1);
    else if (now < subtask->level && subtask->data < root->data)
        root->left = insert(root->left, subtask, now + 1);
    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("data = %d\n", root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}

int cmp(const void *p1, const void *p2)
{
    return (((Subtask *)p1)->level - ((Subtask *)p2)->level);
}

int one_search(Node* root, int target, int edge_num)
{
    if (root->data == target)
        return edge_num;
    else if (root->data > target)
        return one_search(root->left, target, edge_num + 1);
    else
        return one_search(root->right, target, edge_num + 1);
}

int search(Node* root, int t1, int t2)
{
    if (root->data > t1 && root->data > t2)
        return search(root->left, t1, t2);
    else if (root->data < t1 && root->data < t2)
        return search(root->right, t1, t2);
    else
        return one_search(root, t1, 0) + one_search(root, t2, 0);   
}

int main()
{
    int n;
    scanf("%d", &n);
    Subtask subtask[n];
    for (int i = 0; i < n; i++)
        scanf("%d%d", &subtask[i].data, &subtask[i].level);
    qsort(subtask, n, sizeof(Subtask), cmp);
#ifdef DEBUG
for (int i = 0; i < n; i++)
    printf("subtask[%d].data = %d, subtask[%d].level = %d\n", i, subtask[i].data, i, subtask[i].level);
#endif
    Node *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, &(subtask[i]), 1);
#ifdef DEBUG
    preorder(root);
#endif
    int task_num;
    scanf("%d", &task_num);
    int t1, t2;
    for (int i = 0; i < task_num; i++)
    {
        scanf("%d%d", &t1, &t2);
        printf("%d\n", search(root, t1, t2));
    }
}