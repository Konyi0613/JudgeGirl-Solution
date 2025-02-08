#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n, e;
    scanf("%d%d", &n, &e);

    // �ϥΫ��а}�C���x�s�C�Ӿǥͪ��B��
    int *friends[n];
    int index[n]; // �x�s�C�Ӿǥͪ��B�ͼ�

    // ��l��
    for (int i = 0; i < n; i++)
    {
        friends[i] = (int *)malloc(256 * sizeof(int)); // �C�Ӿǥͳ̦h�� 256 �ӪB��
        index[i] = 0;
    }

    // ��J�B�����Y
    for (int i = 0; i < e; i++)
    {
        int vi, vj;
        scanf("%d%d", &vi, &vj);
        friends[vi][index[vi]] = vj;
        index[vi]++;
        friends[vj][index[vj]] = vi;
        index[vj]++;
    }

    bool invited[n]; // �����ֳQ�ܽ�
    for (int i = 0; i < n; i++)
    {
        invited[i] = false; // ��l���A�U�A�Ҧ��H�����Q�ܽ�
    }

    // Ū���ܽоǥͪ��ǦC
    int x;
    while (scanf("%d", &x) != EOF)
    {
        invited[x] = true; // �аO�ܽЪ�

        // �ܽЩҦ��B��
        for (int i = 0; i < index[x]; i++)
        {
            invited[friends[x][i]] = true; // �N�B�ͤ]�аO���Q�ܽ�
        }
    }

    // ��X���Q�ܽЪ��ǥ� ID�A�åB���ɧǱƦC
    bool first = true;
    for (int i = 0; i < n; i++)
    {
        if (!invited[i])
        {
            if (first)
            {
                first = false;
            }
            else
            {
                printf("\n");
            }
            printf("%d", i);
        }
    }

    // ����O����
    for (int i = 0; i < n; i++)
    {
        free(friends[i]);
    }

    return 0;
}