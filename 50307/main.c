#include <stdio.h>
#include "scholarship.h"

int main() {
    int n;
    struct Student students[505];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", students[i].id);
        scanf("%d", &students[i].k);
        for (int j = 0; j < students[i].k; j++) {
            scanf("%d %d %d", &students[i].classes[j].credit, &students[i].classes[j].type, &students[i].classes[j].score);
        }
    }
    scholarship(n, students);
}
