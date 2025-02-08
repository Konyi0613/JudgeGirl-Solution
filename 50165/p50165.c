#include <stdio.h>
#include <math.h>

double det(double a, double b, double c, double d)
{
    return (a * d - c * b);
}

void intersect(double a[2], double b[2], double c[2], double *x, double *y)
{
    double delta = det(a[0], b[0], a[1], b[1]);
    double delta_x = det(c[0], b[0], c[1], b[1]);
    double delta_y = det(a[0], c[0], a[1], c[1]);
    *x = delta_x / delta;
    *y = delta_y / delta;
    return;
}

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n;
    scanf("%d", &n);
    double x[n], y[n];
    double a[2], b[2], c[2], first_a, first_b, first_c;
    scanf("%lf%lf%lf", &a[0], &b[0], &c[0]);
    first_a = a[0];
    first_b = b[0];
    first_c = c[0];
    double ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%lf%lf%lf", &a[1], &b[1], &c[1]);
        intersect(a, b, c, &(x[i]), &(y[i]));
        a[0] = a[1];
        b[0] = b[1];
        c[0] = c[1];
    }
    a[1] = first_a;
    b[1] = first_b;
    c[1] = first_c;
    intersect(a, b, c, &(x[n - 1]), &(y[n - 1]));
    double perimeter = 0;
    for (int i = 0; i < n; i++)
    {
        int first = i, second = (i + 1) % n;
        perimeter += distance(x[first], y[first], x[second], y[second]);
    }
    printf("%.3lf\n", perimeter);
}