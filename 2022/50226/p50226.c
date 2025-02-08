#include <stdio.h>
int lcm(int a, int b)
{
    int gcd;
    int tmp_a = a;
    int tmp_b = b;
    while (tmp_a % tmp_b != 0)
    {
        int temp = tmp_b;
        tmp_b = tmp_a % tmp_b;
        tmp_a = temp;
    }
    gcd = tmp_b;
    int l = a * b / gcd;
    return l;
}
int main()
{
    int counter = 0;
    int gear;
    int max;
    int new_lcm = 0, pre_lcm = 0;
    while (scanf("%d", &gear) != EOF)
    {
        if (counter == 0)
        {
            max = gear;
            pre_lcm = gear;
            counter++;
            continue;
        }
        else
        {
            new_lcm = lcm(gear, pre_lcm);
            pre_lcm = new_lcm;
            if (counter == 3)
            {
                printf("%d\n", pre_lcm / max);
                counter = 0;
            }
            else
            {
                counter++;
            }
        }
    }
}