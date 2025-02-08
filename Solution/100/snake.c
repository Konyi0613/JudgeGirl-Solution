#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "snake.h"

void snake(const int *ptr_array[100][100], int m)
{
    bool used[m * m];
    for (int i = 0; i < m * m; i++)
        used[i] = false;
    for (int times = 0; times < m * m; times++)
    {
        int min;
        int min_num;
        bool found = false;
        for (int i = 0; i < m * m; i++)
        {
            if (!found)
            {
                if (used[i])
                    continue;
                else
                {
                    min = *ptr_array[i / m][i % m];
                    min_num = i;
                    found = true;
                }
            }
            else if (*ptr_array[i / m][i % m] < min && !used[i])
            {
                min = *ptr_array[i / m][i % m];
                min_num = i;
            }
        }
        int row = times / m;
        int col;
        if (row % 2 == 0)
            col = times % m;
        else
            col = m - 1 - times % m;
        used[row * m + col] = true;
        int *tmp = ptr_array[min_num / m][min_num % m];
        ptr_array[min_num / m][min_num % m] = ptr_array[row][col];
        ptr_array[row][col] = tmp;
    }
}

int main()
{
    int array[100][100], check[100][100];
    const int *ptr_array[100][100];
    int i, j, m;

    scanf("%d", &m);
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            ptr_array[i][j] = &(array[i][j]);
            scanf("%d", &(array[i][j]));
            check[i][j] = array[i][j];
        }

    snake(ptr_array, m);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            assert(check[i][j] == array[i][j]);
            assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
            printf("%d ", *(ptr_array[i][j]));
        }
        printf("\n");
    }

    return 0;
}
