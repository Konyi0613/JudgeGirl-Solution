#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "sub.h"
// #define MAIN

int find_substring(Node *text, Node *pattern, int id, int pattern_length)
{
    if (text == NULL)
        return 0;
    Node *text_ptr = text;
    Node *pattern_ptr = pattern;
    bool found = false;
    while (pattern_ptr != NULL)
    {
        if (text_ptr->c != pattern_ptr->c)
            break;
        if (pattern_ptr->next == NULL)
        {
            found = true;
            break;
        }
        if (text_ptr->next == NULL)
            break;
        pattern_ptr = pattern_ptr->next;
        text_ptr = text_ptr->next;
    }
    if (found)
    {
        int sum = 0;
        for (int i = id; i < id + pattern_length; i++)
            sum += i;
        return sum;
    }
    else
        return find_substring(text->next, pattern, id + 1, pattern_length);
}

void substring(Node *text, Node *pattern)
{
    Node *ptr = pattern;
    int len = 0;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }
    printf("%d", find_substring(text, pattern, 0, len));
}

int find_subsequence(Node *text, Node *pattern, int id)
{
    if (pattern == NULL)
        return 0;
    if (text->c == pattern->c)
        return id + find_subsequence(text->next, pattern->next, id + 1);
    else
        return find_subsequence(text->next, pattern, id + 1);
}

void subsequence(Node *text, Node *pattern)
{
    printf("%d", find_subsequence(text, pattern, 0));
}

#ifdef MAIN
Node *insert(Node *root, char c)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->c = c;
        root->next = NULL;
        return root;
    }
    root->next = insert(root->next, c);
    return root;
}
int main(int argc, char const *argv[])
{
    char tmp = '\n';
    int N, M, i, act;
    Node *text = NULL, *pattern = NULL, *cur = NULL;

    scanf("%d%d", &act, &N);
    while (isspace(tmp))
        scanf("%c", &tmp);
    text = insert(text, tmp);
    cur = text;
    for (i = 0; i < N - 1; i++)
    {
        scanf("%c", &tmp);
        cur->next = insert(cur->next, tmp);
        cur = cur->next;
    }

    scanf("%d", &M);
    tmp = '\n';
    while (isspace(tmp))
        scanf("%c", &tmp);
    pattern = insert(pattern, tmp);
    cur = pattern;
    for (i = 0; i < M - 1; i++)
    {
        scanf("%c", &tmp);
        cur->next = insert(cur->next, tmp);
        cur = cur->next;
    }
    if (!act)
        substring(text, pattern);
    else
        subsequence(text, pattern);
    return 0;
}
#endif