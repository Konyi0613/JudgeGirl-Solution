#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    char fuse[128] = {}, input[128];
    int flag;
    while (scanf("%s", input) != EOF)
    {
        int length = strlen(fuse);
        for (flag = 0; flag < length; flag++)
        {
            if (strncmp(&(fuse[flag]), input, length - flag) == 0)
                break;
        }
        strcpy(&(fuse[flag]), input);
    }
    printf("%s", fuse);
    return 0;
}