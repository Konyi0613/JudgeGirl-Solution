#include <stdio.h>
#include <ctype.h>

int main()
{
    char input, output[100];
    int status = 0, count = 0;
    int detect[100] = {0};
    while (scanf("%c", &input) != EOF)
    {
        if (isspace(input))
            detect[count] = 1;
        if (input == '\n')
            detect[count] = 2;
        output[count] = input;
        count++;
    }
    int det = 0;
    while (detect[det] == 1)
    {
        detect[det] = -1;
        det++;
    }
    for (int i = 0; i < count; i++)
    {
        if (detect[i] == 2)
        {
            int k = 1;
            while (i - k >= 0 && detect[i - k] == 1)
            {
                detect[i - k] = -1;
                k++;
            }
            k = 1;
            while (i + k < count && detect[i + k] == 1)
            {
                detect[i + k] = -1;
                k++;
            }
        }
    }
    /*det = count - 1;
    while (detect[det] == 1)
    {
        detect[det] = -1;
        det--;
    }*/
    for (int i = 0; i < count; i++)
    {
        if (detect[i] != -1)
            printf("%c", output[i]);
    }
    return 0;
}