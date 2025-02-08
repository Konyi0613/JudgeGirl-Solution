#include <stdio.h>
#include <stdbool.h>
#define swap(x1, y1, x2, y2, x3, y3, x4, y4) \
    int tmp = x1;                            \
    x1 = x3;                                 \
    x3 = tmp;                                \
    tmp = y1;                                \
    y1 = y3;                                 \
    y3 = tmp;                                \
    tmp = x2;                                \
    x2 = x4;                                 \
    x4 = tmp;                                \
    tmp = y2;                                \
    y2 = y4;                                 \
    y4 = tmp;
int calculate_area(int x1, int y1, int x2, int y2)
{
    return ((x2 - x1) * (y2 - y1));
}
int covered_area(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int operator)
{
    int lbx, lby, tpx, tpy, width, height;
    if (!(x3 <= x2 && x4 >= x1 && y3 <= y2 && y4 >= y1))
        return 0;
    if (x4 < x2)
    {
        // swap x1,y1 with x3,y3
        // swap x2,y2 with x4,y4
        swap(x1, y1, x2, y2, x3, y3, x4, y4)
    }
    if (x3 >= x1 && y4 >= y2 && y3 >= y1)
    {
        // type 1
        lbx = x3;
        lby = y3;
        tpx = x2;
        tpy = y2;
    }
    else if (x3 >= x1 && y4 <= y2 && y3 <= y1)
    {
        // type 2
        lbx = x3;
        lby = y1;
        tpx = x2;
        tpy = y4;
    }
    else if (x3 <= x1 && y4 <= y2 && y3 <= y1)
    {
        // type 3
        lbx = x1;
        lby = y1;
        tpx = x2;
        tpy = y4;
    }
    else if (x3 <= x1 && y4 >= y2 && y3 >= y1)
    {
        // type 4
        lbx = x1;
        lby = y3;
        tpx = x2;
        tpy = y2;
    }
    else if (x3 >= x1 && y4 <= y2 && y3 >= y1)
    {
        // type 5
        lbx = x3;
        lby = y3;
        tpx = x2;
        tpy = y4;
    }
    else if (x3 >= x1 && y4 >= y2 && y3 <= y1)
    {
        // type 6
        lbx = x3;
        lby = y1;
        tpx = x2;
        tpy = y2;
    }
    else if (x3 <= x1 && y4 >= y2 && y3 <= y1)
    {
        // type 7
        lbx = x1;
        lby = y1;
        tpx = x2;
        tpy = y2;
    }
    else
    {
        // type8 penetrate
        lbx = x1;
        lby = y3;
        tpx = x2;
        tpy = y4;
    }
    int area = calculate_area(lbx, lby, tpx, tpy);
    if (operator== 0)
        return area;
    else if (operator== 1)
        return lbx;
    else if (operator== 2)
        return lby;
    else if (operator== 3)
        return tpx;
    else if (operator== 4)
        return tpy;
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
    int area01, area02, area12, area123;
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