typedef struct memory
{
    int start;
    int length;
    struct memory *next;
} Memory;