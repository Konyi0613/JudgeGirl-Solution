#include <stdio.h>
#include <string.h>

typedef struct solution
{
    int distance;
    int ID1;
    int ID2;
} Solution;

int distance(char *str1, char *str2, int len1, int len2, int start1, int start2)
{
    // printf("len1: %d len2: %d\n", len1, len2);
    if (start1 == len1)
        return len2 - start2;
    if (start2 == len2)
        return len1 - start1;
    if (str1[start1] == str2[start2])
        return (distance(str1, str2, len1, len2, start1 + 1, start2 + 1));
    int a1 = distance(str1, str2, len1, len2, start1 + 1, start2);
    int a2 = distance(str1, str2, len1, len2, start1, start2 + 1);
    // printf("a1: %d a2: %d\n", a1, a2);
    return (1 + ((a1 > a2) ? a2 : a1));
}

void find_small(int length[100], char str[100][11], int str_count, Solution *best)
{

    for (int index = 0; index < str_count; index++)
    {
        for (int i = index + 1; i < str_count; i++)
        {
            int d = distance(&(str[index][0]), &(str[i][0]), length[index], length[i], 0, 0);
            // printf("%d\n", i);
            if (d < best->distance || (d == best->distance && 1000 * (index + 1) + (i + 1) < 1000 * best->ID1 + best->ID2))
            {
                best->distance = d;
                best->ID1 = index + 1;
                best->ID2 = i + 1;
            }
        }
        if (index == str_count - 1)
        {
            printf("%d %d %d", best->distance, best->ID1, best->ID2);
            return;
        }
    }
}

int main()
{
    int str_count = 0;
    char str[100][11];
    int length[100];
    while (scanf("%s", str[str_count]) != EOF)
    {
        length[str_count] = strlen(str[str_count]);
        str_count++;
    }
    Solution best = {200, 200, 200};
    find_small(length, str, str_count, &best);
    // printf("%d", distance("a", "x"));
}