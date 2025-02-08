#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Initialize variables
    int X, Y, x1, y1, x2, y2, dx1, dy1, dx2, dy2, sec;

    // Input: Box dimensions, initial positions, directions, and time
    scanf("%d%d%d%d%d%d%d%d%d%d%d", &X, &Y, &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &sec);

    // Simulate second by second
    for (int i = 0; i < sec; i++)
    {
        // Move both balls
        x1 += dx1;
        y1 += dy1;
        x2 += dx2;
        y2 += dy2;

        // Check for collisions between the two balls
        if (x1 == x2 && y1 == y2)
        {
            // Swap directions upon collision (but not when they exchange places)
            int temp_dx = dx1, temp_dy = dy1;
            dx1 = dx2;
            dy1 = dy2;
            dx2 = temp_dx;
            dy2 = temp_dy;
        }

        // Check if ball 1 hits the box boundaries
        if (x1 == 1 || x1 == X)
        {
            dx1 = -dx1; // Reverse x direction if it hits left/right wall
        }
        if (y1 == 1 || y1 == Y)
        {
            dy1 = -dy1; // Reverse y direction if it hits top/bottom wall
        }

        // Check if ball 2 hits the box boundaries
        if (x2 == 1 || x2 == X)
        {
            dx2 = -dx2; // Reverse x direction if it hits left/right wall
        }
        if (y2 == 1 || y2 == Y)
        {
            dy2 = -dy2; // Reverse y direction if it hits top/bottom wall
        }
    }

    // Output the final positions of both balls
    printf("%d\n%d\n%d\n%d", x1, y1, x2, y2);

    return 0;
}
