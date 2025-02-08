#include "subset.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int find(int numbers[], int n, int K, int S, int id) {
    if (S == 0) {
        if (K == 0)
            return 1;
        else
            return 0;
    } else if (id == n) {
        if (S == 0 && K == 0)
            return 1;
        else
            return 0;
    }
    if (K <= 0)
        return 0;
    return 
    find(numbers, n, K - numbers[id], S - 1, id + 1) || find(numbers, n, K, S, id + 1);
}

int subset(int numbers[], int n, int K, int S){
    // Fill your code in here.
    return find(numbers, n, K, S, 0);
}