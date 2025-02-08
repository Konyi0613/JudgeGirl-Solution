#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int cross(int x1,int y1, int x2, int y2)
{
    return (x1*y2-x2*y1);
}
int main()
{
    //input n
    //input x1,y1,x2,y2,x3,y3,x4,y4
    //以v1為基準點依順逆排序
    //看直角

    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
    int x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4;
    scanf("%d%d%d%d%d%d%d%d",&x_1,&y_1,&x_2,&y_2,&x_3,&y_3,&x_4,&y_4);
    if(cross(x_2-x_1, y_2-y_1, x_3-x_1, y_3-y_1)>0)
    {
        if(cross(x_3-x_1, y_3-y_1, x_4-x_1, y_4-y_1)<0)
        {
            if(cross(x_2-x_1, y_2-y_1, x_4-x_1, y_4-y_1)>0)
            {
                int temp;
                temp = x_3;
                x_3 = x_4;
                x_4 = temp;
                temp = y_3;
                y_3 = y_4;
                y_4 = temp;
            }
            else
            {
                int temp;
                temp = x_3;
                x_3 = x_4;
                x_4 = temp;
                temp = y_3;
                y_3 = y_4;
                y_4 = temp;
                temp = x_2;
                x_2 = x_3;
                x_3 = temp;
                temp = y_2;
                y_2 = y_3;
                y_3 = temp;
            }
        }
    }
    else
    {
        if(cross(x_3-x_1, y_3-y_1, x_4-x_1, y_4-y_1)<0)
        {
            int temp;
            temp = x_2;
            x_2 = x_4;
            x_4 = temp;
            temp = y_2;
            y_2 = y_4;
            y_4 = temp;
        }
        else
        {
            if(cross(x_4-x_1, y_4-y_1, x_2-x_1, y_2-y_1)>0)
            {
                int temp;
                temp = x_3;
                x_3 = x_2;
                x_2 = temp;
                temp = y_3;
                y_3 = y_2;
                y_2 = temp;
                temp = x_3;
                x_3 = x_4;
                x_4 = temp;
                temp = y_3;
                y_3 = y_4;
                y_4 = temp;
            }
            else
            {
                int temp;
                temp = x_3;
                x_3 = x_2;
                x_2 = temp;
                temp = y_3;
                y_3 = y_2;
                y_2 = temp;
            }
        }
    }
    
    /*printf("%d %d %d %d %d %d %d %d\n",x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4);*/
    
    bool four_length_equal = false;
    bool four_right_angle = false;
    if(pow((x_2-x_1),2)+pow((y_2-y_1),2) == pow((x_2-x_3),2)+pow((y_2-y_3),2) && pow((x_2-x_1),2)+pow((y_2-y_1),2) == pow((x_4-x_3),2)+pow((y_4-y_3),2) && pow((x_2-x_1),2)+pow((y_2-y_1),2) == pow((x_4-x_1),2)+pow((y_4-y_1),2))
    {
        four_length_equal = true;
    }
    if(pow((x_2-x_1),2)+pow((y_2-y_1),2) + pow((x_2-x_3),2)+pow((y_2-y_3),2) == pow((x_3-x_1),2) + pow((y_3-y_1),2) &&
       pow((x_2-x_3),2)+pow((y_2-y_3),2) + pow((x_4-x_3),2)+pow((y_4-y_3),2) == pow((x_4-x_2),2) + pow((y_4-y_2),2) &&
       pow((x_3-x_4),2)+pow((y_3-y_4),2) + pow((x_4-x_1),2)+pow((y_4-y_1),2) == pow((x_3-x_1),2) + pow((y_3-y_1),2) &&
       pow((x_1-x_4),2)+pow((y_1-y_4),2) + pow((x_2-x_1),2)+pow((y_2-y_1),2) == pow((x_2-x_4),2) + pow((y_2-y_4),2))
    {
        four_right_angle = true;
    }
    if(four_length_equal == true)
    {
        if(four_right_angle == true)
            printf("square");
        else
            printf("diamond");
    }
    else
    {
        if(four_right_angle == true)
            printf("rectangle");
        else
            printf("other");
    }
    printf("\n");
    }
    
    
}