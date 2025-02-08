#include <stdio.h>
void insert(int n, int m, int x, int y, int direction)
{
    if (n == 2 && m == 1)
    {
        printf("%d %d %d\n", direction, x, y);
        return;
    }
    switch (direction)
    {
    case 1:
        insert(n / 2, m / 2, x, y, 1);
        insert(n / 2, m / 2, x + m / 2, y - m / 2, 2);
        insert(n / 2, m / 2, x - m / 2, y - m / 2, 1);
        insert(n / 2, m / 2, x - m / 2, y + m / 2, 3);
        break;
    case 2:
        insert(n / 2, m / 2, x, y, 2);
        insert(n / 2, m / 2, x + m / 2, y - m / 2, 2);
        insert(n / 2, m / 2, x + m / 2, y + m / 2, 4);
        insert(n / 2, m / 2, x - m / 2, y - m / 2, 1);
        break;
    case 3:
        insert(n / 2, m / 2, x, y, 3);
        insert(n / 2, m / 2, x + m / 2, y + m / 2, 4);
        insert(n / 2, m / 2, x - m / 2, y + m / 2, 3);
        insert(n / 2, m / 2, x - m / 2, y - m / 2, 1);
        break;
    case 4:
        insert(n / 2, m / 2, x, y, 4);
        insert(n / 2, m / 2, x - m / 2, y + m / 2, 3);
        insert(n / 2, m / 2, x + m / 2, y - m / 2, 2);
        insert(n / 2, m / 2, x + m / 2, y + m / 2, 4);
        break;
    }
}

void fill_hole(int L, int hole_x, int hole_y, int now_Ox, int now_Oy)
{
    // Sprintf("L: %d hole_x: %d hole_y: %d\n", L, hole_x, hole_y);
    if (L == 1)
        return;
    int direction, L_x, L_y, new_Ox, new_Oy;
    if (hole_x < L / 2 && hole_y < L / 2)
    {
        direction = 4;
        new_Ox = now_Ox + 0;
        new_Oy = now_Oy + 0;
    }
    else if (hole_x >= L / 2 && hole_y < L / 2)
    {
        direction = 3;
        new_Ox = now_Ox + L / 2;
        new_Oy = now_Oy + 0;
    }
    else if (hole_x >= L / 2 && hole_y >= L / 2)
    {
        direction = 1;
        new_Ox = now_Ox + L / 2;
        new_Oy = now_Oy + L / 2;
    }
    else
    {
        direction = 2;
        new_Ox = now_Ox + 0;
        new_Oy = now_Oy + L / 2;
    }
    L_x = now_Ox + L / 2;
    L_y = now_Oy + L / 2;
    insert(L, L / 2, L_x, L_y, direction);
    fill_hole(L / 2, hole_x - (new_Ox - now_Ox), hole_y - (new_Oy - now_Oy), new_Ox, new_Oy);
}
int main()
{
    int L, hole_x, hole_y;
    scanf("%d%d%d", &L, &hole_x, &hole_y);
    fill_hole(L, hole_x, hole_y, 0, 0);
}