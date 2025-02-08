#include <stdio.h>
#include <string.h>
#include <stdio.h>
void translate(int length, int dimension, char *ptr)
{
    char unit[7][15] = {"", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion"};
    char first_dig[10][8] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char second_dig[10][10] = {"", "", "twenty-", "thirty-", "forty-", "fifty-", "sixty-", "seventy-", "eighty-", "ninety-"};
    char ten2dig[10][10] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    int now_digit = length - dimension * 3;
    char tmp[4];
    strncpy(tmp, ptr, 3);
    tmp[3] = '\0';
    int pos = 0;
    if (now_digit > 1)
    {
        if (now_digit == 3)
        {
            char hundred_digit = tmp[0];
            printf("%s hundred ", first_dig[hundred_digit - '0']);
            pos++;
        }
        if (tmp[pos] - '0' == 1)
        {
            int index = tmp[pos + 1] - '0';
            printf("%s ", ten2dig[index]);
        }
        else
            printf("%s%s ", second_dig[(tmp[pos] - '0')], first_dig[tmp[pos + 1] - '0']);
    }
    else
        printf("%s ", first_dig[tmp[0] - '0']);
    printf("%s", unit[dimension]);
}
int main()
{
    char number[21];
    scanf("%s", number);
    int length = strlen(number);
    int dimension = (length - 1) / 3;
    char *ptr = &number[0];
    int dim_copy = dimension;
    for (int i = 0; i < dim_copy + 1; i++)
    {
        int now_digit = length - dimension * 3;
        translate(length, dimension, ptr);
        printf(" ");
        length -= now_digit;
        dimension--;
        ptr += now_digit;
    }
}