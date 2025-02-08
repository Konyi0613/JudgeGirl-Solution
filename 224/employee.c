#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "employee.h"
// #define MAIN

void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id( Employee *set, int n, int id )
{
    for (int i = 0; i < n; i++)
        if (set[i].id == id)
            return &(set[i]);
    return NULL;
}
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name )
{
    for (int i = 0; i < n; i++)
        if (strcmp(set[i].first_name, first_name) == 0 && strcmp(set[i].last_name, last_name) == 0)
            return &(set[i]);
    return NULL;
}
Employee* find_root_boss( Employee *set, int n, Employee *employee )
{
    while (employee->boss_id != employee->id)
        employee = find_employee_by_id(set, n, employee->boss_id);
    return employee;
}
bool find(Employee *set, int n, Employee *A, Employee *B)
{
    Employee* root_boss = find_root_boss(set, n, A);
    while (A != root_boss)
    {
        if (A->boss_id == B->id)
            return true;
        A = find_employee_by_id(set, n, A->boss_id);
    }
    return false;
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B)
{
    if (find(set, n, A, B))
        return 1;
    else if (find(set, n, B, A))
        return 2;
    else if (find_root_boss(set, n, A) == find_root_boss(set, n, B))
        return 3;
    else
        return 4;
}


#ifdef MAIN 
int main()
{
    int n, m;
    int i;
    Employee *set = NULL;
 
    scanf("%d", &n);
    init_storage(&set, n);
    for ( i = 0 ; i < n ; i++ )
        scanf("%d %s %s %d", &(set[i].id), set[i].first_name, set[i].last_name, &(set[i].boss_id));
    char first_name_A[32], first_name_B[32];
    char last_name_A[32], last_name_B[32];
    Employee *A, *B;
    int type;
 
    scanf("%d", &m);
    for ( i = 0 ; i < m ; i++ )
    {
        scanf("%s %s", first_name_A, last_name_A);  
        A = find_employee_by_name(set, n, first_name_A, last_name_A);
 
        scanf("%s %s", first_name_B, last_name_B);  
        B = find_employee_by_name(set, n, first_name_B, last_name_B);
 
        type = check_relationship(set, n, A, B);
        switch(type){
            case 1:
                printf("subordinate\n"); break;
            case 2:
                printf("supervisor\n"); break;
            case 3:
                printf("colleague\n"); break;
            default:
                printf("unrelated\n"); break;
        }
    }
    free_storage(&set);
    return 0;
}
#endif