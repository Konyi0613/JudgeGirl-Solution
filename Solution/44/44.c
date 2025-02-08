#include <stdio.h>

enum Type
{
    NOVEL,
    COMICS,
    MANUAL,
    TEXTBOOK
};

struct Book
{
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};

struct Date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

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

int important(unsigned int n)
{
    int distance = 0, count = 0;
    while (count != 2)
    {
        if (n % 2 == 1)
            count++;
        if (count == 1 && n % 2 == 0)
            distance++;
        n = n >> 1;
    }
    return distance;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
    unsigned int fine = 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n1, n2;
    n1 = date_borrowed.year * 365 + date_borrowed.day + count(date_borrowed);
    for (int i = 0; i < date_borrowed.month - 1; i++)
    {
        if (i == 1 && leapyear(date_borrowed.year))
        {
            n1 += 29;
            continue;
        }
        n1 += days[i];
    }
    n2 = date_returned.year * 365 + date_returned.day + count(date_returned);
    for (int i = 0; i < date_returned.month - 1; i++)
    {
        if (i == 1 && leapyear(date_returned.year))
        {
            n2 += 29;
            continue;
        }
        n2 += days[i];
    }
    int during = n2 - n1 + 1;
    printf("during: %d\n", during);
    int exceed;
    switch (book.type)
    {
    case 0:
        if (during > 90)
            exceed = during - 90;
        else
            return 0;
        break;
    case 1:
        if (during > 10)
            exceed = during - 10;
        else
            return 0;
        break;
    case 2:
        if (during > 100)
            exceed = during - 100;
        else
            return 0;
        break;
    case 3:
        if (during > 5)
            exceed = during - 5;
        else
            return 0;
        break;
    }
    fine = important(book.importance) * exceed;
    return fine;
}

int main()
{
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17};
    struct Date date_borrowed, date_returned;
    date_borrowed.year = 1900;
    date_borrowed.month = 1;
    date_borrowed.day = 1;
    date_returned.year = 2000;
    date_returned.month = 12;
    date_returned.day = 31;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}