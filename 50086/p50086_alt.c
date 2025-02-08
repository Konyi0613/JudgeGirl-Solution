#include <stdio.h>
#include <stdbool.h>

int friends[32768][256];

int main()
{
    int N, E;
    scanf("%d%d", &N, &E);
    int friends_count[N];
    bool invite[N];
    for (int i = 0; i < N; i++)
    {
        friends_count[i] = 0;
        invite[i] = false;
    }
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        friends[v1][friends_count[v1]] = v2;
        friends[v2][friends_count[v2]] = v1;
        friends_count[v1]++;
        friends_count[v2]++;
    }
    int inviter;
    while (scanf("%d", &inviter) != EOF)
    {
        invite[inviter] = true;
        for (int i = 0; i < friends_count[inviter]; i++)
            invite[friends[inviter][i]] = true;
    }
    for (int i = 0; i < N; i++)
        if (!invite[i])
            printf("%d\n", i);
}