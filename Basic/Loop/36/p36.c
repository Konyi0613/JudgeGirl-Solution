#include <stdio.h>
#include <stdbool.h>

int main()
{
    int year, month, first_day;
    scanf("%d%d%d", &year, &month, &first_day);
    int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap_year = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    if (leap_year)
        month_day[1] = 29;
    // test invalid
    if ((month > 12 || month < 1) || (first_day > 6 || first_day < 0))
    {
        printf("invalid");
        return 0;
    }
    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================\n");
    int day_counter = 0;
    for (int i = 0; i < first_day; i++)
    {
        printf("   ");
        day_counter++;
    }
    for (int i = 1; i <= month_day[month - 1]; i++)
    {
        if (day_counter % 7 == 6)
            printf("%3d\n", i);
        else
            printf("%3d", i);
        if (i == month_day[month - 1] && day_counter % 7 != 6)
            printf("\n");
        day_counter++;
    }
    printf("=====================\n");
}