#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n;
    scanf("%d", &n);
    // first, now, max
    int first_power = 0, first_sum = 0, now_power = 0, now_sum = 0, max_power = 0, max_sum = 0;
    scanf("%d", &first_power);
    first_sum += first_power;
    now_power = first_power;
    now_sum = first_power;
    max_power = first_power;
    max_sum = first_sum;
    bool first_group = true;
    for (int i = 1; i < n; i++)
    {
        int new_power;
        scanf("%d", &new_power);
        if (first_group)
        {
            if (new_power == first_power)
            {
                first_sum += first_power;
                now_sum += first_power;
                max_sum += first_power;
                continue;
            }
            else
            {
                now_power = new_power;
                now_sum = new_power;
                first_group = false;
                continue;
            }
        }
        if (new_power == now_power)
            now_sum += now_power;
        else
        {
            if (now_sum >= max_sum)
            {
                if (now_sum == max_sum)
                {
                    if (now_power < max_power)
                        max_power = now_power;
                }
                else
                {
                    max_sum = now_sum;
                    max_power = now_power;
                }
            }
            now_power = new_power;
            now_sum = now_power;
        }
    }
    if (now_power == first_power)
        now_sum += first_sum;
    if (now_sum >= max_sum)
    {
        if (now_sum == max_sum)
        {
            if (now_power < max_power)
                max_power = now_power;
        }
        else
        {
            max_sum = now_sum;
            max_power = now_power;
        }
    }
    if (now_power != first_power)
    {
        if (first_sum == max_sum)
        {
            if (first_power < max_power)
                max_power = first_power;
        }
        else if (first_sum > max_sum)
        {
            max_sum = first_sum;
            max_power = first_power;
        }
    }
    if (first_group == true)
    {
        printf("%d %d", first_power, first_sum / first_power);
        return 0;
    }
    printf("%d %d", max_power, max_sum / max_power);
}