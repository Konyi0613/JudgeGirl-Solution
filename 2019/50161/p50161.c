#include <stdio.h>
// #define DEBUG
int main()
{
    int n;
    scanf("%d", &n);
    int card[n];
    int memory[100][5000];
    int count[100] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &card[i]);
        memory[card[i] - 1][count[card[i] - 1]] = i;
        count[card[i] - 1]++;
    }
    int used[100] = {0};
    for (int i = 0; i < n; i++)
    {
        printf("%d", i);
        used[card[i] - 1]++;
        if (used[card[i] - 1] % 2 == 0)
            printf(" %d %d", memory[card[i] - 1][used[card[i] - 1] - 2], card[i]);
        printf("\n");
    }
}