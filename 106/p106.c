#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    while (true)
    {
        char number[1000];
        scanf("%s", number);
        char end[] = "-1";
        if (strcmp(number, end) == 0)
            break;
        int len = strlen(number);
        // printf("len: %d\n", len);
        // printf("last: %c\n", number[len - 1]);
        if ((number[len - 1] - '0') % 2 == 0)
            printf("yes ");
        else
            printf("no ");
        int even_sum = 0;
        int odd_sum = 0;
        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
                even_sum += (number[i] - '0');
            else
                odd_sum += (number[i] - '0');
        }
        int sum = even_sum + odd_sum;
        if (sum % 3 == 0)
            printf("yes ");
        else
            printf("no ");
        if ((number[len - 1] - '0') % 5 == 0)
            printf("yes ");
        else
            printf("no ");
        if ((odd_sum - even_sum) % 11 == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
}