#include <stdio.h>

int main()
{
    int row, col;
    scanf("%d%d", &row, &col);
    int matrix;
    int largest = -1, largest_r, largest_c;
    for (int i = 0; i < row; i++)
    {
        int lc = 0, slc, lc_val, slc_val;
        int found = -1;
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix);
            if (j == 0)
            {
                lc_val = matrix;
                continue;
            }
            if (matrix >= lc_val)
            {
                slc_val = lc_val;
                lc_val = matrix;
                slc = lc;
                lc = j;
                found = 1;
            }
            else if (found == -1 || matrix >= slc_val)
            {
                found = 1;
                slc = j;
                slc_val = matrix;
            }
            if (lc_val >= largest)
            {
                largest = lc_val;
                largest_r = i;
                largest_c = lc;
            }
        }
        printf("%d %d\n", lc + 1, slc + 1);
    }
    printf("%d %d\n", largest_r + 1, largest_c + 1);
}