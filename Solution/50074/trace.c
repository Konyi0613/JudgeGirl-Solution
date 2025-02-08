#include <stdio.h>
#include <stdlib.h>
#include "trace.h"
// #define MAIN

int find_node_num(Node *root, ChildList *now, int *internal_node, int *max_branch)
{
    if (now == NULL)
        return 0;
    if (now->node->list != NULL)
    {
        (*internal_node)++;
        ChildList *child = now->node->list;
        int counter = 0;
        while (child != NULL)
        {
            child = child->next;
            counter++;
        }
        if (counter > *max_branch)
            *max_branch = counter;
    }
    return 1 + find_node_num(root, now->next, internal_node, max_branch) +
           find_node_num(now->node, now->node->list, internal_node, max_branch);
}

void find_depth(Node *root, ChildList *now, int now_layer, int *depth)
{
    if (now == NULL)
    {
        if (*depth < now_layer - 1)
            *depth = now_layer - 1;
        return;
    }
    find_depth(root, now->next, now_layer, depth);
    find_depth(now->node, now->node->list, now_layer + 1, depth);
}

void trace(Node *root, Answer *ans)
{
    if (root == NULL)
    {
        ans->InternalNode = 0;
        ans->Leaf = 0;
        ans->MaxBranchFactor = 0;
        ans->Depth = 0;
        return;
    }
    else if (root->list == NULL)
    {
        ans->InternalNode = 0;
        ans->Leaf = 1;
        ans->MaxBranchFactor = 0;
        ans->Depth = 0;
        return;
    }
    int internal_node = 1;
    int max_branch = 0;
    ChildList *ptr = root->list;
    while (ptr != NULL)
    {
        max_branch++;
        ptr = ptr->next;
    }
    int node_num = 1 + find_node_num(root, root->list, &internal_node, &max_branch);
    // printf("node_num: %d\n", node_num);
    int leaf = node_num - internal_node;
    ans->InternalNode = internal_node;
    ans->Leaf = leaf;
    ans->MaxBranchFactor = max_branch;
    int depth = 0;
    find_depth(root, root->list, 1, &depth);
    ans->Depth = depth;
}

#ifdef MAIN
Node *newNode()
{
    Node *ret = malloc(sizeof(Node));
    ret->list = NULL;
    return ret;
}
ChildList *newList(Node *node, ChildList *next)
{
    ChildList *ret = malloc(sizeof(ChildList));
    ret->node = node;
    ret->next = next;
    return ret;
}
int main()
{
    // sample input
    Node *root = newNode();
    Node *n1 = newNode(), *n2 = newNode(), *n3 = newNode(), *n4 = newNode(), *n5 = newNode(), *n6 = newNode();
    ChildList *l3 = newList(n3, NULL), *l2 = newList(n2, l3), *l1 = newList(n1, l2);
    ChildList *l5 = newList(n5, NULL), *l4 = newList(n4, l5), *l6 = newList(n6, NULL);
    root->list = l1;
    n2->list = l4;
    n4->list = l6;
    // end
    Answer *ans = calloc(1, sizeof(Answer));
    trace(root, ans);
    printf("%d %d %d %d\n", ans->InternalNode, ans->Leaf, ans->MaxBranchFactor, ans->Depth);
    return 0;
}
#endif