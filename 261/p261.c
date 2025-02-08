#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// #define DEBUG1
// #define DEBUG2
void string_to_number(int alpha_num, char string[3][10], int len[3], char alphabet[alpha_num], int corresponding_number[alpha_num])
{
#ifdef DEBUG1
    for (int i = 0; i < alpha_num; i++)
        printf("corresponding_number[%d] = %d\n", i, corresponding_number[i]);
    printf("\n");
#endif
    char number_string[3][10];
    for (int id1 = 0; id1 < 3; id1++)
    {
        for (int id2 = 0; id2 < len[id1]; id2++)
        {
            int now_id;
            for (int k = 0; k < alpha_num; k++)
                if (alphabet[k] == string[id1][id2])
                {
                    now_id = k;
                    break;
                }
            number_string[id1][id2] = '0' + corresponding_number[now_id];
        }
        number_string[id1][len[id1]] = '\0';
    }
#ifdef DEBUG2
    printf("%s x %s = %s", number_string[0], number_string[1], number_string[2]);
#endif
    int start_zero_num[3] = {0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < len[i]; j++)
            if (number_string[i][j] == '0')
                start_zero_num[i]++;
            else
                break;
    int real_number[3] = {0};
    for (int i = 0; i < 3; i++)
        for (int j = start_zero_num[i]; j < len[i]; j++)
            real_number[i] = real_number[i] * 10 + (number_string[i][j] - '0');
    if (real_number[0] * real_number[1] == real_number[2])
    {
        printf("%s x %s = %s\n", number_string[0], number_string[1], number_string[2]);
        exit(0);
    }
}

void find_solution(int alpha_num, char string[3][10], int len[3], char alphabet[alpha_num], int corresponding_number[alpha_num], int id1, int id2)
{
    if (id1 == 3 && id2 == 0)
    {
        string_to_number(alpha_num, string, len, alphabet, corresponding_number);
        return;
    }
    int next_id1, next_id2;
    for (int i = 0; i < 3; i++)
        if (id1 == i)
        {
            if (id2 == len[i] - 1)
            {
                next_id1 = i + 1;
                next_id2 = 0;
            }
            else
            {
                next_id1 = id1;
                next_id2 = id2 + 1;
            }
        }
    if (isdigit(string[id1][id2]))
    {
        find_solution(alpha_num, string, len, alphabet, corresponding_number, next_id1, next_id2);
        return;
    }
    int now_id;
    for (int i = 0; i < alpha_num; i++)
        if (alphabet[i] == string[id1][id2])
        {
            now_id = i;
            break;
        }
#ifdef DEBUG1
        // printf("id1: %d id2: %d now_id: %d\n", id1, id2, now_id);
#endif
    if (corresponding_number[now_id] == 0)
        for (int i = 1; i <= 9; i++)
        {
            corresponding_number[now_id] = i;
            find_solution(alpha_num, string, len, alphabet, corresponding_number, next_id1, next_id2);
            corresponding_number[now_id] = 0;
        }
    else
        find_solution(alpha_num, string, len, alphabet, corresponding_number, next_id1, next_id2);
}

int main()
{
    char string[3][10];
    scanf("%s", string[0]);
    scanf("%s", string[1]);
    scanf("%s", string[2]);
    int len[3];
    len[0] = strlen(string[0]);
    len[1] = strlen(string[1]);
    len[2] = strlen(string[2]);
    int alpha_num = 0;
    char alphabet[27];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < len[i]; j++)
        {
            if (isdigit(string[i][j]))
            {
                alphabet[alpha_num] = string[i][j];
                alpha_num++;
            }
            bool found = false;
            for (int k = 0; k < alpha_num; k++)
                if (alphabet[k] == string[i][j])
                {
                    found = true;
                    break;
                }
            if (!found)
            {
                alphabet[alpha_num] = string[i][j];
                alpha_num++;
            }
        }
    int corresponding_number[alpha_num];
    for (int i = 0; i < alpha_num; i++)
    {
        if (isdigit(alphabet[i]))
            corresponding_number[i] = alphabet[i] - '0';
        else
            corresponding_number[i] = 0;
    }
#ifdef DEBUG1
    for (int i = 0; i < alpha_num; i++)
        printf("alphabet[%d]: %c corresponding_number[%d]: %d\n", i, alphabet[i], i, corresponding_number[i]);
    printf("\n");
#endif
    find_solution(alpha_num, string, len, alphabet, corresponding_number, 0, 0);
}