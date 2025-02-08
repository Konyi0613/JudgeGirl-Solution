#include <stdio.h>
#include "card.h"

void shuffle(int *deck[])
{
    int card_num = 0;
    while (deck[card_num] != NULL)
        card_num++;
    int *half1[(card_num + 1) / 2], *half2[card_num - ((card_num + 1) / 2)];
    for (int i = 0; i < card_num; i++)
    {
        if (i < (card_num + 1) / 2)
            half1[i] = deck[i];
        else
            half2[i - (card_num + 1) / 2] = deck[i];
    }
    int pile = 1;
    int pile1_count = 0;
    int pile2_count = 0;
    int *deck2[card_num];
    for (int i = 0; i < card_num; i++)
    {
        if (pile == 1)
        {
            deck2[i] = half1[pile1_count];
            pile1_count++;
            pile = 2;
        }
        else
        {
            deck2[i] = half2[pile2_count];
            pile2_count++;
            pile = 1;
        }
    }
    int a[card_num];
    for (int i = 0; i < card_num; i++)
        a[i] = *deck2[i];
    for (int i = 0; i < card_num; i++)
        *deck[i] = a[i];
}
void print(int *deck[])
{
    int i = 0;
    while (deck[i] != NULL)
    {
        printf("%d ", *deck[i]);
        i++;
    }
}
/*int main()
{
    int card[10000];
    int *deck[10000];
    int index = 0;

    while (scanf("%d", &(card[index])) != EOF)
    {
        deck[index] = &(card[index]);
        index++;
    }
    deck[index] = NULL;
    shuffle(deck);
    print(deck);
    return 0;
}*/