#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// #define DEBUG

typedef struct alphabet
{
    char character;
    int frequency;
} Alphabet;

void find_solution(int target, Alphabet alphabet[9], int index[9], bool used[9], int now_num)
{
    if (now_num == 10)
    {
        int sum = 0;
        for (int i = 1; i <= 9; i++)
            sum += (alphabet[index[i - 1]].frequency * i);
        if (sum == target)
        {
            printf("%c", alphabet[index[0]].character);
            for (int i = 1; i < 9; i++)
                printf(" %c", alphabet[index[i]].character);
            printf("\n");
            exit(0);
        }
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            index[now_num - 1] = i;
            find_solution(target, alphabet, index, used, now_num + 1);
            used[i] = false;
        }
    }
}

int cmp(const void *t1, const void *t2)
{
    return ((*(Alphabet *)t1).character - (*(Alphabet *)t2).character);
}

int main()
{
    int target;
    scanf("%d", &target);
    char string[20][101];
    int string_count = 0;
    while (scanf("%s", string[string_count]) != EOF)
        string_count++;
    Alphabet alphabet[9];
    int alphabet_count = 0;
    for (int i = 0; i < string_count; i++)
    {
        int len = strlen(&(string[i][0]));
        for (int j = 0; j < len; j++)
        {
            bool found = false;
            for (int k = 0; k < alphabet_count; k++)
            {
                if (alphabet[k].character == string[i][j])
                {
                    found = true;
                    alphabet[k].frequency++;
                    break;
                }
            }
            if (!found)
            {
                alphabet[alphabet_count].character = string[i][j];
                alphabet[alphabet_count].frequency = 1;
                alphabet_count++;
            }
        }
    }
    qsort(alphabet, 9, sizeof(Alphabet), cmp);
#ifdef DEBUG
    for (int i = 0; i < 9; i++)
        printf("alphabet[%d].character = %c, frequency = %d\n", i, alphabet[i].character, alphabet[i].frequency);
#endif
    int index[9];
    bool used[9] = {0};
    find_solution(target, alphabet, index, used, 1);
}