#include <stdio.h>
#include <string.h>

int compare(char *longer, char *shorter, int len_short) {
    int pos = -1;
    for (int i = 0; i < len_short && pos == -1; ++i) {
        if (longer[i] != shorter[i])
            pos = i;
    }
    if (pos == -1)
        return 1;
    if (strcmp(&(shorter[pos]), &(longer[pos + 1])) == 0)
        return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    char dictionary[n][101];
    for (int i = 0; i < n; ++i)
        scanf("%s", dictionary[i]);
    int m;
    scanf("%d", &m);
    char text[101];
    for (int i = 0; i < m; ++i) {
        scanf("%s", text);
        int id = -1;
        for (int j = 0; j < n && id == -1; j++)
            if (strcmp(dictionary[j], text) == 0)
                id = j;
        if (id != -1) {
            printf(">%s\n", text);
            continue;
        }
        int candidate_num = 0;
        int candidate_id[n];
        int len_text = strlen(text);
        for (int j = 0; j < n; ++j) {
            int len_dic = strlen(dictionary[j]);
            if (len_text - len_dic > 1 || len_text - len_dic < -1)
                continue;
            else if (len_text == len_dic) {
                int diff = 0;
                for (int k = 0; k < len_text && diff < 2; k++)
                    if (text[k] != dictionary[j][k])
                        diff++;
                if (diff == 1)
                    candidate_id[candidate_num++] = j;
            } else {
                if (len_text > len_dic) {
                    if (compare(text, dictionary[j], len_dic) == 1)
                        candidate_id[candidate_num++] = j;
                } else {
                    if (compare(dictionary[j], text, len_text) == 1)
                        candidate_id[candidate_num++] = j;
                }
            }
        }
        if (candidate_num == 0)
            printf("!%s\n", text);
        else {
            for (int i = 0; i < candidate_num; i++)
                printf("%c%s", (i == 0) ? '?' : ' ', dictionary[candidate_id[i]]);
            printf("\n");
        }
    }
}