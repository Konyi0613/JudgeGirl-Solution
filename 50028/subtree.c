#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// #define MAIN

typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;

int find_k(Node* root, int label[], int k, int *id, int *num)
{
    if (root == NULL)
        return 0;
    int l = find_k(root->left, label, k, id, num);
    int r = find_k(root->right, label, k, id, num);
    if (root->label != k && l > 0 && r > 0)
    {
        label[*id] = root->label;
        (*id)++;
        (*num)++;
    }
    if (root->label == k)
        return 1 + l + r;
    else
        return l + r;
}

int getNode(Node *root, int label[], int k)
{
    int id = 0, num = 0;
    find_k(root, label, k, &(id), &(num));
    return num;
}

#ifdef MAIN
Node* newNode(int label, Node *l, Node *r) {
    Node *u = (Node *) malloc(sizeof(Node));
    u->label = label, u->left = l, u->right = r;
    return u;
}
 
int main() {
    Node *root = newNode(
        10,
            newNode(
                5,
                    newNode(1, NULL, NULL),
                    newNode(1, NULL, NULL)               
            ),
            newNode(
                7,
                    newNode(1, NULL, NULL),
                    newNode(5, NULL, NULL)               
            )
    );
    int k;
    while (scanf("%d", &k) == 1) {
        int A[128];
        int n = getNode(root, A, k);
        printf("%d\n", n);
        for (int i = 0; i < n; i++)
            printf("%d%c", A[i], i == n-1 ? '\n' : ' ');
    }
    return 0;
}
#endif
