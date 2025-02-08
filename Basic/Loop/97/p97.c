#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int distance(int x1, int y1, int x2, int y2)
{
    return (abs(x1 - x2) + abs(y1 - y2));
}
int main()
{
    int n;
    scanf("%d", &n);
    int park_x[n], park_y[n], capacity[n];
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &park_x[i], &park_y[i], &capacity[i]);
    int m;
    scanf("%d", &m);
    int bike_x[m], bike_y[m];
    for (int i = 0; i < m; i++)
        scanf("%d%d", &bike_x[i], &bike_y[i]);
    int num[n];
    for (int i = 0; i < n; i++)
        num[i] = 0;
    for (int i = 0; i < m; i++)
    {
        int min_one = 0;
        while (num[min_one] >= capacity[min_one])
        {
            min_one++;
        }
        for (int j = min_one + 1; j < n; j++)
        {
            if (distance(park_x[j], park_y[j], bike_x[i], bike_y[i]) < distance(park_x[min_one], park_y[min_one], bike_x[i], bike_y[i]) &&
                (num[j] < capacity[j]))
            {
                min_one = j;
            }
            else if (distance(park_x[j], park_y[j], bike_x[i], bike_y[i]) == distance(park_x[min_one], park_y[min_one], bike_x[i], bike_y[i]) &&
                     (num[j] < capacity[j]))
            {
                if (park_x[j] < park_x[min_one])
                    min_one = j;
                else if (park_x[j] == park_x[min_one] && park_y[j] < park_y[min_one])
                    min_one = j;
            }
        }
        num[min_one]++;
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", num[i]);
}