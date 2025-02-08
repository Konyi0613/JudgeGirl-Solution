#include <stdio.h>
#include <stdbool.h>
// #define DEBUG
// the better way is to print only when index == n
int find_solution(int k, int N, int M, int num[N], int picked[N], int index, int picked_number, bool last_pick)
{
    int sum = 0;
    for (int i = 0; i < picked_number; i++)
        sum += num[picked[i]];
    bool valid = false;
    if (sum > M || (index == N && picked_number < k))
        return 0;
    else if (sum <= M && picked_number >= k && last_pick)
    {
#ifdef DEBUG
        printf("index: %d\n", index);
        for (int i = 0; i < picked_number; i++)
            printf("%d ", num[picked[i]]);
        printf("\n");
#endif
        valid = true;
    }
    picked[picked_number] = index;
    if (!valid && index < N)
        return find_solution(k, N, M, num, picked, index + 1, picked_number + 1, true) + find_solution(k, N, M, num, picked, index + 1, picked_number, false);
    else if (valid && index < N)
        return 1 + find_solution(k, N, M, num, picked, index + 1, picked_number + 1, true) + find_solution(k, N, M, num, picked, index + 1, picked_number, false);
    else if (valid && index == N)
        return 1;
    else if (!valid && index == N)
        return 0;
}

int main()
{
    int k, N, M;
    scanf("%d%d%d", &k, &N, &M);
    int num[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    int picked[N];
    printf("%d", find_solution(k, N, M, num, picked, 0, 0, true));
}