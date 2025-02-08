#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int pre_num, now_num, max_con = 0, now_con[2] = {0, 0};
    scanf("%d", &pre_num);
    int pre_line = 0, now_line = 0; // 0 = down, 1 = up
    int num[2];                     // num[0] down, num[1] up
    num[0] = pre_num;
    bool first = true;
    for (int step = 0; step < n * (2 * a - b); step++)
    {
        if (step == 0)
        {
            now_num = num[0];
        }
        else
        {
            scanf("%d", &now_num);
        }
        int location = step % (2 * a - b);
        if (num[now_line] == now_num && (now_line == 0 || (now_line == 1 && location != b + 1)))
        {
            now_con[now_line]++;
            if (first == true && location <= b)
            {
                max_con++;
            }
            else
                first = false;
        }
        else
        {
            if (now_con[now_line] > max_con)
            {
                max_con = now_con[now_line];
            }
            first = false;
            now_con[now_line] = 1;
            num[now_line] = now_num;
        }
        int temp = now_line;
        // printf("%d %d\n", now_con[0],now_con[1]);
        // printf("%d ", now_line);
        if (((location - b) % 2 == 0 && location >= b))
        {
            now_line = (now_line == 0) ? 1 : 0;
            pre_line = temp;
        }
        else
            pre_line = now_line;
        if (step == n * (2 * a - b) - 1 && (now_con[0] > max_con || now_con[1] > max_con))
        {
            max_con = (now_con[0] > now_con[1]) ? now_con[0] : now_con[1];
        }
    }
    printf("%d", max_con);
}