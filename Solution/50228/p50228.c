#include <stdio.h>
#include <stdint.h>
int main()
{
    int n;
    scanf("%d", &n);
    int input;
    scanf("%d", &input);
    int max_sum = input, max_num = 1, max_first = input;
    int now_sum = input, now_num = 1, now_first = input, dif = INT32_MAX, last = input;
    int first_group = 1;
    n--;
    while(n > 0)
    {
        n--;
        scanf("%d", &input);
        if (dif == INT32_MAX)
        {
            dif = input - last;
            max_sum += input;
            max_num++;
            now_sum += input;
            now_num++;
            last = input;
            continue;
        }
        if (input - last == dif)
        {
            if (first_group == 1)
            {
                max_sum += input;
                max_num++;
            }
            now_sum += input;
            now_num++;
        }
        else
        {
            if (first_group == 1)
                first_group = -1;
            else
                if (now_sum > max_sum || (now_sum == max_sum && (now_num > max_num || (now_num == max_num && now_first > max_first))))
                {
                    max_sum = now_sum;
                    max_num = now_num;
                    max_first = now_first;
                }
            now_sum = last + input;
            now_num = 2;
            now_first = last;
            dif = input - last;
        }
        last = input;
    }
    if (now_sum > max_sum || (now_sum == max_sum && (now_num > max_num || (now_num == max_num && now_first > max_first))))
    {
        max_sum = now_sum;
        max_num = now_num;
        max_first = now_first;
    }
    printf("%d %d %d", max_sum, max_num, max_first);
}