#include <stdio.h>
#include <stdbool.h>
int gcd2way(int a, int b)
{
    while (a % b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
}
int main()
{
    int N;
    scanf("%d", &N);
    int pin_num = N * (N + 1) / 2;
    int pin_left[pin_num];
    int pin_right[pin_num];
    int pin_denominator[pin_num];
    for (int i = 0; i < pin_num; i++)
    {
        scanf("%d%d", &pin_left[i], &pin_right[i]);
        pin_denominator[i] = pin_left[i] + pin_right[i];
        int gcd = gcd2way(pin_left[i], pin_denominator[i]);
        pin_left[i] /= gcd;
        pin_right[i] /= gcd;
        pin_denominator[i] /= gcd;
    }
    int come_pro_nu[pin_num + N + 1];
    int come_pro_de[pin_num + N + 1];
    for (int layer = 0; layer <= N; layer++)
    {
        // first ball of the layer is (layer*(layer + 1))/2
        for (int ball_num = 0; ball_num < layer + 1; ball_num++)
        {
            if (layer == 0)
            {
                come_pro_nu[0] = 1;
                come_pro_de[0] = 1;
                continue;
            }
            if (ball_num == 0)
            {
                come_pro_nu[layer * (layer + 1) / 2] = come_pro_nu[layer * (layer - 1) / 2] * pin_left[layer * (layer - 1) / 2];
                come_pro_de[layer * (layer + 1) / 2] = come_pro_de[layer * (layer - 1) / 2] * pin_denominator[layer * (layer - 1) / 2];
                int gcd = gcd2way(come_pro_nu[layer * (layer + 1) / 2], come_pro_de[layer * (layer + 1) / 2]);
                come_pro_nu[layer * (layer + 1) / 2] /= gcd;
                come_pro_de[layer * (layer + 1) / 2] /= gcd;
            }
            else if (ball_num == layer)
            {
                come_pro_nu[(layer + 1) * (layer + 2) / 2 - 1] = come_pro_nu[layer * (layer + 1) / 2 - 1] * pin_right[layer * (layer + 1) / 2 - 1];
                come_pro_de[(layer + 1) * (layer + 2) / 2 - 1] = come_pro_de[layer * (layer + 1) / 2 - 1] * pin_denominator[layer * (layer + 1) / 2 - 1];
                int gcd = gcd2way(come_pro_nu[(layer + 1) * (layer + 2) / 2 - 1], come_pro_de[(layer + 1) * (layer + 2) / 2 - 1]);
                come_pro_nu[(layer + 1) * (layer + 2) / 2 - 1] /= gcd;
                come_pro_de[(layer + 1) * (layer + 2) / 2 - 1] /= gcd;
            }
            else
            {
                // suppose it is the k'th ball in the layer, 0 <= k <= layer
                //  then it is layer*(layer + 1)/2 +ball_num
                //  it is by the k-1'th and k'th ball of the previous layer
                //  which is (layer - 1)*layer/2 + ball_num - 1 and (layer - 1)*layer/2 + ball_num
                int from_left_nu, from_left_de, from_right_nu, from_right_de, final_nu, final_de;
                from_left_nu = come_pro_nu[(layer - 1) * layer / 2 + ball_num - 1] * pin_right[(layer - 1) * layer / 2 + ball_num - 1];
                from_left_de = come_pro_de[(layer - 1) * layer / 2 + ball_num - 1] * pin_denominator[(layer - 1) * layer / 2 + ball_num - 1];
                int gcd = gcd2way(from_left_nu, from_left_de);
                from_left_nu /= gcd;
                from_left_de /= gcd;
                from_right_nu = come_pro_nu[(layer - 1) * layer / 2 + ball_num] * pin_left[(layer - 1) * layer / 2 + ball_num];
                from_right_de = come_pro_de[(layer - 1) * layer / 2 + ball_num] * pin_denominator[(layer - 1) * layer / 2 + ball_num];
                gcd = gcd2way(from_right_nu, from_right_de);
                from_right_nu /= gcd;
                from_right_de /= gcd;
                final_nu = from_left_nu * from_right_de + from_right_nu * from_left_de;
                final_de = from_left_de * from_right_de;
                gcd = gcd2way(final_nu, final_de);
                come_pro_nu[layer * (layer + 1) / 2 + ball_num] = final_nu / gcd;
                come_pro_de[layer * (layer + 1) / 2 + ball_num] = final_de / gcd;
            }
        }
    }
    for (int i = 0; i < N + 1; i++)
    {
        printf("%d/%d\n", come_pro_nu[N * (N + 1) / 2 + i], come_pro_de[N * (N + 1) / 2 + i]);
    }
}