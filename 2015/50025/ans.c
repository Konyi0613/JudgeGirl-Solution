#include <stdio.h>
 
int find(int friends[][100], int n_remains, int remains[], int m, int count, int chosen[]) {
    if (count == m) {
        for (int i = 0; i < count; i++)
            printf("%d%c", chosen[i], i != count - 1 ? ' ' : '\n');
        return 1;
    }
    if (count + n_remains < m)
        return 0;
 
    int new_remains[100];
    int new_n_remains = 0;
    chosen[count] = remains[0];
    for (int i = 1; i < n_remains; i++) {
        if (!friends[remains[0]][remains[i]]) {
            new_remains[new_n_remains] = remains[i];
            new_n_remains++;
        }
    }
    return find(friends, new_n_remains, new_remains, m, count + 1, chosen) ||
        find(friends, n_remains - 1, remains + 1, m, count, chosen);
}
int main() {
    int n, m;
    int friends[100][100] = {0};
    int chosen[100];
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                scanf("%d", &friends[i][j]);
        }
        int remains[100];
        for (int i = 0; i < n; i++)
            remains[i] = i;
        int ret = find(friends, n, remains, m, 0, chosen);
        if (!ret)
            printf("no solution\n");
    }
    return 0;
}