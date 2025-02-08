#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int cmp(const void *t1, const void *t2)
{
    return strcmp(*(char **)t1, *(char **)t2);
}
 
int main()
{
    char str[501];
    scanf("%s", str);
    int len = strlen(str);
    char *arr[500000];
    int count = 0;
    for (int start = 0; start < len; start++)
        for (int end = start; end < len; end++)
        {
            char *tmp = (char *)malloc((end - start + 2) * sizeof(char));
            strncpy(tmp, &(str[start]), end - start + 1);
            tmp[end - start + 1] = '\0';
            int same = 0;
            for (int i = 0; i < count; i++)
                if (arr[i][0] != tmp[0])
                    continue;
                else if (strcmp(tmp, arr[i]) == 0)
                {
                    same = 1;
                    break;
                }
            if (same)
            {
                free(tmp);
                continue;
            }
            arr[count] = tmp;
            count++;
        }
    qsort(arr, count, sizeof(char *), cmp);
    for (int i = 0; i < count; i++)
        printf("%s\n", arr[i]);
}