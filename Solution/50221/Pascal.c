#include <stdio.h>
#include <stdlib.h>
// #define MAIN

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

void link(Node* node_array, int height)
{
    int base = 0;
    for (int i = 0; i < height; i++)
    {
        int left_base = i;
        for (int j = 0; j < height - i; j++)
        {
            if (j == height - i - 1)
            {
                node_array[base + j].value = 0;
                node_array[base + j].right = NULL;
                node_array[left_base].value = 0;
                node_array[left_base].left = NULL;
            }
            else
            {
                node_array[base + j].value = 0;
                node_array[base + j].right = &node_array[base + j + 1];
                node_array[left_base].value = 0;
                node_array[left_base].left = &node_array[left_base + height - j];
                left_base += (height - j);
            }
        }
        base += (height - i);
    }
}

void build_Pascal(Node* node_array, int height)
{
    link(node_array, height);
    Node* ptr = node_array;
    while (ptr != NULL)
    {
        ptr->value = 1;
        ptr = ptr->right;
    }
    ptr = node_array;
    while(ptr != NULL)
    {
        ptr->value = 1;
        ptr = ptr->left;
    }
    for (int layer = 2; layer < height; layer++)
    {
        int n = layer + (height - 1);
        for (int i = 0; i < layer - 1; i++)
        {
            node_array[n].value = node_array[n - 1].value + node_array[n - height + i].value;
            n += (height - 2 - i);
        }

    }
}

#ifdef MAIN
int main(){
    int height;
    scanf("%d", &height);
    int node_num = height * (height+1) / 2;
    Node* node_array = (Node*)calloc(node_num, sizeof(Node));
    build_Pascal(node_array, height);
 
    for (int i = 0; i < node_num; i++){
        int value = node_array[i].value;
        int left = (node_array[i].left == NULL)? -1 : (node_array[i].left - node_array);
        int right = (node_array[i].right == NULL)? -1 : (node_array[i].right - node_array);
        printf("%d %d %d\n", value, left, right);
    }
    free(node_array);
    node_array = NULL;
    return 0;
}
#endif