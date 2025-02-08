#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void snake(int *first_element, int n, int *pointers[], int m)
{
    for (int i = 1; i < m; i++)
    {
        if (pointers[i] == NULL)
            return;
        if (pointers[i] - first_element > n * n - 1 || pointers[i] - first_element < 0)
            return;
        else
        {
            int location1 = pointers[i] - first_element;
            int location2 = pointers[i - 1] - first_element;
            int *small = pointers[i];
            if (location1 > location2)
            {
                int tmp = location1;
                location1 = location2;
                location2 = tmp;
                small = pointers[i - 1];
            }
            if (location1 / n == location2 / n)
            {
                for (int j = 0; j < location2 - location1 + 1; j++)
                {
                    *(small + j) = 1;
                }
            }
            else if (location1 % n == location2 % n)
            {
                for (int j = 0; j < (location2 - location1) / n + 1; j++)
                {
                    *(small + n * j) = 1;
                }
            }
            else if (abs(location1 / n - location2 / n) == abs(location1 % n - location2 % n))
            {
                if (location1 % n > location2 % n)
                {
                    for (int j = 0; j < location1 % n - location2 % n + 1; j++)
                    {
                        *(small + n * j - j) = 1;
                    }
                }
                else
                {
                    for (int j = 0; j < location2 % n - location1 % n + 1; j++)
                    {
                        *(small + n * j + j) = 1;
                    }
                }
            }
            else
                return;
        }
    }
}