#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char *suffix[20] = {
        "ed", "tion", "ness", "ful", "ing",	"ly", "able", 
        "ous", "ish", "ive", "less", "ism", "ist", "ize", 
        "ment", "ship", "ary", "ical", "ence", "hood"};
    for (int i = 19; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (strcmp(suffix[j], suffix[j + 1]) > 0)
            {
                char *ptr = suffix[j];
                suffix[j] = suffix[j + 1];
                suffix[j + 1] = ptr;
            }
    int frequency[20] = {0};
    char buffer[100001];
    while (scanf("%s", buffer) != EOF)
    {
        int len = strlen(buffer);
        if (!isalpha(buffer[len - 1]))
        {
            buffer[len - 1] = '\0';
            len--;
        }
        for (int i = 0; i < 20; i++)
        {
            int suffix_len = strlen(suffix[i]);
            char *ptr = &buffer[len - suffix_len];
            if (strcmp(ptr, suffix[i]) == 0)
            {
                frequency[i]++;
                break;
            }
        }
    }
    for (int i = 0; i < 20; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%s:\n", suffix[i]);
            printf("Frequency: %d\n", frequency[i]);
        }
    }
}