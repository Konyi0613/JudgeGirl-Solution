#include <stdio.h>
#include <stdbool.h>
#include "length.h"

void init(int length[3]) {
    /* add your code */
    length[0] = length[1] = length[2] = 0;
}
void add(int length[3], int i) {
    /* add your code */
    length[2] += i;
    if (length[2] > 11) {
        int nxt = length[2] / 12;
        length[2] %= 12;
        length[1] += nxt;
        if (length[1] > 2) {
            int nxt2 = length[1] / 3;
            length[1] %= 3;
            length[0] += nxt2;
        }
    }
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    /* add your code */
    int i = 36 * lengthb[0] + 12 * lengthb[1] + lengthb[2];
    for (int i = 0; i < 3; i++)
        lengthc[i] = lengtha[i];
    add(lengthc, i);
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    /* add your code */
    int a = 36 * lengtha[0] + 12 * lengtha[1] + lengtha[2];
    int b = 36 * lengthb[0] + 12 * lengthb[1] + lengthb[2];
    init(lengthc);
    add(lengthc, a - b);
}