#include <stdio.h>

int main()
{
    int x[2], y[2], r[2];
    scanf("%d%d%d%d%d%d", &x[0], &y[0], &r[0], &x[1], &y[1], &r[1]);
    int x_in, y_in;
    while (scanf("%d%d", &x_in, &y_in) != EOF)
    {
        int state[2] = {0};
        for (int i = 0; i < 2; i++)
        {
            if ((x_in - x[i]) * (x_in - x[i]) + (y_in - y[i]) * (y_in - y[i]) > r[i] * r[i])
                state[i] = -1;
            else if ((x_in - x[i]) * (x_in - x[i]) + (y_in - y[i]) * (y_in - y[i]) < r[i] * r[i])
                state[i] = 1;
        }
        if (state[0] == 1 || state[1] == 1)
            printf("In\n");
        else if (state[0] == 0 || state[1] == 0)
            printf("On\n");
        else
            printf("Out\n");
    }
}