#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 1 << 20 // 1 MB buffer

// Input buffer
char inputBuffer[BUFFER_SIZE];
char *inputPtr = inputBuffer;

// Output buffer
char outputBuffer[BUFFER_SIZE];
char *outputPtr = outputBuffer;

// Fast input function
int fastInput() {
    int num = 0, sign = 1;
    
    // Skip non-numeric characters
    while (*inputPtr && !isdigit(*inputPtr) && *inputPtr != '-') {
        inputPtr++;
    }
    
    // Handle negative numbers
    if (*inputPtr == '-') {
        sign = -1;
        inputPtr++;
    }
    
    // Read number
    while (*inputPtr && isdigit(*inputPtr)) {
        num = num * 10 + (*inputPtr - '0');
        inputPtr++;
    }
    
    return num * sign;
}

// Fast output function
void fastOutput(int num) {
    char buffer[12]; // Enough for 32-bit integers
    int i = 0;

    if (num < 0) {
        *outputPtr++ = '-';
        num = -num;
    }

    if (num == 0) {
        *outputPtr++ = '0';
    } else {
        while (num > 0) {
            buffer[i++] = '0' + (num % 10);
            num /= 10;
        }
        while (i > 0) {
            *outputPtr++ = buffer[--i];
        }
    }

    *outputPtr++ = '\n';
}

int main() {
    // Load input into buffer
    fread(inputBuffer, 1, BUFFER_SIZE, stdin);

    // Read numbers
    int a = fastInput();
    int b = fastInput();

    // Write numbers in reverse order
    fastOutput(b);
    fastOutput(a);

    // Flush output buffer
    fwrite(outputBuffer, 1, outputPtr - outputBuffer, stdout);

    return 0;
}
