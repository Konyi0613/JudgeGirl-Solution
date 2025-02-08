#include <stdio.h>
#include <stdbool.h>
#include "snake.h"

int snake(int *ptr, int *row, int *column) {
    int now_r = 0, now_c = 0;
    int counter = 0;
    while (*ptr == counter) {
        now_c++;
        ptr++;
        counter++;
    }
    now_r = 1;
    *column = now_c;
    now_c--;
    while (*ptr != 0) {
        int tg = now_r * (*column) + now_c;
        if (*ptr != tg) {
            *row = now_r;
            *column = now_c;
            return 0;
        }
        if (now_r % 2 == 0) {
            if (now_c != (*column) - 1)
                now_c++;
            else
                now_r++;
        } else {
            if (now_c != 0)
                now_c--;
            else
                now_r++;
        }
        ptr++;
    }
    *row = now_r;
    return 1;
}