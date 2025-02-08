#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int main()
{
    char hashtable[1000][3][21];
    int hash_times[1000][3] = {{0, 0, 0}};
    char str[21];
    while (scanf("%s", str) != EOF)
    {
        if (!(str[0] == '_' || isalpha(str[0])))
            continue;
        int len = strlen(str);
        bool skip = false;
        for (int i = 1; i < len; i++)
            if (!(isalnum(str[i]) == true || str[i] == '_'))
                skip = true;
        if (skip)
            continue;
        int sum = 0;
        for (int i = 0; i < len; i++)
            sum += str[i];
        int hash_value = sum % 1000;
        int hash_index = -1;
        for (int i = 0; i < 3; i++)
        {
            if (strcmp(str, hashtable[hash_value][i]) == 0)
            {
                hash_index = i;
                break;
            }
        }
        if (hash_index == -1)
        {
            for (int i = 0; i < 3; i++)
                if (hash_times[hash_value][i] == 0)
                {
                    strcpy(hashtable[hash_value][i], str);
                    hash_times[hash_value][i] = 1;
                    hash_index = i;
                    break;
                }
        }
        else
            hash_times[hash_value][hash_index]++;
        printf("%s ", hashtable[hash_value][hash_index]);
        printf("%d\n", hash_times[hash_value][hash_index]);
    }
}