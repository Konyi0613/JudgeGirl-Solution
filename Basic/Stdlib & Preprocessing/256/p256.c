#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int cmp(const void *c1, const void *c2) {
    uint64_t a = *(uint64_t *)c1;
    uint64_t b = *(uint64_t *)c2;
    int one_a = __builtin_popcountll(a);
    int one_b = __builtin_popcountll(b);
    if (one_a != one_b)
        return one_a - one_b;
    else
        return (a > b) - (a < b);
}

int main() {
    uint64_t num[1001];
    int counter = 0;
    while (scanf("%lu", &num[counter]) != EOF)
        counter++;
    qsort(num, counter, sizeof(uint64_t), cmp);
    for (int i = 0; i < counter; i++)
        printf("%lu\n", num[i]);
}
