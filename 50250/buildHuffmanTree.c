#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "huffmanTree.h"

int compare(const void *a, const void *b)
{
    Node *a1 = *(Node **)a;
    Node *b1 = *(Node **)b;
    if (a1->frequency != b1->frequency)
    {
        return a1->frequency - b1->frequency;
    }
    return strcmp(a1->symbol, b1->symbol);
}

// Function to build the Huffman Tree
Node *buildHuffmanTree(char *s[], int n)
{
    Node *nodes[n];
    int unique_string_num = 0;

    // Step 1: Count frequencies and initialize nodes
    for (int i = 0; i < n; i++)
    {
        int found = -1;
        for (int j = 0; j < unique_string_num; j++)
        {
            if (strcmp(s[i], nodes[j]->symbol) == 0)
            {
                found = j;
                break;
            }
        }
        if (found != -1)
        {
            nodes[found]->frequency++;
        }
        else
        {
            nodes[unique_string_num] = (Node *)malloc(sizeof(Node));
            strcpy(nodes[unique_string_num]->symbol, s[i]);
            nodes[unique_string_num]->frequency = 1;
            nodes[unique_string_num]->left = NULL;
            nodes[unique_string_num]->right = NULL;
            unique_string_num++;
        }
    }

    // Step 2: Construct the Huffman Tree
    int numNodes = unique_string_num;
    while (numNodes > 1)
    {
        // Sort nodes by frequency and lexicographical order
        qsort(nodes, numNodes, sizeof(Node *), compare);

        // Merge two nodes with the lowest frequency
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->frequency = nodes[0]->frequency + nodes[1]->frequency;
        newNode->left = nodes[1];  // Second smallest goes to the left
        newNode->right = nodes[0]; // Smallest goes to the right

        // Assign symbol of the new node based on the smallest symbol of the subtree
        if (strcmp(nodes[0]->symbol, nodes[1]->symbol) < 0)
        {
            strcpy(newNode->symbol, nodes[0]->symbol);
        }
        else
        {
            strcpy(newNode->symbol, nodes[1]->symbol);
        }

        // Replace the two smallest nodes with the new node and reduce the array size by one
        nodes[0] = newNode;
        nodes[1] = nodes[numNodes - 1]; // Move the last node to fill the gap
        numNodes--;
    }

    return nodes[0]; // The last remaining node is the root of the Huffman Tree
}
/*
int compare(const void *a, const void *b)
{
    Node *a1 = *(Node **)a;
    Node *b1 = *(Node **)b;

    // Rule 1: Sort by frequency in descending order
    if (a1->frequency != b1->frequency)
    {
        return b1->frequency - a1->frequency;
    }
    // Rule 2: If frequencies are equal, sort by symbol in descending lexicographical order
    return strcmp(b1->symbol, a1->symbol);
}
Node *buildHuffmanTree(char *s[SYM_MAX_NUM], int n)
{
    Node *now_node[n + 1];
    int unique_string_num = 0;
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < unique_string_num; j++)
        {
            if (strcmp(s[i], now_node[j]->symbol) == 0)
            {
                now_node[j]->frequency++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            now_node[unique_string_num] = (Node *)malloc(sizeof(Node));
            strcpy(now_node[unique_string_num]->symbol, s[i]);
            now_node[unique_string_num]->frequency = 1;
            now_node[unique_string_num]->left = NULL;
            now_node[unique_string_num]->right = NULL;
            unique_string_num++;
        }
    }
    int now_node_num = unique_string_num;
    while (now_node_num > 1)
    {
        qsort(now_node, now_node_num, sizeof(Node *), compare);
        now_node[now_node_num] = (Node *)malloc(sizeof(Node));
        now_node[now_node_num]->frequency = now_node[now_node_num - 2]->frequency + now_node[now_node_num - 1]->frequency;
        now_node[now_node_num]->left = now_node[now_node_num - 2];
        now_node[now_node_num]->right = now_node[now_node_num - 1];
        strcpy(now_node[now_node_num]->symbol, now_node[now_node_num - 2]->symbol);
        now_node_num--;
        now_node[now_node_num - 1] = now_node[now_node_num + 1];
    }
    return now_node[0];
}
*/
void printTree(Node *node)
{
    if (node->left == NULL && node->right == NULL)
    {
        printf("%d %s\n", node->frequency, node->symbol);
        return;
    }
    printf("%d\n", node->frequency);
    printTree(node->left);
    printTree(node->right);
}

int main()
{
    int n;
    char *s[SYM_MAX_NUM];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        s[i] = (char *)malloc(sizeof(char) * SYM_MAX_LEN);
        scanf("%s", s[i]);
    }
    Node *root = buildHuffmanTree(s, n);
    printTree(root);

    for (int i = 0; i < n; i++)
    {
        free(s[i]);
    }
}