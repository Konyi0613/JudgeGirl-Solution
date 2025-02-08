#include <stdio.h>
#include <stdint.h>
int count1(uint32_t number, int bit_num)
{
    int one_num = 0;
    for (int i = 0; i < bit_num; i++)
    {
        if (number % 2 == 1)
            one_num++;
        number >>= 1;
    }
    return one_num;
}

uint32_t transformation(uint32_t number, int bit_num)
{
    if (bit_num == 1)
        return number;
    uint32_t A = (number >> (bit_num / 2));
    uint32_t B = (((1U << (bit_num / 2)) - 1) & number);
    int one_num = count1(number, bit_num);
    A = transformation(A, bit_num / 2);
    B = transformation(B, bit_num / 2);
    if (one_num % 2 == 0)
        return ((A << (bit_num / 2)) + B);
    else
        return ((B << (bit_num / 2)) + A);
}

int main()
{
    uint32_t number;
    scanf("%u", &number);
    printf("%u", transformation(number, 32));
}