#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int m;
    scanf("%d", &m);
    int row[m], col[m];
    for (int i = 0; i < m; i++)
        scanf("%d%d", &row[i], &col[i]);
    for (int j = 0; j < m - 1; j++)
    {
        for (int i = 0; i < m - 1; i++)
        {
            if (row[i] > row[i + 1])
            {
                int temp = row[i];
                row[i] = row[i + 1];
                row[i + 1] = temp;
                temp = col[i];
                col[i] = col[i + 1];
                col[i + 1] = temp;
            }
            else if (row[i] == row[i + 1] && col[i] > col[i + 1])
            {
                int temp = col[i];
                col[i] = col[i + 1];
                col[i + 1] = temp;
            }
        }
    }
    /*for (int i = 0; i < m; i++)
        printf("%d %d\n", row[i], col[i]);*/
    for (int i = 0; i < m; i++)
    {
        int horizon = 0, vertical = 0;
        int col_counter = col[i];
        int row_counter = row[i];
        int type_h = 0;
        int type_v = 0;
        int type = 0;
        while (col_counter != n)
        {
            if (a[row[i]][col_counter] == 0)
                break;
            else
            {
                col_counter++;
                horizon++;
            }
            type_h = (horizon > 1);
        }
        horizon -= 1;
        col_counter = col[i];
        while (col_counter != -1)
        {
            if (a[row[i]][col_counter] == 0)
                break;
            else
            {
                col_counter--;
                horizon++;
            }
        }
        while (row_counter != n)
        {
            if (a[row_counter][col[i]] == 0)
                break;
            else
            {
                row_counter++;
                vertical++;
            }
            type_v = (vertical > 1);
        }
        vertical -= 1;
        row_counter = row[i];
        while (row_counter != -1)
        {
            if (a[row_counter][col[i]] == 0)
                break;
            else
            {
                row_counter--;
                vertical++;
            }
        }
        // 1 means right and down, 0 means left and up
        if (type_h == 0 && type_v == 0)
            type = 1;
        else if (type_h == 0 && type_v == 1)
            type = 2;
        else if (type_h == 1 && type_v == 0)
            type = 0;
        else
            type = 3;
        printf("%d %d %d\n", type, vertical, horizon);
    }
}