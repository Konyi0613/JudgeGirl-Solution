#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct people
{
    char lastname[80];
    char firstname[80];
    char ID[80];
    int salary;
    int age;
} People;

int main()
{
    int data_num;
    scanf("%d", &data_num);
    People people[data_num];
    for (int i = 0; i < data_num; i++)
    {
        scanf("%s", people[i].lastname);
        scanf("%s", people[i].firstname);
        scanf("%s", people[i].ID);
        scanf("%d", &people[i].salary);
        scanf("%d", &people[i].age);
    }
    int search_num;
    scanf("%d", &search_num);
    int now_search = 0;
    char item[50000][10];
    int item_count = 0;
    char input[10];
    while (now_search < search_num)
    {
        scanf("%s", input);
        if (strcmp(input, "select") == 0)
        {
            item_count = 0;
            continue;
        }
        else if (strcmp(input, "where") == 0)
        {
            char operand[10];
            char operator[3];
            char constant[81];
            scanf("%s%s%s", operand, operator, constant);
            int corresponding_index[data_num];
            int corresponding_count = 0;
            if (strcmp(operand, "lastname") == 0 || strcmp(operand, "firstname") == 0 || strcmp(operand, "ID") == 0)
            {
                // 0 = lastname, 1 = firstname, 2 = ID
                if (strcmp(operator, "==") == 0)
                {
                    if (strcmp(operand, "lastname") == 0)
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (strcmp(people[i].lastname, constant) == 0)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                    else if (strcmp(operand, "firstname") == 0)
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (strcmp(people[i].firstname, constant) == 0)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (strcmp(people[i].ID, constant) == 0)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                }
                else
                {
                    if (strcmp(operand, "lastname") == 0)
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (strcmp(people[i].lastname, constant) != 0)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                    else if (strcmp(operand, "firstname") == 0)
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (strcmp(people[i].firstname, constant) != 0)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (strcmp(people[i].ID, constant) != 0)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                }
            }
            else
            {
                int const_num = 0;
                int len = strlen(constant);
                for (int i = 0; i < len; i++)
                    const_num = (const_num * 10 + (constant[i] - '0'));
                if (strcmp(operator, ">") == 0)
                {
                    if (strcmp(operand, "salary") == 0)
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (people[i].salary > const_num)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (people[i].age > const_num)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                }
                else if (strcmp(operator, "<") == 0)
                {
                    if (strcmp(operand, "salary") == 0)
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (people[i].salary < const_num)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (people[i].age < const_num)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                }
                else
                {
                    if (strcmp(operand, "salary") == 0)
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (people[i].salary == const_num)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < data_num; i++)
                        {
                            if (people[i].age == const_num)
                            {
                                corresponding_index[corresponding_count] = i;
                                corresponding_count++;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < corresponding_count; i++)
            {
                for (int j = 0; j < item_count; j++)
                {
                    if (strcmp(item[j], "lastname") == 0)
                        printf("%s", people[corresponding_index[i]].lastname);
                    else if (strcmp(item[j], "firstname") == 0)
                        printf("%s", people[corresponding_index[i]].firstname);
                    else if (strcmp(item[j], "ID") == 0)
                        printf("%s", people[corresponding_index[i]].ID);
                    else if (strcmp(item[j], "salary") == 0)
                        printf("%d", people[corresponding_index[i]].salary);
                    else
                        printf("%d", people[corresponding_index[i]].age);
                    if (j != item_count - 1)
                        printf(" ");
                }
                printf("\n");
            }
            now_search++;
            continue;
        }
        strcpy(item[item_count], input);
        item_count++;
    }
}