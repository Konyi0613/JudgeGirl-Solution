#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "book.h"
#include "date.h"
int leapyear(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}
int count(struct Date date)
{
    int year = date.year;
    year--;
    int leap = year / 4 - year / 100 + year / 400;
    return leap;
}
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
    int day_num[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned borrow_day = 0;
    int d1 = 365 * date_borrowed.year + date_borrowed.day + count(date_borrowed), d2 = 365 * date_returned.year + date_returned.day + count(date_returned);
    for (int i = 1; i < date_borrowed.month; i++)
    {
        if (leapyear(date_borrowed.year) == 1 && i == 2)
            d1++;
        d1 += (day_num[i]);
    }
    for (int i = 1; i < date_returned.month; i++)
    {
        if (leapyear(date_returned.year) == 1 && i == 2)
            d2++;
        d2 += (day_num[i]);
    }
    borrow_day = (d2 - d1);
    borrow_day++;
    bool found_head = false;
    int step = 0;
    unsigned int importance_cpy = book.importance;
    while (importance_cpy != 0)
    {
        if (found_head && (importance_cpy >> 1) != 0U)
            step++;
        if ((importance_cpy & 1U == 1U) && !found_head)
            found_head = true;
        importance_cpy >>= 1;
    }
    // printf("step: %d\n", step);
    int max_borrow_day;
    if (book.type == NOVEL)
        max_borrow_day = 90;
    else if (book.type == COMICS)
        max_borrow_day = 10;
    else if (book.type == MANUAL)
        max_borrow_day = 100;
    else
        max_borrow_day = 5;
    if (borrow_day <= max_borrow_day)
        return 0;
    return ((borrow_day - max_borrow_day) * step);
}
static unsigned int importance_factor(unsigned int importance)
{
    int lower = importance & -importance;
    int upper = importance ^ lower;
    int factor;
    for (factor = 0; (lower <<= 1) != upper; ++factor)
        ;
    return factor;
}
/*
int main()
{
    unsigned int i, j;

    unsigned int importance[32 * 31 / 2];
    int n_importance = 0;
    for (i = 0; i < 32; ++i)
        for (j = 0; j < i; ++j)
            importance[n_importance++] = (1 << i) | (1 << j);

    const char title[4][128] = {"Fundation", "Neon Genesis Evangelion, Vol. 1", "Programming Perl (3rd Edition)", "C How to Program (5th Edition)"};
    const char ISBN[4][128] = {"978-055-380-371-6", "978-159-116-400-5", "978-059-600-027-1", "978-013-240-416-7"};
    const char authors[4][128] = {"Isaac Asimov", "Yoshiyuki Sadamoto", "Larry Wall", "Harvey Deitel & Paul Deitel"};
    struct Book books[32 * 31 / 2 * 4];
    int n_book = 0;
    for (i = NOVEL; i <= TEXTBOOK; ++i)
        for (j = 0; j < n_importance; ++j)
        {
            strcpy(books[n_book].title, title[i]);
            books[n_book].type = i;
            strcpy(books[n_book].ISBN, ISBN[i]);
            sprintf(books[n_book].authors, "%s", authors[i]);
            books[n_book].importance = importance[j];
            ++n_book;
        }

    struct Date date_borrowed, date_returned;
    scanf("%d %d %d %d %d %d",
          &date_borrowed.year, &date_borrowed.month, &date_borrowed.day,
          &date_returned.year, &date_returned.month, &date_returned.day);

    printf("+---------------------------------+----------------+----------+\n");
    printf("|              Title              |   Importance   |   Fine   |\n");
    printf("+---------------------------------+----------------+----------+\n");
    for (i = 0; i < n_book; ++i)
    {
        printf("| %-31.31s | %#010x(%2u) | %8u |\n",
               books[i].title,
               books[i].importance,
               importance_factor(books[i].importance),
               library_fine(books[i], date_borrowed, date_returned));
    }
    printf("+---------------------------------+----------------+----------+\n");
    return 0;
}
*/