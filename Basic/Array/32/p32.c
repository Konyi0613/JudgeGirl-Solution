#include <stdio.h>
#include <stdbool.h>
int main()
{
    int a[100];
    int n;
    int length = 0;
    while (scanf("%d", &n) != EOF)
    {
        a[length] = n;
        length++;
    }
    int palindrome_count = 0;
    int max_db_palindrome = 0;
    int palin_length[2] = {0}; // 0 for left, 1 for right
    int head = 0;
    int tail = length - 1;
    int *left = &a[0];
    int *right = &a[length - 1];
    int max_head = 0;
    int max_tail = length - 1;
    int step = 0;
    int type = 0;
    while (head != length - 1)
    {
        // printf("%d", palindrome_count);
        while (*left != *right)
            right--;
        head = left - &a[0];
        tail = right - &a[0];
        int palindrome_length = right - left + 1;
        bool palindrome = true;
        for (int i = 0; i < palindrome_length / 2; i++)
        {
            if (a[head + i] != a[tail - i])
            {
                palindrome = false;
                break;
            }
        }
        if (palindrome)
        {
            if (palindrome_count == 0)
                palin_length[0] = palindrome_length;
            else // palinfrome_count == 1
                palin_length[1] = palindrome_length;
            palindrome_count++;
        }
        else
        {
            right--;
            continue;
        }
        if (palindrome_count == 2 && (max_db_palindrome == 0 || palin_length[0] + palin_length[1] >= max_db_palindrome))
        {
            max_db_palindrome = palin_length[0] + palin_length[1];
            max_head = head - palin_length[0];
            max_tail = tail;
        }
        // change right and left
        if (palindrome_count == 2) // change to 1
        {
            if (type == 0)
            {
                left = &a[step];
                right = &a[step];
                palindrome_count = 0;
                type++;
            }
            else
            {
                step++;
                left = &a[step];
                right = &a[length - 1];
                palindrome_count = 0;
                type = 0;
            }
        }
        else
        {
            right = &a[length - 1];
            if (tail == length - 1)
            {
                left = &a[length - 1];
                break;
            }
            else
                left = &a[tail + 1];
        }
        // printf("%d", palindrome_count);
    }
    // printf("%d %d\n", max_head, max_tail);
    printf("%d", a[max_head]);
    for (int i = max_head + 1; i <= max_tail; i++)
        printf(" %d", a[i]);
}