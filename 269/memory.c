#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "memory.h"

// #define DEBUG
// #define MAIN
Memory *getFreeBlock(int start, int length, Memory *next)
{
    Memory *block = (Memory *)malloc(sizeof(Memory));
    block->start = start;
    block->length = length;
    block->next = next;
    return block;
}

void initMemory(Memory *memory, int length)
{
    memory->start = 0;
    memory->length = length;
    memory->next = NULL;
}
void printMemory(Memory *memory)
{
    Memory *ptr = memory;
    // printf("%d %d\n",ptr->start,ptr->length);
    printf("==========\n");
    while (ptr != NULL)
    {
        if (ptr->length != 0)
            printf("start %d, length %d\n", ptr->start, ptr->length);
        ptr = ptr->next;
    }
    return;
}
void allocateMemory(Memory *memory, int start, int length)
{
    Memory *current = memory;
    Memory *previous = NULL;
    while (!((start >= current->start) && (start < current->start + current->length)))
    {
        previous = current;
        current = current->next;
    }
    int beginSame = (start == current->start);
    int endSame = (start + length == current->start + current->length);
    if (beginSame && endSame)
    {
        if (previous == NULL)
        {
            if (current->next != NULL)
                *memory = *(current->next);
            else
            {
                memory->start = 0;
                memory->length = 0;
                memory->next = NULL;
            }
        }
        else
        {
            previous->next = current->next;
        }
    }
    else if (beginSame)
    {
        current->start += length;
        current->length -= length;
    }
    else if (endSame)
    {
        current->length -= length;
    }
    else
    {
        Memory *after = getFreeBlock(start + length, (current->start + current->length) - (start + length), current->next);
        current->next = after;
        current->length = start - current->start;
    }
}

void freeMemory(Memory *memory, int start, int length)
{
    Memory *current = memory;
    Memory *previous = NULL;
    if (memory->length == 0)
    {
        memory->start = start;
        memory->length = length;
        memory->next = NULL;
        return;
    }
    while ((current != NULL) && (start > current->start))
    {
        previous = current;
        current = current->next;
    }
    int mergeprevious = ((previous != NULL) && (start == previous->start + previous->length));
    int mergecurrent = ((current != NULL) && (start + length == current->start));

    if (mergeprevious && mergecurrent)
    {
        previous->length += (length + current->length);
        previous->next = current->next;
    }
    else if (mergeprevious)
    {
        previous->length += length;
    }
    else if (mergecurrent)
    {
        current->length += length;
        current->start -= length;
    }
    else
    {
        if (previous == NULL)
        {
            Memory *between = getFreeBlock(start, length, memory);
            between->next = memory->next;
            memory->next = between;
            int temp;
            temp = between->length;
            between->length = memory->length;
            memory->length = temp;
            temp = between->start;
            between->start = memory->start;
            memory->start = temp;
            // printf("%d %d %d %d\n",memory->start,memory->length,(memory->next)->start,between->start);
        }
        else
        {
            Memory *between = getFreeBlock(start, length, current);
            previous->next = between;
        }
    }
}

#ifdef DEBUG
int main()
{
    Memory my_memory;
    initMemory(&my_memory, 100);
    printMemory(&(my_memory));
    allocateMemory(&my_memory, 0, 100);
    printMemory(&(my_memory));
}
#endif
#ifdef MAIN
int main()
{
    static Memory mem[2];
    char c;
    int i;
    memset(mem, 0xB3, sizeof(mem));
    while (scanf(" %c%d", &c, &i) == 2)
    {
        if (c == 'I')
        {
            int n;
            scanf("%d", &n);
            initMemory(mem + i, n);
        }
        else if (c == 'P')
        {
            printMemory(mem + i);
        }
        else
        {
            int b, n;
            scanf("%d%d", &b, &n);
            if (c == 'A')
                allocateMemory(mem + i, b, n);
            else
                freeMemory(mem + i, b, n);
        }
    }
    return 0;
}
#endif