#include <stdio.h>
#include <math.h>

int main()
{
    double input[5];
    for(int i = 0; i < 5; i++)
    {
        scanf("%lf", &input[i]);
    }
    //scanf("%lf %lf %lf %lf %lf", &input[0], &input[1], &input[2], &input[3], &input[4]);
    double signal[4][5] = {{0.0, 0.707, 1, 0.707, 0.0},
    {0.0, -0.707, -1, -0.707, 0.0},{0.0,2.828,4,2.828,0.0},
    {0.0, -2.828, -4, -2.828, 0.0}};
    double similarity[4]={0,0,0,0};
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            double distance = signal[i][j]-input[j];
            similarity[i]+=pow(distance, 2);
        }
        similarity[i] = sqrt(similarity[i]);
    }
    int min_index = 0;
    for(int i = 1; i < 4; i++)
    {
        if(similarity[i] < similarity[min_index])
        {
            min_index = i;
        }
    }
    if(similarity[min_index] >= 1.0)
    {
        printf("no signal matched");
    }
    else
    {
        printf("%d",min_index + 1);
    }
}