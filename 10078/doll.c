#include "doll.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define MAIN

Doll *newDoll(char top, char bottom)
{
    Doll *new = (Doll *)malloc(sizeof(Doll));
    new->top = top;
    new->bottom = bottom;
    new->interior = NULL;
    return new;
}
void package(Doll *outer, Doll *inter)
{
    outer->interior = inter;
    return;
}
void get_string(Doll *doll, char *destination, int *layer)
{
    if (doll == NULL)
        return;
    destination[*layer] = doll->top;
    *layer = *layer + 1;
    get_string(doll->interior, destination, layer);
    destination[*layer] = doll->bottom;
    *layer = *layer + 1;
    return;
}
const char *doll_c_str(Doll *doll)
{
    int length = 0;
    Doll *ptr = doll;
    while (ptr != NULL)
    {
        length += 2;
        ptr = ptr->interior;
    }
    char *string = (char *)malloc((length + 1) * sizeof(char));
    int layer = 0;
    get_string(doll, string, &(layer));
    string[length] = '\0';
    return string;
}

#ifdef MAIN
int main()
{
    Doll *dolls[3];
    dolls[0] = newDoll('<', '~');
    dolls[1] = newDoll('(', ')');
    dolls[2] = newDoll('@', '>');
    package(dolls[1], dolls[2]);
    package(dolls[0], dolls[1]);
    printf("%s\n", doll_c_str(dolls[0]));
    return 0;
}
#endif