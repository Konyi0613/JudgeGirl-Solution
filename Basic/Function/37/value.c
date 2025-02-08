#include <stdio.h>
#include "value.h"
int gcd(int a, int b)
{
    while (a % b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
}
int value(int type, int width, int height, int length)
{
    if (type != 79 && type != 47 && type != 29 && type != 82 && type != 26 && type != 22)
        return -1;
    if (width <= 0 || height <= 0 || length <= 0)
        return -2;
    int unit_price;
    switch (type)
    {
    case 79:
        unit_price = 30;
        break;
    case 47:
        unit_price = 10;
        break;
    case 29:
        unit_price = 4;
        break;
    case 82:
        unit_price = 5;
        break;
    case 26:
        unit_price = 3;
        break;
    case 22:
        unit_price = 9;
        break;
    }
    int gcd12 = gcd(width, height);
    int gcd123 = gcd(gcd12, length);
    int counter = 1, max_value = 0;
    while (counter <= gcd123)
    {
        int cubic_num = (width / counter) * (height / counter) * (length / counter);
        int cubic_value = counter * counter * counter * counter * counter * counter * unit_price;
        if (gcd123 % counter == 0 && cubic_value * cubic_num > max_value)
            max_value = cubic_value * cubic_num;
        counter++;
    }
    return max_value;
}