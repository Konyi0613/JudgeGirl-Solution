#include <stdio.h>

void insert(int n, int m, int x, int y, int direction)
{
    if (n == 2 && m == 1)
    {
        printf("%d %d %d\n", direction, x, y);
        return;
    }

    if (n != m * 2)
    {
        insert(m * 2, m, x, y, 1);
        insert(n, m * 2, x - m, y - m, 1);
        return;
    }

    switch (direction)
    {
    case 1:
        insert(n / 2, m / 2, x, y, 1);
        insert(n / 2, m / 2, x + m / 2, y - m / 2, 2);
        insert(n / 2, m / 2, x - m / 2, y - m / 2, 1);
        insert(n / 2, m / 2, x - m / 2, y + m / 2, 4);
        break;
    case 2:
        insert(n / 2, m / 2, x, y, 2);
        insert(n / 2, m / 2, x + m / 2, y - m / 2, 2);
        insert(n / 2, m / 2, x + m / 2, y + m / 2, 3);
        insert(n / 2, m / 2, x - m / 2, y - m / 2, 1);
        break;
    case 3:
        insert(n / 2, m / 2, x, y, 3);
        insert(n / 2, m / 2, x + m / 2, y + m / 2, 3);
        insert(n / 2, m / 2, x - m / 2, y + m / 2, 4);
        insert(n / 2, m / 2, x + m / 2, y - m / 2, 2);
        break;
    case 4:
        insert(n / 2, m / 2, x, y, 4);
        insert(n / 2, m / 2, x - m / 2, y + m / 2, 4);
        insert(n / 2, m / 2, x - m / 2, y - m / 2, 1);
        insert(n / 2, m / 2, x + m / 2, y + m / 2, 3);
        break;
    }
    return;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    insert(n, m, n - m, n - m, 1);
    return 0;
}