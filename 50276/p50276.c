#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    char grid[n * n];
    int i = 0;
    while (i < n * n)
    {
        char a;
        scanf("%c", &a);
        if (a != '\n')
        {
            grid[i] = a;
            i++;
        }
    }
    int end[2];
    int end_counter = 0;
    for (int i = 0; i < n * n; i++)
    {
        if (grid[i] == '0')
            continue;
        int neighbor = 0;
        if ((i / n) > 0 && grid[(i / n - 1) * n + (i % n)] != '0')
            neighbor++;
        if ((i / n) < n - 1 && grid[(i / n + 1) * n + (i % n)] != '0')
            neighbor++;
        if ((i % n) > 0 && grid[i - 1] != '0')
            neighbor++;
        if ((i % n) < n - 1 && grid[i + 1] != '0')
            neighbor++;
        if (neighbor == 1)
        {
            end[end_counter] = i;
            end_counter++;
        }
    }
    if (grid[end[0]] > grid[end[1]] || (grid[end[0]] == grid[end[1]] && (end[0] / n > end[1] / n || (end[0] / n == end[1] / n && end[0] % n > end[1] % n))))
    {
        int tmp = end[0];
        end[0] = end[1];
        end[1] = tmp;
    }
    int pos = end[0];
    while(pos != end[1])
    {
        printf("%c", grid[pos]);
        grid[pos] = '0';
        if (pos / n > 0 && grid[(pos / n - 1) * n + pos % n] != '0')
            pos = (pos / n - 1) * n + pos % n;
        else if (pos / n < n - 1 && grid[(pos / n + 1) * n + pos % n] != '0')
            pos = (pos / n + 1) * n + pos % n;
        else if (pos % n > 0 && grid[pos - 1] != '0')
            pos = pos - 1;
        else if (pos % n < n - 1 && grid[pos + 1] != '0')
            pos = pos + 1;
    }
    printf("%c", grid[end[1]]);
}