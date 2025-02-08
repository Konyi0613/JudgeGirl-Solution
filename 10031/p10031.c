#include <stdio.h>

unsigned long long modular_multiply(unsigned long long a, unsigned long long b, unsigned long long n) {
    unsigned long long result = 0; // Result of (a * b) % n
    a = a % n; // Reduce 'a' modulo 'n'

    while (b > 0) {
        // If the current bit of 'b' is set, add 'a' to the result
        if (b & 1) {
            result = (result + a) % n;
        }

        // Double 'a' and reduce modulo 'n'
        a = (a * 2) % n;

        // Right-shift 'b' by 1 to process the next bit
        b >>= 1;
    }

    return result;
}

int main() {
    unsigned long long a, b, n;
    while (scanf("%llu %llu %llu", &a, &b, &n) == 3) {
        printf("%llu\n", modular_multiply(a, b, n));
    }
    return 0;
}
