#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include "classroom_arrangement.h"
// #define DEBUG
// #define MAIN

int time_previous(struct Time time1, struct Time time2)
{
    if (time1.hour < time2.hour || (time1.hour == time2.hour && time1.minute < time2.minute))
        return 1;
    else
        return 0;
}

int overlapse(struct Course course1, struct Course course2)
{
    if (time_previous(course1.start, course2.start) == 0)
    {
        struct Course tmp = course1;
        course1 = course2;
        course2 = tmp;
    }
    if (time_previous(course1.end, course2.start) == 0)
        return 1;
    else
        return 0;
}

void class_arrangement(int classnum, int coursenum, struct Classroom classrooms[], struct Course courses[])
{
    int course_in_classromm[classnum][5][25];
    int num_of_course_in_classroom[5][classnum];
    for (int i = 0; i < classnum; i++)
        for (int j = 0; j < 5; j++)
            num_of_course_in_classroom[j][i] = 0;

#ifdef DEBUG
    for (int i = 0; i < coursenum; i++)
        printf("num:%d, %d : %d, %d : %d\n", i, courses[i].start.hour, courses[i].start.minute, courses[i].end.hour, courses[i].end.minute);
#endif

    for (int i = 0; i < coursenum; i++)
    {
        int now_day = courses[i].day - 1;
        for (int j = 0; j < classnum; j++)
        {
            if (classrooms[j].capacity < courses[i].number_of_students)
                continue;
            bool isoverlapse = false;
            for (int k = 0; k < num_of_course_in_classroom[now_day][j]; k++)
            {
                if (overlapse(courses[i], courses[course_in_classromm[j][now_day][k]]) == 1)
                {
                    isoverlapse = true;
                    break;
                }
            }
            if (!isoverlapse)
            {
                course_in_classromm[j][now_day][num_of_course_in_classroom[now_day][j]] = i;
                num_of_course_in_classroom[now_day][j]++;
                break;
            }
        }
    }
#ifdef DEBUG
    for (int i = 0; i < classnum; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("classnum %d in day %d has:", i, j);
            for (int k = 0; k < num_of_course_in_classroom[j][i]; k++)
                printf(" %s", courses[course_in_classromm[i][j][k]].id);
            printf("\n");
        }
    }
#endif
    for (int i = 0; i < classnum; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = num_of_course_in_classroom[j][i] - 2; k >= 0; k--)
            {
                for (int l = 0; l <= k; l++)
                {
                    if (time_previous(courses[course_in_classromm[i][j][l]].start, courses[course_in_classromm[i][j][l + 1]].start) == 0)
                    {
                        int tmp = course_in_classromm[i][j][l];
                        course_in_classromm[i][j][l] = course_in_classromm[i][j][l + 1];
                        course_in_classromm[i][j][l + 1] = tmp;
                    }
                }
            }
        }
    }
#ifdef DEBUG
    printf("after sort: \n");
    for (int i = 0; i < classnum; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("classnum %d in day %d has:", i, j);
            for (int k = 0; k < num_of_course_in_classroom[j][i]; k++)
                printf(" %s", courses[course_in_classromm[i][j][k]].id);
            printf("\n");
        }
    }
#endif
    for (int i = 0; i < classnum; i++)
    {
        printf("%s :", classrooms[i].name);
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < num_of_course_in_classroom[j][i]; k++)
                printf(" %s", courses[course_in_classromm[i][j][k]].id);
        printf("\n");
    }
}

#ifdef MAIN
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct Classroom classrooms[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", classrooms[i].name, &classrooms[i].capacity);
    }

    struct Course courses[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%s %d:%d %d:%d %d %d", courses[i].id, &courses[i].start.hour, &courses[i].start.minute, &courses[i].end.hour, &courses[i].end.minute, &courses[i].number_of_students, &courses[i].day);
    }

    class_arrangement(n, m, classrooms, courses);

    return 0;
}
#endif