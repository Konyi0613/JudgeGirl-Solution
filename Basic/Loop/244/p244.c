#include <stdio.h>
#include <math.h>

int main()
{
    int special_prize[3] = {0};
    int first_prize[3] = {0};
    int number;
    int dollars = 0;
    int i = 0;
    while (scanf("%d", &number) != EOF)
    {
        if (i <= 2)
        {
            special_prize[i] = number;
            i++;
        }
        else if (3 <= i && i <= 5)
        {
            first_prize[i - 3] = number;
            i++;
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                if (number == special_prize[j])
                {
                    // printf("%d == %d\n", number, first_prize[j]);
                    dollars += 2000000;
                }
            }
            for (int j = 0; j < 3; j++)
            {
                for (int k = 8; k >= 3; k--)
                {
                    if (number % (int)pow(10, k) == first_prize[j] % (int)pow(10, k))
                    {
                        if (k == 8)
                        {
                            dollars += 200000;
                            break;
                        }
                        else if (k == 7)
                        {
                            dollars += 40000;
                            break;
                        }
                        else if (k == 6)
                        {
                            dollars += 10000;
                            break;
                        }
                        else if (k == 5)
                        {
                            dollars += 4000;
                            break;
                        }
                        else if (k == 4)
                        {
                            dollars += 1000;
                            break;
                        }
                        else if (k == 3)
                        {
                            dollars += 200;
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("%d", dollars);
}