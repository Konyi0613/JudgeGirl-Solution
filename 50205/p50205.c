#include <stdio.h>
#include <string.h>
int main()
{
    char symbol[] = {')', '!', '@', '#', '$', '%', '^', '&', 'n', '('};
    int sum = 0, multiple = 1, is_mul = -1;
    char now;
    int now_num = 0;
    while (scanf("%c", &now) != EOF)
    {
        if (now == ' ' || now == '\n')
            break;
        if (now == '+')
            if (is_mul == -1)
            {
                sum += now_num;
                now_num = 0;
            }
            else
            {
                multiple *= now_num;
                sum += multiple;
                is_mul = -1;
                multiple = 1;
                now_num = 0;
            }
        else if (now == '*')
        {
            is_mul = 1;
            multiple *= now_num;
            now_num = 0;
        }
        else
        {
            int id = 0;
            for (int i = 0; i <= 9; i++)
                if (symbol[i] == now)
                {
                    id = i;
                    break;
                }
            now_num = now_num * 10 + id;
        }
    }
    if (is_mul == 1)
        sum += (now_num * multiple);
    else
        sum += now_num;
    printf("%d", sum);
}