#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *t1, const void *t2)
{
    return strcmp((char *)t1, (char *)t2);
}

int main()
{
    int n;
    scanf("%d", &n);
    char string[8];
    char ans[2][n][8];
    int num[2] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%s", string);
        bool valid = true;
        int type = -1, digit_num = 0, digit_sum = 0, last_four = -2, four_num = 0;
        for (int j = 0; j < 7; j++)
        {
            if (j != 2 && j != 3 && !isalpha(string[j]) && !isdigit(string[j]))
            {
                // printf("j = %d error1\n", j);
                valid = false;
                break;
            }
            else if (j == 2 && string[j] == '-')
                type = 0;
            else if (j == 3 && string[j] == '-')
                type = 1;
            else if (j == 3 && type == -1)
            {
                // printf("j = %d error2\n", j);
                valid = false;
                break;
            }
            else if (isdigit(string[j]))
            {
                digit_num++;
                digit_sum += (string[j] - '0');
                if (string[j] == '4')
                {
                    if (last_four + 1 == j || four_num > 2)
                    {
                        // printf("j = %d error3\n", j);
                        valid = false;
                        break;
                    }
                    last_four = j;
                }
            }
            for (int k = 0; k < j; k++)
                if (string[j] == string[k])
                {
                    for (int l = j + 1; l < 7; l++)
                        if (string[l] == string[j])
                        {
                            // printf("j = %d error4\n", j);
                            valid = false;
                            break;
                        }
                }
        }
        printf("%d %d\n", digit_num, digit_sum);
        if (digit_num == 0 || digit_sum % 7 == 0 || !valid)
            continue;
        strcpy(ans[type][num[type]], string);
        num[type]++;
    }
    qsort(ans[0], num[0], sizeof(char [8]), cmp);
    qsort(ans[1], num[1], sizeof(char [8]), cmp);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < num[i]; j++)
            printf("%s\n", ans[i][j]);
}