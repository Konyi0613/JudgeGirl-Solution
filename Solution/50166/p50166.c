#include <stdio.h>

double calculate(int degree, double coefficient[], double x)
{
    double sum = 0;
    for (int i = 0; i <= degree; i++)
    {
        double tmp = 1;
        for (int j = 0; j < i; j++)
            tmp *= x;
        tmp *= coefficient[i];
        sum += tmp;
    }
    return sum;
}

int main()
{
    int degree;
    scanf("%d", &degree);
    double coefficient[degree + 1], dif_coefficient[degree];
    for (int i = degree; i >= 0; i--)
        scanf("%lf", &coefficient[i]);
    for (int i = 0; i < degree; i++)
        dif_coefficient[i] = coefficient[i + 1] * (i + 1);
    int k;
    scanf("%d", &k);
    double now_x, now_y;
    scanf("%lf", &now_x);
    now_y = calculate(degree, coefficient, now_x);
    printf("%.4f %.4f\n", now_x, now_y);
    //-now_y = m(next_x-now_x)
    for (int i = 0; i < k - 1; i++)
    {
        double m = calculate(degree - 1, dif_coefficient, now_x);
        now_x = (-now_y / m) + now_x;
        now_y = calculate(degree, coefficient, now_x);
        printf("%.4f %.4f\n", now_x, now_y);
    }

}