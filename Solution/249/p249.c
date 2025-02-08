#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
typedef struct employee
{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
} Employee;

int search_name(char first_name[], char last_name[], Employee employee[], int n)
{
    for (int i = 0; i < n; i++)
        if (strcmp(first_name, employee[i].first_name) == 0 && strcmp(last_name, employee[i].last_name) == 0)
            return i;
    return -1;
}
int search_id(int id, Employee employee[], int n)
{
    for (int i = 0; i < n; i++)
        if (employee[i].id == id)
            return i;
    return -1;
}

int search_supervisor(int index1, int index2, Employee employee[], int counter, int n) // 2 is 1's supervisor
{
    if (employee[index2].id == employee[index1].boss_id)
        return 1;
    if (counter == n - 1)
        return -1;
    int boss_index = search_id(employee[index1].boss_id, employee, n);
    assert(boss_index != -1);
    return search_supervisor(boss_index, index2, employee, counter + 1, n);
}

int main()
{
    int n;
    scanf("%d", &n);
    Employee employee[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &employee[i].id);
        scanf("%s", employee[i].first_name);
        scanf("%s", employee[i].last_name);
        scanf("%d", &employee[i].boss_id);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        bool found = false;
        char p1_first[32], p1_last[32], p2_first[32], p2_last[32];
        scanf("%s%s%s%s", p1_first, p1_last, p2_first, p2_last);
        int p1_index = search_name(p1_first, p1_last, employee, n), p2_index = search_name(p2_first, p2_last, employee, n);
        assert(p1_index != -1 && p2_index != -1);
        if (search_supervisor(p1_index, p2_index, employee, 1, n) == 1)
        {
            printf("subordinate\n");
            found = true;
        }
        else if (search_supervisor(p2_index, p1_index, employee, 1, n) == 1)
        {
            printf("supervisor\n");
            found = true;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (j != p1_index && j != p2_index && search_supervisor(p1_index, search_id(employee[j].id, employee, n), employee, 1, n) == 1 && search_supervisor(p2_index, search_id(employee[j].id, employee, n), employee, 1, n) == 1)
                {
                    printf("colleague\n");
                    found = true;
                    break;
                }
            }
            if (!found)
                printf("unrelated\n");
        }
    }
}