#include <stdio.h>
#include <math.h>
int main()
{
    int n,x1,y1,x2,y2,x3,y3;
    int len1,len2,len3;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        len1 = pow((x1-x2),2)+pow((y1-y2),2);
        len2 = pow((x1-x3),2)+pow((y1-y3),2);
        len3 = pow((x2-x3),2)+pow((y2-y3),2);
        if(len1 == len2 || len1 == len3 || len2 == len3)
        printf("isosceles");
        else
        {
            int temp;
            if(len1 > len2)
            {
            temp = len2;
            len2 = len1;
            len1 = temp;
            }
            if(len2 > len3)
            {
            temp = len3;
            len3 = len2;
            len2 = temp;
            }
            if(len1 + len2 > len3)
            printf("acute");
            else if(len1 + len2 < len3)
            printf("obtuse");
            else
            printf("right");
        }
        printf("\n");
    }
}