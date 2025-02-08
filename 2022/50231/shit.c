#include <stdio.h>
#include <stdbool.h>
int hash_f(int k, int S)
{
    int j = (77 * k + 2222) % S;
    return j;
}
int main()
{
    int N, S, C;
    scanf("%d%d%d", &N, &S, &C);
    int tower[N][N][N]; // layer,row,col
    // i_th layer has (i+1)*(i+1) cubics
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            for (int k = 0; k < i + 1; k++)
            {
                scanf("%d", &tower[i][j][k]);
            }
        }
    }
    int expose[N][N]; // row,col
    int expose_layer[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            expose_layer[i][j] = (i > j) ? i : j;
            expose[i][j] = tower[expose_layer[i][j]][i][j];
        }
    }
    int hash_table[S][C];
    int i_hash[S][C];
    int j_hash[S][C];
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < C; j++)
        {
            hash_table[i][j] = 0;
            i_hash[i][j] = -1;
            j_hash[i][j] = -1;
        }
    }
    int t = 1000000;
    while (t--)
    {
        bool found = false;
        bool exist = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int key = expose[i][j];
                int index = hash_f(key, S);
                int counter = 0;
                while (counter < C)
                {
                    if (hash_table[index][counter] == key)
                    {
                        exist = true;
                        found = true;
                        if (expose_layer[i][j] < N - 1)
                        {
                            expose_layer[i][j]++;
                            expose[i][j] = tower[expose_layer[i][j]][i][j];
                            if (expose_layer[i_hash[index][counter]][j_hash[index][counter]] < N - 1)
                            {
                                expose_layer[i_hash[index][counter]][j_hash[index][counter]]++;
                                expose[i_hash[index][counter]][j_hash[index][counter]] = tower[expose_layer[i_hash[index][counter]][j_hash[index][counter]]][i_hash[index][counter]][j_hash[index][counter]];
                            }
                            else
                            {
                                expose[i_hash[index][counter]][j_hash[index][counter]] = -1;
                            }
                            hash_table[index][counter] = 0;
                            i_hash[index][counter] = -1;
                            j_hash[index][counter] = -1;
                            // delete the one who is stored in hash_table
                        }
                        else
                        {
                            expose[i][j] = -1;
                            if (expose_layer[i_hash[index][counter]][j_hash[index][counter]] < N - 1)
                            {

                                expose_layer[i_hash[index][counter]][j_hash[index][counter]]++;
                                expose[i_hash[index][counter]][j_hash[index][counter]] = tower[expose_layer[i_hash[index][counter]][j_hash[index][counter]]][i_hash[index][counter]][j_hash[index][counter]];
                            }
                            else
                            {
                                expose[i_hash[index][counter]][j_hash[index][counter]] = -1;
                            }
                        }
                        // i = 0;
                        // j = -1;
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
                            i_hash[index][counter] = i;
                            j_hash[index][counter] = j;
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

        /*if (found == false)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (expose[i][j] != -1)
                        printf("%d ", expose[i][j]);
                }
            }
            return 0;
        }
        */
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (expose[i][j] != -1)
                printf("%d ", expose[i][j]);
        }
    }
}