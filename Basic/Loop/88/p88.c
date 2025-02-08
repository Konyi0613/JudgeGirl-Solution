#include <stdio.h>

int main()
{
    int A = 0, B = 0, num1, num2;
    scanf("%d%d", &num1, &num2);
    int temp1 = num1, temp2 = num2;
    int a1[4], a2[4];
    for (int i = 3; i >= 0; i--)
    {
        int tens = 1;
        for (int j = 0; j < i; j++)
            tens *= 10;
        if (temp1 / tens == temp2 / tens)
            A++;
        a1[3 - i] = temp1 / tens;
        a2[3 - i] = temp2 / tens;
        temp1 %= tens;
        temp2 %= tens;
    }
    for (int i = 0; i < 4; i++)
    {
        if (a1[i] == a2[i])
            continue;
        for (int j = 0; (j < 4) && (i != j); j++)
        {
            if (a1[i] == a2[j])
                B++;
            if (a1[j] == a2[i])
                B++;
        }
    }
    printf("%dA%dB", A, B);
}