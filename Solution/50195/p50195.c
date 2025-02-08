#include <stdio.h>
#include <stdbool.h>

int main()
{
    int max_dist[3] = {0};
    int max_pos[3][2];
    int second_max_dist[3] = {0};
    int second_max_pos[3][2];
    int last_pos[3] = {-1, -1 ,-1};
    int num_count[3] = {0};
    int in;
    int counter = 0;
    bool two_dist[3] = {0};
    while (scanf("%d", &in) != EOF)
    {
        int t = in - 1;
        int dist = counter - last_pos[t];
        if (num_count[t] == 1)
        {
            max_pos[t][0] = last_pos[t];
            max_pos[t][1] = counter;
            max_dist[t] = dist;
        }
        else if (num_count[t] == 2)
        {
            if (dist > max_dist[t])
            {
                second_max_dist[t] = max_dist[t];
                second_max_pos[t][0] = max_pos[t][0];
                second_max_pos[t][1] = max_pos[t][1];
                max_dist[t] = dist;
                max_pos[t][0] = last_pos[t];
                max_pos[t][1] = counter;
                two_dist[t] = true;
            }
            else if (dist == max_dist[t])
            {
                max_pos[t][0] = last_pos[t];
                max_pos[t][1] = counter;
            }
            else
            {
                second_max_dist[t] = dist;
                second_max_pos[t][0] = last_pos[t];
                second_max_pos[t][1] = counter;
                two_dist[t] = true;
            }
        }
        else if (num_count[t] > 2)
        {
            if (two_dist[t])
            {
                if (dist == max_dist[t])
                {
                    max_pos[t][0] = last_pos[t];
                    max_pos[t][1] = counter;
                }
                else if (dist == second_max_dist[t])
                {
                    second_max_pos[t][0] = last_pos[t];
                    second_max_pos[t][1] = counter;
                }
                else if (dist > max_dist[t])
                {
                    second_max_dist[t] = max_dist[t];
                    second_max_pos[t][0] = max_pos[t][0];
                    second_max_pos[t][1] = max_pos[t][1];
                    max_dist[t] = dist;
                    max_pos[t][0] = last_pos[t];
                    max_pos[t][1] = counter;
                }
                else if (dist > second_max_dist[t])
                {
                    second_max_dist[t] = dist;
                    second_max_pos[t][0] = last_pos[t];
                    second_max_pos[t][1] = counter;
                }
            }
            else
            {
                if (dist == max_dist[t])
                {
                    max_pos[t][0] = last_pos[t];
                    max_pos[t][1] = counter;
                }
                else if (dist > max_dist[t])
                {
                    second_max_dist[t] = max_dist[t];
                    second_max_pos[t][0] = max_pos[t][0];
                    second_max_pos[t][1] = max_pos[t][1];
                    max_dist[t] = dist;
                    max_pos[t][0] = last_pos[t];
                    max_pos[t][1] = counter;
                    two_dist[t] = true;
                }
                else if (dist < max_dist[t])
                {
                    second_max_dist[t] = dist;
                    second_max_pos[t][0] = last_pos[t];
                    second_max_pos[t][1] = counter;
                    two_dist[t] = true;
                }
            }
        }
        last_pos[t] = counter;
        num_count[t]++;
        counter++;
    }
    for (int i = 0; i < 3; i++)
        printf("%d %d %d\n", second_max_dist[i], second_max_pos[i][0], second_max_pos[i][1]);
}