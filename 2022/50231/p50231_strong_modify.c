#include <stdio.h>
#include <stdlib.h>

#define MAXN 105
#define MAXS MAXN *MAXN
#define MAXC 10

void Insert(int k, int hashTable[MAXS][MAXC], int N, int S, int C, int val[MAXN * MAXN * MAXN]);
int Remove(int k, int h, int hashTable[MAXS][MAXC], int C, int val[MAXN * MAXN * MAXN]);

int Hash(int k, int S)
{
    return (77 * k + 2222) % S;
}
void Insert(int k, int hashTable[MAXS][MAXC], int N, int S, int C, int val[MAXN * MAXN * MAXN])
{
    if (k >= N * MAXN * MAXN)
        return;
    int h = Hash(val[k], S);
    int r = Remove(k, h, hashTable, C, val);
    if (r != -1)
    {
        printf("%d ", val[k]);
        Insert(k + MAXN * MAXN, hashTable, N, S, C, val);
        Insert(r + MAXN * MAXN, hashTable, N, S, C, val);
        return;
    }
    for (int i = 0; i < C; ++i)
    {
        if (hashTable[h][i] == -1)
        {
            hashTable[h][i] = k;
            break;
        }
    }
}
int Remove(int k, int h, int hashTable[MAXS][MAXC], int C, int val[MAXN * MAXN * MAXN])
{
    for (int i = 0; i < C; ++i)
    {
        if (hashTable[h][i] != -1 && val[hashTable[h][i]] == val[k])
        {
            int t = hashTable[h][i];
            hashTable[h][i] = -1;
            return t;
        }
    }
    return -1;
}

int main()
{

    int N, S, C;
    int hashTable[MAXS][MAXC];
    int val[MAXN * MAXN * MAXN];

    scanf("%d%d%d", &N, &S, &C);
    for (int i = 0; i < S; ++i)
        for (int j = 0; j < C; ++j)
            hashTable[i][j] = -1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            for (int k = 0; k <= i; ++k)
            {
                int id = i * MAXN * MAXN + j * MAXN + k;
                scanf("%d", &val[id]);
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int id = (i > j ? i : j) * MAXN * MAXN + i * MAXN + j;
            Insert(id, hashTable, N, S, C, val);
        }
    }

    return 0;
}