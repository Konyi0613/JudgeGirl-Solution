#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAIN

typedef struct Node {
    char *val;
    struct Node *left, *right;
} Node;

bool evaluate(Node *root, int *values)
{
    if (root->left == NULL && root->right == NULL)
        return ((values[(root->val)[0] - 'A']) > 0);
    if ((root->val)[0] == '!')
        return !(evaluate(root->left, values));
    else if ((root->val)[0] == '|')
        return (evaluate(root->left, values) || evaluate(root->right, values));
    else
        return (evaluate(root->left, values) && evaluate(root->right, values));
}

void evaluateTree(Node *root, int *values)
{
    if(evaluate(root,values)){
        #ifdef LOWER
        printf("true\n");
        #endif
        #ifdef UPPER
        printf("TRUE\n");
        #endif
    }
    else{
        #ifdef LOWER
        printf("false\n");
        #endif
        #ifdef UPPER
        printf("FALSE\n");
        #endif
    }
}