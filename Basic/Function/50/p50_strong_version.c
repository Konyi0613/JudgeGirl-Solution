#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int calculate_area(int x1, int y1, int x2, int y2)
{
    return (abs(x2 - x1) * abs(y2 - y1));
}
int middle2(int x1, int x2, int x3, int x4, int operator)
{

    int x[4] = {x1, x2, x3, x4};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (x[j] > x[j + 1])
            {
                int tmp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = tmp;
            }
        }
    }
    if (operator== 1)
        return x[2];
    else
        return x[1];
}
int covered_area(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int op)
{
    if ((x2 - x3) * (x1 - x4) >= 0 || (y2 - y3) * (y1 - y4) >= 0)
        return 0;
    int lbx, lby, rtx, rty;
    lbx = middle2(x1, x2, x3, x4, 0);
    rtx = middle2(x1, x2, x3, x4, 1);
    lby = middle2(y1, y2, y3, y4, 0);
    rty = middle2(y1, y2, y3, y4, 1);
    int area = calculate_area(lbx, lby, rtx, rty);
    if (op == 0)
        return area;
    else if (op == 1)
        return lbx;
    else if (op == 2)
        return lby;
    else if (op == 3)
        return rtx;
    else
        return rty;
}
int main()
{
    int bt_left_x[3];
    int bt_left_y[3];
    int top_right_x[3];
    int top_right_y[3];
    int area[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d%d%d%d", &bt_left_x[i], &bt_left_y[i], &top_right_x[i], &top_right_y[i]);
        area[i] = calculate_area(bt_left_x[i], bt_left_y[i], top_right_x[i], top_right_y[i]);
    }
    int area01 = 0, area02 = 0, area12 = 0, area123 = 0;
    area01 = covered_area(bt_left_x[0], bt_left_y[0], top_right_x[0], top_right_y[0], bt_left_x[1], bt_left_y[1], top_right_x[1], top_right_y[1], 0);
    area02 = covered_area(bt_left_x[0], bt_left_y[0], top_right_x[0], top_right_y[0], bt_left_x[2], bt_left_y[2], top_right_x[2], top_right_y[2], 0);
    area12 = covered_area(bt_left_x[1], bt_left_y[1], top_right_x[1], top_right_y[1], bt_left_x[2], bt_left_y[2], top_right_x[2], top_right_y[2], 0);
    if (area01 != 0)
    {
        int lbx01 = covered_area(bt_left_x[0], bt_left_y[0], top_right_x[0], top_right_y[0], bt_left_x[1], bt_left_y[1], top_right_x[1], top_right_y[1], 1);
        int lby01 = covered_area(bt_left_x[0], bt_left_y[0], top_right_x[0], top_right_y[0], bt_left_x[1], bt_left_y[1], top_right_x[1], top_right_y[1], 2);
        int tpx01 = covered_area(bt_left_x[0], bt_left_y[0], top_right_x[0], top_right_y[0], bt_left_x[1], bt_left_y[1], top_right_x[1], top_right_y[1], 3);
        int tpy01 = covered_area(bt_left_x[0], bt_left_y[0], top_right_x[0], top_right_y[0], bt_left_x[1], bt_left_y[1], top_right_x[1], top_right_y[1], 4);
        area123 = covered_area(lbx01, lby01, tpx01, tpy01, bt_left_x[2], bt_left_y[2], top_right_x[2], top_right_y[2], 0);
        int total_area = area[0] + area[1] + area[2] - area01 - area02 - area12 + area123;
        printf("%d", total_area);
    }
    else
    {
        printf("%d", area[0] + area[1] + area[2] - area02 - area12);
    }
}