#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int a, b, c;
    long long temp1, temp2, temp3;
    scanf("%d %d %d", &a, &b, &c);

    if (c == 0)
    {
        // Special case: factor x^3 + ax^2 + bx into x(x + p)(x + q)
        if (b == 0)
        {
            if (a >= 0)
                printf("0 0 %d\n", a); // Factors are 0, 0, and a
            else
                printf("%d 0 0\n", a); // Negative a
            exit(0);
        }

        temp1 = 0;
        for (int j = 1; j * j <= abs(b); j++)
        {
            if (b % j == 0)
            {
                int factors[] = {0, j, b / j};

                // Try both positive and negative factors
                for (int sign = -1; sign <= 1; sign += 2)
                {
                    factors[1] *= sign;
                    factors[2] = b / factors[1];

                    if (factors[1] + factors[2] == a)
                    {
                        qsort(factors, 3, sizeof(int), compare);
                        printf("%d %d %d\n", factors[0], factors[1], factors[2]);
                        exit(0);
                    }
                    factors[1] = j; // Reset factor for next iteration
                }
            }
        }
    }

    // General case for non-zero c
    for (int i = 1; i * i <= abs(c); i++)
    {
        if (c % i == 0)
        {
            int possible_factors[] = {i, -i, c / i, -(c / i)};

            for (int f1 = 0; f1 < 4; f1++)
            {
                temp1 = possible_factors[f1];

                for (int j = 1; j * j <= llabs(c / temp1); j++)
                {
                    if ((c / temp1) % j == 0)
                    {
                        int factors[] = {temp1, j, (c / temp1) / j};

                        // Try both positive and negative for j
                        for (int sign = -1; sign <= 1; sign += 2)
                        {
                            factors[1] *= sign;
                            factors[2] = (c / temp1) / factors[1];

                            // Check if factorization conditions hold
                            if (factors[0] + factors[1] + factors[2] == a &&
                                factors[0] * factors[1] + factors[0] * factors[2] + factors[1] * factors[2] == (long long)b)
                            {
                                qsort(factors, 3, sizeof(int), compare);
                                printf("%d %d %d\n", factors[0], factors[1], factors[2]);
                                exit(0);
                            }
                            factors[1] = j; // Reset factor for next iteration
                        }
                    }
                }
            }
        }
    }

    // If no factorization found, print nothing or handle the error accordingly
    printf("No factorization found\n");
    return 0;
}
