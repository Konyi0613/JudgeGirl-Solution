#include <stdio.h>
#include <stdbool.h>

#define DEBUG

typedef struct time
{
    int hour;
    int minute;
} Time;

typedef struct course
{
    Time start;
    Time end;
    int enrolled_people;
    int day;
    int length;
} Course;

bool time_previous(Time t1, Time t2)
{
    if (t1.hour < t2.hour || (t1.hour == t2.hour && t1.minute < t2.minute))
        return true;
    return false;
}

bool overlapse(Course c1, Course c2)
{
    if (time_previous(c1.start, c2.end) && time_previous(c2.start, c1.end))
        return true;
    else if ((c1.start.hour == c2.end.hour && c1.start.minute == c2.end.minute) || (c2.start.hour == c1.end.hour && c2.start.minute == c1.end.minute))
        return true;
    return false;
}
int count_length(Time t1, Time t2)
{
    return (t2.hour * 60 + t2.minute - t1.hour * 60 - t1.minute + 1);
}
void find_sol(int classroom_num, int course_num, int *capacity, Course *course,
              int *best_minute, int *best_course_num,
              int course_in_classroom[classroom_num][20], int *course_in_classroom_num, int *now_course_num, int now_min,
              int index, int now_day)
{
    if (index == course_num)
    {
#ifdef DEBUG
        if (now_day == 0)
        {
            printf("now_min: %d, best_min: %d\n", now_min, *best_minute);
            for (int i = 0; i < classroom_num; i++)
                printf("classroom[%d] has %d course\n", i, course_in_classroom_num[i]);
        }
#endif
        if (now_min > *best_minute)
        {
            *best_minute = now_min;
            for (int i = 0; i < classroom_num; i++)
                best_course_num[i] = now_course_num[i];
        }
        else if (now_min == *best_minute)
        {
            bool change = false;
            for (int i = 0; i < classroom_num; i++)
                if (now_course_num[i] > best_course_num[i])
                {
                    change = true;
                    break;
                }
                else if (now_course_num[i] < best_course_num[i])
                    break;
            if (change)
            {
#ifdef DEBUG
                printf("change\n");
#endif
                for (int i = 0; i < classroom_num; i++)
                    best_course_num[i] = now_course_num[i];
            }
        }
        return;
    }
    if ((course[index].day - 1) != now_day)
    {
        find_sol(classroom_num, course_num, capacity, course, best_minute,
                 best_course_num, course_in_classroom, course_in_classroom_num, now_course_num, now_min, index + 1, now_day);
        return;
    }
    int remaining_time = 0;
    for (int i = index; i < course_num; i++)
        if ((course[i].day - 1) == now_day)
            remaining_time += course[i].length;
    if (now_min + remaining_time < *best_minute)
        return;
    for (int i = 0; i < classroom_num; i++)
    {
        if (capacity[i] < course[index].enrolled_people)
            continue;
        bool is_overlapse = false;
        for (int j = 0; j < course_in_classroom_num[i]; j++)
            if (overlapse(course[index], course[course_in_classroom[i][j]]))
            {
                is_overlapse = true;
                break;
            }
        if (!is_overlapse)
        {
            course_in_classroom[i][course_in_classroom_num[i]] = index;
            course_in_classroom_num[i]++;
            now_course_num[i]++;
            find_sol(classroom_num, course_num, capacity, course, best_minute,
                     best_course_num, course_in_classroom, course_in_classroom_num, now_course_num, now_min + course[index].length, index + 1, now_day);
            course_in_classroom_num[i]--;
            now_course_num[i]--;
            continue;
        }
    }
    find_sol(classroom_num, course_num, capacity, course, best_minute,
             best_course_num, course_in_classroom, course_in_classroom_num, now_course_num, now_min, index + 1, now_day);
    return;
}

int main()
{
    int classroom_num, course_num;
    scanf("%d%d", &classroom_num, &course_num);
    int capacity[classroom_num];
    for (int i = 0; i < classroom_num; i++)
        scanf("%d", &capacity[i]);
    Course course[course_num];
    for (int i = 0; i < course_num; i++)
        scanf("%d%d%d%d%d%d", &course[i].start.hour, &course[i].start.minute,
              &course[i].end.hour, &course[i].end.minute, &course[i].enrolled_people, &course[i].day);
    for (int i = 0; i < course_num; i++)
        course[i].length = count_length(course[i].start, course[i].end);
    int course_in_classroom[classroom_num][20];
    int course_in_classroom_num[classroom_num];
    int now_course_num[classroom_num];
    int best_course_num[classroom_num];
    int best_minute = 0;
#ifdef DEBUG
    printf("declare\n");
    for (int i = 0; i < course_num; i++)
        printf("course[%d].length = %d\n", i, course[i].length);
#endif
    int total_course_num = 0;
    int total_best_minute = 0;
    int total_course[classroom_num];
    for (int i = 0; i < classroom_num; i++)
        total_course[i] = 0;
    for (int i = 0; i < 5; i++)
    {
        best_minute = 0;
        for (int j = 0; j < classroom_num; j++)
        {
            now_course_num[j] = 0;
            best_course_num[j] = 0;
            course_in_classroom_num[j] = 0;
        }
        find_sol(classroom_num, course_num, capacity, course, &(best_minute),
                 best_course_num, course_in_classroom, course_in_classroom_num, now_course_num, 0, 0, i);
        for (int j = 0; j < classroom_num; j++)
        {
            total_course_num += best_course_num[j];
            total_course[j] += best_course_num[j];
        }
        total_best_minute += best_minute;
    }
    printf("%d\n%d\n", total_best_minute, total_course_num);
    for (int i = 0; i < classroom_num; i++)
        printf("%d\n", total_course[i]);
}