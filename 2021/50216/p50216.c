#include <stdio.h>
#include <string.h>
// #define DEBUG
int max(int a, int b, int c, int d)
{
    int bigger1 = (a > b) ? a : b;
    int bigger2 = (bigger1 > c) ? bigger1 : c;
    int bigger3 = (bigger2 > d) ? bigger2 : d;
    return bigger3;
}

int find_same(char base, char str1[], char start1, int len1)
{
    while (start1 < len1)
        if (base == str1[start1])
            return start1;
        else
            start1++;
    return len1;
}

int LCS(char str[3][15], int len[3], int start0, int start1, int start2, int longest_length)
{
    if (start0 == len[0] || start1 == len[1] || start2 == len[2])
    {
#ifdef DEBUG
        printf("longest_length: %d\n", longest_length);
#endif
        return 0;
    }
    if (str[0][start0] == str[1][start1] && str[1][start1] == str[2][start2])
        return 1 + LCS(str, len, start0 + 1, start1 + 1, start2 + 1, longest_length + 1);
    int first_same01 = find_same(str[0][start0], str[1], start1, len[1]), first_same02 = find_same(str[0][start0], str[2], start2, len[2]);
    int keep_0 = LCS(str, len, start0, first_same01, first_same02, longest_length);
    int first_same10 = find_same(str[1][start1], str[0], start0, len[0]), first_same12 = find_same(str[1][start1], str[2], start2, len[2]);
    int keep_1 = LCS(str, len, first_same10, start1, first_same12, longest_length);
    int first_same20 = find_same(str[2][start2], str[0], start0, len[0]), first_same21 = find_same(str[2][start2], str[1], start1, len[1]);
    int keep_2 = LCS(str, len, first_same20, first_same21, start2, longest_length);
    int skip = LCS(str, len, start0 + 1, start1 + 1, start2 + 1, longest_length);
#ifdef DEBUG
    printf("start0: %d, start1: %d, start2: %d, longest_length: %d\n", start0, start1, start2, longest_length);
#endif
    return max(keep_0, keep_1, keep_2, skip);
}
int main()
{
    char str[3][15];
    while (scanf("%s%s%s", str[0], str[1], str[2]) != EOF)
    {
        int len[3];
        len[0] = strlen(&(str[0][0]));
        len[1] = strlen(&(str[1][0]));
        len[2] = strlen(&(str[2][0]));
        printf("%d\n", LCS(str, len, 0, 0, 0, 0));
    }
}