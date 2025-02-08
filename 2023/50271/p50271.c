#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
bool reserved(char word[], char reserved_words[12][7])
{
    for (int i = 0; i < 12; i++)
        if (strcmp(word, reserved_words[i]) == 0)
            return true;
    return false;
}

int main()
{
    char reserved_words[12][7] = {"if", "else", "while", "for", "switch", "case", "break", "return", "void", "int", "float", "char"};
    char name[31][31];
    int name_num = 0;
    int frequency[31] = {0};
    char input[20000];
    while (scanf("%s", input) != EOF)
    {
        char delimeters[] = "()[],.+-*/%%!;{}=?><\\\n";
        char *start = strtok(input, delimeters);
        while (start != NULL)
        {
            if ((isalpha(*start) || *start == '_') && reserved(start, reserved_words) == false)
            {
                bool found = false;
                for (int i = 0; i < name_num; i++)
                {
                    if (strncmp(name[i], start, 24) == 0)
                    {
                        frequency[i]++;
                        found = true;
                        continue;
                    }
                }
                if (!found)
                {
                    strncpy(name[name_num], start, 24);
                    frequency[name_num]++;
                    name_num++;
                }
            }
            start = strtok(NULL, delimeters);
        }
    }
    for (int i = 0; i < name_num; i++)
        printf("%s %d\n", name[i], frequency[i]);
}