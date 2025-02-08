#include <stdio.h>
int hasEOF = 0;
int readchar()
{
    static int N = 1 << 20;
    static char buf[1 << 20];
    static char *p = buf, *end = buf;
    if (p == end)
    {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf)
        {
            hasEOF = 1;
            return EOF;
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x)
{
    char c, neg;
    while ((c = readchar()) < '-')
    {
        if (c == EOF)
            return 0;
    }
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c - '0' : 0;
    while ((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c - '0';
    *x *= neg;
    return 1;
}
int main()
{
    int now_book;
    int book_shelf[8] = {0};
    while (ReadInt(&now_book))
    {
        int search = -1;
        for (int i = 0; i < 8; i++)
        {
            if (book_shelf[i] == now_book)
            {
                search = i;
                for (int j = i; j < 7; j++)
                    book_shelf[j] = book_shelf[j + 1];
                book_shelf[7] = now_book;
            }
        }
        if (search == -1)
        {
            for (int j = 0; j < 7; j++)
                book_shelf[j] = book_shelf[j + 1];
            book_shelf[7] = now_book;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%d", book_shelf[i]);
        if (i != 7)
            printf(" ");
    }
}