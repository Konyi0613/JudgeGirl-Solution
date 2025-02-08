#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
void MorseEncode(int *n, char str[], uint64_t *encoded_content)
{
    char *MorseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int len = strlen(str);
    char tmp_morse[5000] = "";
    int now_index = 0;
    for (int i = 0; i < len; i++)
    {
        char *ptr = &tmp_morse[now_index];
        strcpy(ptr, MorseCodes[str[i] - 'A']);
        now_index += strlen(MorseCodes[str[i] - 'A']);
        tmp_morse[now_index] = ' ';
        now_index++;
    }
    now_index--;
    // printf("%s\n",tmp_morse);

    int tmp_len = now_index;

    // printf("%d\n", tmp_len);

    int now_bit = 0;
    encoded_content[0] = 0;
    for (int i = 0; i < tmp_len; i++)
    {
        // 00 for dot, 01 for dash, 10 for space, 11 for eof
        if (tmp_morse[i] == '.')
        {
            now_bit += 2;
        }
        else if (tmp_morse[i] == '-')
        {
            encoded_content[*n] |= (1ULL << (63 - now_bit - 1));
            now_bit += 2;
        }
        else
        {
            encoded_content[*n] |= (1ULL << (63 - now_bit));
            now_bit += 2;
        }
        if (now_bit == 64)
        {
            now_bit = 0;
            (*n)++;
            encoded_content[*n] = 0;
        }
    }
    // printf("%d\n",now_bit);
    int left_bit = 64 - now_bit;
    encoded_content[*n] |= ((1ULL << left_bit) - 1);
    if (now_bit != 0)
        (*n)++;
}