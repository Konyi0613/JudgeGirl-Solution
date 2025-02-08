#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// #define DEBUG
// #define DEBUG1

typedef struct time
{
    int hour;
    int minute;
} Time;

typedef struct classrooom
{
    char name[100];
    int capacity;
} Classroom;

typedef struct course
{
    char name[100];
    Time start;
    Time end;
    int enrolled_people;
    int day;
} Course;

bool time_previous(Time t1, Time t2)
{
    if (t1.hour < t2.hour || (t1.hour == t2.hour && t1.minute < t2.minute))
        return true;
    else
        return false;
}

bool overlapse(Course c1, Course c2)
{
    if (time_previous(c2.start, c1.start))
    {
        Course tmp = c1;
        c1 = c2;
        c2 = tmp;
    }
    if (time_previous(c2.start, c1.end) || (c2.start.hour == c1.end.hour && c2.start.minute == c1.end.minute))
        return true;
    else
        return false;
}

bool can_put(int classroom_num, int course_num, Classroom classroom[classroom_num],
             Course course[course_num], int course_id, int classroom_id, int class_in_classroom[5][classroom_num][8], int class_in_classroom_num[5][classroom_num])
{
    int now_day = course[course_id].day;
    if (course[course_id].enrolled_people > classroom[classroom_id].capacity)
        return false;
    for (int i = 0; i < class_in_classroom_num[now_day - 1][classroom_id]; i++)
    {
        Course target_course = course[class_in_classroom[now_day - 1][classroom_id][i]];
        if (overlapse(target_course, course[course_id]))
            return false;
    }
    return true;
}

int count_minute(Time t1, Time t2)
{
    if (time_previous(t2, t1))
    {
        Time tmp = t1;
        t1 = t2;
        t2 = tmp;
    }
    return (t2.hour * 60 + t2.minute - (t1.hour * 60 + t1.minute) + 1);
}

void smallest_time(int classroom_num, int course_num, Classroom classroom[classroom_num],
                   Course course[course_num], int *best, int index, int now_min, int class_in_classroom[5][classroom_num][8], int class_in_classroom_num[5][classroom_num])
{
    if (index == course_num)
    {
#ifdef DEBUG
        for (int j = 0; j < 5; j++)
            for (int i = 0; i < classroom_num; i++)
            {
                for (int k = 0; k < class_in_classroom_num[j][i]; k++)
                    printf("%d ", class_in_classroom[j][i][k]);
            }
        printf("now_min: %d\n", now_min);
#endif
        if (now_min > *best)
            *best = now_min;
        return;
    }
    smallest_time(classroom_num, course_num, classroom, course, best, index + 1, now_min, class_in_classroom, class_in_classroom_num);
    for (int i = 0; i < classroom_num; i++)
    {
#ifdef DEBUG1
        printf("capacity[%d]: %d\n", i, classroom[i].capacity);
#endif
        // put index
        if (can_put(classroom_num, course_num, classroom, course, index, i, class_in_classroom, class_in_classroom_num))
        {
#ifdef DEBUG1
            printf("can put %d \n", index);
#endif
            // modify
            int now_day = course[index].day;
            class_in_classroom[now_day - 1][i][class_in_classroom_num[now_day - 1][i]] = index;
            class_in_classroom_num[now_day - 1][i]++;
            int new_min = count_minute(course[index].start, course[index].end);
            smallest_time(classroom_num, course_num, classroom, course, best, index + 1, now_min + new_min, class_in_classroom, class_in_classroom_num);
            // recover
            class_in_classroom_num[now_day - 1][i]--;
        }
        // not put index
    }
}

int main()
{
    int classroom_num, course_num;
    scanf("%d%d", &classroom_num, &course_num);
    Classroom classroom[classroom_num];
    for (int i = 0; i < classroom_num; i++)
        scanf("%s%d", classroom[i].name, &classroom[i].capacity);
    Course course[course_num];
    for (int i = 0; i < course_num; i++)
        scanf("%s%d%d%d%d%d%d", course[i].name, &course[i].start.hour, &course[i].start.minute, &course[i].end.hour, &course[i].end.minute, &course[i].enrolled_people, &course[i].day);
    int best = 0;
    int class_in_classroom[5][classroom_num][8];
    int class_in_classroom_num[5][classroom_num];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < classroom_num; j++)
            class_in_classroom_num[i][j] = 0;
#ifdef DEBUG
    for (int i = 0; i < course_num; i++)
        printf("course[%d] length : %d\n", i, count_minute(course[i].start, course[i].end));
#endif
    smallest_time(classroom_num, course_num, classroom, course, &best, 0, 0, class_in_classroom, class_in_classroom_num);
    printf("%d", best);
}