#include <stdio.h>
#define MAXN 100005
int A[MAXN];
int main() {
    int n, i;
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; i++)
            scanf("%d", &A[i]);
        /* add your code */
        int zero_num = 0;
        for (i = 0; i < n; i++)
            if (A[i] == 0)
                zero_num++;
            else
                printf("%d ", A[i]);
        if (zero_num > 0)
        {
            printf("0");
            for (int i = 0; i < zero_num - 1; i++)
                printf(" 0");
            printf("\n");
        }
    }
    return 0;
}