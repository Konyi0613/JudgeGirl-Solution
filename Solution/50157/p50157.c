#include <stdio.h>

int main()
{
    int k;
    scanf("%d", &k);
    int attribute_num[3] = {0};
    int sum = 0;
    int max = -1, second_max = -1;
    int input;
    while (scanf("%d", &input) != EOF)
    {
        int id = input % 3;
        attribute_num[id]++;
        if (max == -1)
            max = input;
        else if (input >= max)
        {
            second_max = max;
            max = input;
        }
        else if (second_max == -1 || (input > second_max))
            second_max = input;
        if (attribute_num[0] >= k && attribute_num[1] >= k && attribute_num[2] >= k)
        {
            sum += second_max;
            attribute_num[0] = attribute_num[1] = attribute_num[2] = 0;
            max = second_max = -1;
        }
    }
    if (second_max == -1 && max != -1)
        sum += max;
    else if (max != -1)
        sum += second_max;
    printf("%d", sum);
}