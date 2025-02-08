#include <stdio.h>

void SpiralSnake(int N, int *snake, int *result)
{
    int row = ((N * N) / 2) / N;
    int col = (N * N / 2) % N;
    result[row * N + col] = snake[0];
    int drow[4] = {0, -1, 0, 1};
    int dcol[4] = {-1, 0, 1, 0};
    int direct = 0;
    int step = 1;
    int step_count = 0;
    int counter = 1;
    while (counter < N * N)
    {
        if (step_count == 2)
        {
            step++;
            step_count = 0;
        }
        for (int j = 0; j < step && counter < N * N; j++)
        {
            row += drow[direct];
            col += dcol[direct];
            result[row * N + col] = snake[counter];
            counter++;
        }
        direct = (direct + 1) % 4;
        step_count++;
    }
    return;
}