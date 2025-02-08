#include <stdio.h>

int main()
{
    int max_digit_sum = 0, max_digit_num, max_value;
    int input;
    while (scanf("%d", &input) != EOF)
    {
        int now_digit_sum = 0, now_digit_num = 0, now_value = input;
        while (input != 0)
        {
            now_digit_sum += input % 10;
            now_digit_num++;
            input /= 10;
        }
        if (now_digit_sum > max_digit_sum || (now_digit_sum == max_digit_sum && (now_digit_num < max_digit_num || (now_digit_num == max_digit_num && now_value > max_value))))
        {
            max_digit_sum = now_digit_sum;
            max_digit_num = now_digit_num;
            max_value = now_value;
        }
    }
    printf("%d", max_value);
}