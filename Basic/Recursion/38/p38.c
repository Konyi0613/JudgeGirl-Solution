#include <stdio.h>

int lotion(int target, int supply[3], int level[3], int left)
{
    if ((target == level[0] && supply[0] > 0) || (target == level[1] && supply[1] > 0) || (target == level[2] && supply[2] > 0) || (target == 0))
        return 1;
    for (int i = 0; i < 3; i++)
    {
        if (supply[i] == 0 || target < level[i])
            continue;
        supply[i]--;
        left--;
        if (lotion(target - level[i], supply, level, left) == 1)
            return 1;
        supply[i]++;
        left++;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int target;
    int level[3];
    int supply[3];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d%d%d%d", &target, &supply[0], &supply[1], &supply[2], &level[0], &level[1], &level[2]);
        int result = lotion(target, supply, level, supply[0] + supply[1] + supply[2]);
        if (result == 1)
            printf("yes\n");
        else
            printf("no\n");
    }
}