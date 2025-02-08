#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int height[n];
    for (int i = 0; i < n; i++)
        height[i] = 0;
    int a, b;
    int type[4][3] = {{-1, 0, 0}, {0, 0, -1}, {0, 0, 0}, {-1, 0, -1}};
    int extra_height[4][3][3] = {{{2, 2, 1}, {2, 2, 1}, {2, 2, 1}}, {{1, 2, 2}, {1, 2, 2}, {1, 2, 2}}, {{1, 2, 1}, {1, 2, 1}, {1, 2, 1}}, {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}};
    while (scanf("%d%d", &a, &b) != EOF)
    {
        int stuck_pos = 0;
        int max_height = -2;
        for (int i = a; i < a + 3; i++)
        {
            if (height[i] + type[b][i - a] > max_height)
            {
                stuck_pos = i;
                max_height = height[i] + type[b][i - a];
            }
        }
        // stuck_pos - a = stuck in which block from left to right
        for (int i = a; i < a + 3; i++)
        {
            height[i] = max_height;
            height[i] += extra_height[b][stuck_pos - a][i - a];
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", height[i]);
}