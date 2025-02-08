#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *t1, const void *t2) {
    return strcmp((char *)t1, (char *)t2);
}

int main() {
    int n;
    scanf("%d", &n);
    char string[8];
    char ans[2][n][8]; // Stores valid license plates for type 0 and 1
    int num[2] = {0};  // Counters for valid plates of type 0 and type 1

    for (int i = 0; i < n; i++) {
        scanf("%s", string);
        bool valid = true;
        int type = -1, digit_num = 0, digit_sum = 0, last_four = -2;

        // Frequency array to track occurrences of characters
        int freq[128] = {0};

        for (int j = 0; j < 7; j++) {
            if (j != 2 && j != 3 && !isalpha(string[j]) && !isdigit(string[j])) {
                valid = false; // Invalid character
                break;
            } else if (j == 2 && string[j] == '-') {
                type = 0;
            } else if (j == 3 && string[j] == '-') {
                type = 1;
            } else if (j == 3 && type == -1) {
                valid = false; // Invalid type
                break;
            } else if (isdigit(string[j])) {
                digit_num++;
                digit_sum += (string[j] - '0');
                if (string[j] == '4') {
                    if (last_four + 1 == j) {
                        valid = false; // Consecutive '4's
                        break;
                    }
                    last_four = j;
                }
            }

            // Update frequency array and check occurrences
            freq[(int)string[j]]++;
            if (freq[(int)string[j]] > 2) {
                valid = false; // Character occurs more than twice
                break;
            }
        }

        // Ensure type and additional constraints
        if (digit_num == 0 || digit_sum % 7 == 0 || type == -1) valid = false;
        if (type == 0 && isdigit(string[1]) && isdigit(string[2])) valid = false;
        if (type == 1 && isdigit(string[2]) && isdigit(string[3])) valid = false;

        // Add to the result if valid
        if (valid) {
            strcpy(ans[type][num[type]], string);
            num[type]++;
        }
    }

    // Sort and print results
    for (int i = 0; i < 2; i++) {
        if (num[i] > 0) {
            qsort(ans[i], num[i], sizeof(char[8]), cmp);
            for (int j = 0; j < num[i]; j++)
                printf("%s\n", ans[i][j]);
        }
    }

    return 0;
}
