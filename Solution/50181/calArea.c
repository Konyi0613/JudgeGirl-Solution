#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calArea.h"

int calArea(NODE *head)
{
    int right_num = 0, down_num = 0;
    right_num++;
    NODE *head_r = head->rightPtr;
    while (head_r->rightPtr != NULL || head_r->downPtr != NULL)
    {
        if (head_r->rightPtr == NULL)
        {
            down_num++;
            head_r = head_r->downPtr;
        }
        else
        {
            head_r = head_r->rightPtr;
            right_num++;
        }
    }
    // printf("%d %d\n", right_num, down_num);
    int all_area = right_num * down_num;
    head_r = head->rightPtr;
    // subtract upper area
    int now_down = 0, now_right = 1;
    int subtract_area = 0;
    int accumulate_right = 1;
    char pre_dir = 'r', now_dir;
    while (accumulate_right < right_num)
    {
        now_dir = (head_r->rightPtr != NULL) ? 'r' : 'd';
        if (pre_dir == 'r' && now_dir == 'd')
        {
            // printf("subtract %d\n", now_down * now_right);
            subtract_area += (now_down * now_right);
            now_right = 0;
        }
        if (now_dir == 'r')
        {
            accumulate_right++;
            now_right++;
            head_r = head_r->rightPtr;
            pre_dir = 'r';
        }
        else
        {
            now_down++;
            head_r = head_r->downPtr;
            pre_dir = 'd';
        }
        // printf("now_down: %d now_right: %d\n", now_down, now_right);
    }
    subtract_area += now_down * now_right;
    // printf("%d\n", subtract_area);
    all_area -= subtract_area;
    subtract_area = 0;
    // subtract lower area
    now_down = 1;
    now_right = 0;
    pre_dir = 'd';
    NODE *head_d = head->downPtr;
    int accumulate_down = 1;
    while (accumulate_down < down_num)
    {
        now_dir = (head_d->rightPtr != NULL) ? 'r' : 'd';
        if (pre_dir == 'd' && now_dir == 'r')
        {
            subtract_area += (now_down * now_right);
            now_down = 0;
        }
        if (now_dir == 'r')
        {
            now_right++;
            head_d = head_d->rightPtr;
            pre_dir = 'r';
        }
        else
        {
            now_down++;
            head_d = head_d->downPtr;
            accumulate_down++;
            pre_dir = 'd';
        }
        // printf("now_down: %d now_right: %d\n", now_down, now_right);
    }
    subtract_area += now_down * now_right;
    // printf("%d\n", subtract_area);
    all_area -= subtract_area;
    return all_area;
}
/*
NODE *initList(NODE *pos, int len)
{
    NODE *tail = pos;
    char direction;
    for (int i = 0; i < len - 1; i++)
    {
        scanf("%c", &direction);
        getchar();
        NODE *pNew = (NODE *)malloc(sizeof(NODE));
        pNew->downPtr = NULL;
        pNew->rightPtr = NULL;
        if (direction == 'r')
        {
            pos->rightPtr = pNew;
            pos = pos->rightPtr;
        }
        else
        {
            pos->downPtr = pNew;
            pos = pos->downPtr;
        }
        if (i == len - 3)
            tail = pos;
    }
    return tail;
}

int main()
{
    int len;

    NODE *head = (NODE *)malloc(sizeof(NODE));

    scanf("%d\n", &len);
    getchar();
    NODE *pos;
    char direction;
    scanf("%c", &direction);
    head->rightPtr = (NODE *)malloc(sizeof(NODE));
    pos = head->rightPtr;
    pos->downPtr = NULL;
    pos->rightPtr = NULL;
    NODE *tailR = initList(pos, len);

    head->downPtr = (NODE *)malloc(sizeof(NODE));
    pos = head->downPtr;
    pos->downPtr = NULL;
    pos->rightPtr = NULL;
    scanf("%c", &direction);
    getchar();
    NODE *tailD = initList(pos, len);
    free(tailD->rightPtr);
    tailD->rightPtr = tailR->downPtr;

    printf("%d", calArea(head));
}
*/