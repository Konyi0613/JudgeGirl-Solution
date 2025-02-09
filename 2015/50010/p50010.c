#include <stdio.h>
#include <string.h>

void replace(char* string, char x, char y) {
    int len = strlen(string);
    for (int i = 0; i < len; ++i)
        if (string[i] == x)
            string[i] = y;
    return;
}

void remove_str(char* string, char x) {
    char tmp[100001];
    int pos = 0;
    char* front = string;
    char* back = front;
    int len = strlen(string);
    while (back - string < len) {
        while (*front == x && front - string < len)
            front++;
        if (front - string >= len)
            break;
        back = front;
        while (*back != x && back - string < len)
            back++;
        if (back - string <= len) {
            strncpy(&(tmp[pos]), front, back - front);
            pos += (back - front);
        }
        front = back;
    }
    tmp[pos] = '\0';
    strcpy(string, tmp);
    return;
}

void add_head(char *string, char x) {
    char tmp[100001];
    strcpy(tmp, string);
    string[0] = x;
    strcpy(&(string[1]), tmp);
    return;
}

void add_tail(char *string, char x) {
    int len = strlen(string);
    string[len] = x;
    string[len + 1] = '\0';
    return;
}


int main() {
    char string[100001];
    scanf("%s", string);
    char command[10];
    int legal = 1;
    while (scanf("%s", command) != EOF) {
        char x, y;
        if (strcmp(command, "replace") == 0) {
            scanf("\n%c %c", &x, &y);
            replace(string, x, y);
        } else if (strcmp(command, "remove") == 0) {
            scanf("\n%c", &x);
            remove_str(string, x);
        } else if (strcmp(command, "addhead") == 0) {
            scanf("\n%c", &x);
            add_head(string, x);
        } else if (strcmp(command, "addtail") == 0) {
            scanf("\n%c", &x);
            add_tail(string, x);
        } else if (strcmp(command, "end") == 0)
            break;
        else {
            printf("invalid command %s\n", command);
            legal = 0;
            break;
        }
    }
    if (legal)
        printf("%s\n", string);
}