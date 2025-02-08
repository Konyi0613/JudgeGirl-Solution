#include <stdio.h>
#include <stdbool.h>

int main()
{
    int add = 0;
    int mult = 1;
    bool multi = false;
    int n;
    int temp = 0;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            if (multi)
            {
                mult *= temp;
                add += mult;
            }
            else
            {
                add += temp;
            }
            break;
        }
        if (n == 8 && !multi)
        {
            add += temp;
            temp = 0;
            continue;
        }
        else if (n == 8 && multi)
        {
            multi = false;
            mult *= temp;
            add += mult;
            mult = 1;
            temp = 0;
            continue;
        }
        if (n == 9)
        {
            multi = true;
            mult *= temp;
            temp = 0;
            continue;
        }
        temp *= 10;
        temp += n;
    }
    printf("%d", add);
}