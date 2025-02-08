#include <stdio.h>
#include <stdbool.h>
int hash_f(int k, int S)
{
    int j = (77 * k + 2222) % S;
    return j;
}
int main()
{
    int S, C;
    scanf("%d%d", &S, &C);
    int hash_table[S][C];
    for (int i = 0; i < S; i++)
        for (int j = 0; j < C; j++)
            hash_table[i][j] = 0;
    int key;
    while (scanf("%d", &key) != EOF)
    {
        int index = hash_f(key, S);
        int counter = 0;
        bool exist = false;
        while (counter < C)
        {
            if (hash_table[index][counter] == key)
            {
                exist = true;
                printf("%d %d\n", key, index);
                hash_table[index][counter] = 0;
                break;
            }
            counter++;
        }
        counter = 0;
        if (exist == false)
        {
            while (counter < C)
            {
                if (hash_table[index][counter] == 0)
                {
                    hash_table[index][counter] = key;
                    break;
                }
                else
                {
                    counter++;
                }
            }
        }
    }
}