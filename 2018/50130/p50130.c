#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int getID(int userNum, char **userName, char *key) {
    for (int i = 0; i < userNum; i++)
        if (strcmp(userName[i], key) == 0)
            return i;
    return -1;
}

void redundant_input() {
    while (true) {
        char c;
        scanf("%c", &c);
        if (c == '\n')
            return;
    }
}

int decrypt(char *instruction, char *tg) {
    int len1 = strlen(instruction), len2 = strlen(tg);
    for (int i = 0; i < len1 - len2 + 1; i++) {
        if (strncmp(&(instruction[i]), tg, len2) == 0)
            return 1;
    }
    return 0;
}

int main() {
    int userNum;
    scanf("%d", &userNum);
    char *userName[userNum];
    int balance[userNum];
    for (int i = 0; i < userNum; i++) {
        userName[i] = (char *)malloc(33 * sizeof(char));
        scanf("%s%d", userName[i], &balance[i]);
    }
    char name1[33];
    char *tg_table[4] = {"earns", "spends", "gives", "becomes"};
    while (scanf("%s", name1) != EOF) {
        int id1 = getID(userNum, userName, name1);
        if (id1 == -1) {
            redundant_input();
            continue;
        }
        char instruction[33];
        scanf("%s", instruction);
        int type = -1;
        for (int i = 0; i < 4 && type == -1; i++)
            if (decrypt(instruction, tg_table[i]) == 1)
                type = i;
        if (type == -1) {
            redundant_input();
            continue;
        }
        if (type == 0) {
            int add;
            scanf("%d", &add);
            balance[id1] += add;
        } else if (type == 1) {
            int decrease;
            scanf("%d", &decrease);
            if (balance[id1] >= decrease)
                balance[id1] -= decrease;
        } else if (type == 2) {
            char name2[33];
            scanf("%s", name2);
            int id2 = getID(userNum, userName, name2);
            if (id2 == -1) {
                redundant_input();
                continue;
            }
            int change;
            scanf("%d", &change);
            if (balance[id1] < change)
                continue;
            balance[id1] -= change;
            balance[id2] += change;            
        } else {
            int new;
            scanf("%d", &new);
            balance[id1] = new;
        }
    }
    for (int i = 0; i < userNum; i++)
        printf("%s %d\n", userName[i], balance[i]);
}