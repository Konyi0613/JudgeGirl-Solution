#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int search(int M, char *tg, char arr[M][51], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
        if (strcmp(tg, &(arr[i][0])) == 0)
            return i;
    return -1;
}

int main()
{
    int M;
    scanf("%d", &M);
    char author[M][51], book[M][51];
    int author_num = 0, sell[M], author_to_book[M][M], author_book_num[M];
    char author_buffer[51], book_buffer[51];
    for (int i = 0; i < M; i++)
    {
        sell[i] = 0;
        scanf("%s%s", author_buffer, book_buffer);
        int k = search(M, author_buffer, author, author_num);
        if (k == -1)
        {
            strcpy(author[author_num], author_buffer);
            author_book_num[author_num] = 1;
            author_to_book[author_num][0] = i;
            author_num++;
        }
        else
        {
            author_to_book[k][author_book_num[k]] = i;
            author_book_num[k]++;
        }
        strcpy(book[i], book_buffer);
    }
    for (int i = 0; i < M; i++)
    {
        char name[51];
        int sell_buffer;
        scanf("%s%d", name, &sell_buffer);
        int k = search(M, name, book, M);
        sell[k] += sell_buffer;
    }
    int top_id = 0, top_sell = -1;
    for (int i = 0; i < author_num; i++)
    {
        int total = 0;
        for (int j = 0; j < author_book_num[i]; j++)
            total += sell[author_to_book[i][j]];
        if (total > top_sell || (total == top_sell && strcmp(&(author[i][0]), &(author[top_id][0])) <= 0))
        {
            top_sell = total;
            top_id = i;
        }
    }
    printf("%s %d\n", author[top_id], top_sell);
}