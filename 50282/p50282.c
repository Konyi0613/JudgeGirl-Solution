#include <stdio.h>
#include <stdbool.h>

void fill_brick(int l, int l_x, int l_y, int l_z, int direction)
{
    if (l == 2)
    {
        printf("%d %d %d %d\n", direction, l_x, l_y, l_z);
        return;
    }
    fill_brick(l / 2, l_x, l_y, l_z, direction);
    if (direction != 3)
        fill_brick(l / 2, l_x + l / 4, l_y - l / 4, l_z + l / 4, 6);
    if (direction != 4)
        fill_brick(l / 2, l_x - l / 4, l_y - l / 4, l_z + l / 4, 5);
    if (direction != 2)
        fill_brick(l / 2, l_x - l / 4, l_y + l / 4, l_z + l / 4, 7);
    if (direction != 7)
        fill_brick(l / 2, l_x + l / 4, l_y - l / 4, l_z - l / 4, 2);
    if (direction != 8)
        fill_brick(l / 2, l_x - l / 4, l_y - l / 4, l_z - l / 4, 1);
    if (direction != 5)
        fill_brick(l / 2, l_x + l / 4, l_y + l / 4, l_z - l / 4, 4);
    if (direction != 6)
        fill_brick(l / 2, l_x - l / 4, l_y + l / 4, l_z - l / 4, 3);
    if (direction != 1)
        fill_brick(l / 2, l_x + l / 4, l_y + l / 4, l_z + l / 4, 8);
    return;
}

void fill_hole(int l, int hole_x, int hole_y, int hole_z, int x_d, int y_d, int z_d, int direction, int Ox, int Oy, int Oz)
{
    int l_x = Ox + l / 2;
    int l_y = Oy + l / 2;
    int l_z = Oz + l / 2;
    fill_brick(l, l_x, l_y, l_z, direction);
    if (l == 2)
        return;
    int new_Ox = Ox + (l / 2) * x_d;
    int new_Oy = Oy + (l / 2) * y_d;
    int new_Oz = Oz + (l / 2) * z_d;
    int relative_x = hole_x - new_Ox;
    int relative_y = hole_y - new_Oy;
    int relative_z = hole_z - new_Oz;
    int new_x_d = (relative_x >= (l / 4));
    int new_y_d = (relative_y >= (l / 4));
    int new_z_d = (relative_z >= (l / 4));
    int new_direction = 8 - (new_z_d * 4 + new_y_d * 2 + new_x_d);
    fill_hole(l / 2, hole_x, hole_y, hole_z, new_x_d, new_y_d, new_z_d, new_direction, new_Ox, new_Oy, new_Oz);
    return;
}

int main()
{
    int l;
    scanf("%d", &l);
    int hole_x, hole_y, hole_z;
    scanf("%d%d%d", &hole_x, &hole_y, &hole_z);
    int x_d = (hole_x >= (l / 2));
    int y_d = (hole_y >= (l / 2));
    int z_d = (hole_z >= (l / 2));
    int direction = 8 - (z_d * 4 + y_d * 2 + x_d);
    fill_hole(l, hole_x, hole_y, hole_z, x_d, y_d, z_d, direction, 0, 0, 0);
}