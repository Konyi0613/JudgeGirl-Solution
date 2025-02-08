#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char A[n];
    for (int i = 0; i < n; i++)
        A[i] = '\0';
    char *string;
    int pos;
    for (int i = 0; i < m; i++)
    {
        string = (char *)malloc(51 * sizeof(char));
        scanf("%s", string);
        scanf("%d", &pos);
        int len = strlen(string);
        for (int i = 0; i < len; i++)
        {
            if (A[pos + i] == '\0')
                A[pos + i] = string[i];
            else
                A[pos + i] = (A[pos + i] + string[i]) / 2;
        }
    }
    for (int i = 0; i < n - 1; i++)
        if (A[i] == '\0')
            A[i] = ' ';
    printf("%s", A);
}