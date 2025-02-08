#include <stdio.h>
#include <stdbool.h>

int main()
{
    int year, jan_first;
    scanf("%d%d", &year, &jan_first);
    bool leap_year = false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        leap_year = true;
    int n;
    scanf("%d", &n);
    int correct_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leap_year)
        correct_day[2] = 29;
    for (int i = 0; i < n; i++)
    {
        int month, day;
        scanf("%d%d", &month, &day);
        if (month > 12 || month < 1)
        {
            printf("-1\n");
            continue;
        }
        else if (day > correct_day[month] || day < 1)
        {
            printf("-2\n");
            continue;
        }
        int gap = 0;
        if (month == 1)
        {
            printf("%d\n", (jan_first + day - 1) % 7);
            continue;
        }
        else
        {
            for (int i = 1; i <= month - 1; i++)
                gap += correct_day[i];
            gap += (day - 1);
            printf("%d\n", (jan_first + gap) % 7);
            continue;
        }
    }
}