#include <stdio.h>
#include <stdbool.h>

typedef struct course
{
    int students;
    int st_h;
    int st_m;
    int en_h;
    int en_m;
    int day;
    int length;
} Course;

bool is_overlap(Course *a, Course *b)
{
    if (a->st_h > b->en_h || a->en_h < b->st_h)
        return false;
    else if ((a->st_h == b->en_h && a->st_m > b->en_m) || (b->st_h == a->en_h && b->st_m > a->en_m))
        return false;
    else
        return true;
}

int cal_minute(Course a)
{
    return (a.en_h - a.st_h) * 60 + a.en_m - a.st_m + 1;
}

void find(Course *courses, int n, int m, int vis, int now_min, int *ans, int class[8], int ans_class[8], int room[8][8], int cap[8], int day)
{
    if (vis == m)
    {
        if (*ans < now_min)
        {
            *ans = now_min;
            for (int i = 0; i < n; i++)
                ans_class[i] = class[i];
        }
        else if (*ans == now_min)
        {
            for (int i = 0; i < n; i++)
            {
                if (class[i] > ans_class[i])
                {
                    *ans = now_min;
                    for (int j = 0; j < n; i++)
                        ans_class[j] = class[j];
                    break;
                }
                else if (ans_class[i] > class[i])
                {
                    break;
                }
            }
        }
        return;
    }
    int left_minute = 0;
    for (int i = vis; i < m; i++)
        left_minute += courses[i].length;
    if (*ans > now_min + left_minute)
        return;

    find(courses, n, m, vis + 1, now_min, ans, class, ans_class, room, cap, day);
    for (int i = 0; i < n; i++)
    {
        if (cap[i] >= courses[vis].students)
        {
            bool can = true;
            for (int j = 0; j < class[i] && can; j++)
            {
                if (is_overlap(&courses[room[i][j]], &courses[vis]))
                {
                    can = false;
                }
            }
            if (can)
            {
                room[i][class[i]] = vis;
                class[i]++;
                find(courses, n, m, vis + 1, now_min + courses[i].length, ans, class, ans_class, room, cap, day);
                class[i]--;
            }
        }
    }
}

int main()
{
    int room[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            room[i][j] = -1;
        }
    }
    int cap[8], class[8] = {0};
    int ans_class[8] = {0};
    Course courses[6][8];
    int left_minute[6] = {0};
    int n, m;
    int course_per_day[6] = {0};

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &cap[i]);
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d, e, f;
        scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
        courses[f][course_per_day[f]].st_h = a;
        courses[f][course_per_day[f]].st_m = b;
        courses[f][course_per_day[f]].en_h = c;
        courses[f][course_per_day[f]].en_m = d;
        courses[f][course_per_day[f]].students = e;
        int t = cal_minute(courses[f][course_per_day[f]]);
        courses[f][course_per_day[f]].length = t;
        course_per_day[f]++;
    }
    int ans = 0;
    int final = 0, sum = 0;
    int final_class[8] = {0};
    for (int day = 1; day <= 5; day++)
    {
        find(courses[day], n, course_per_day[day], 0, 0, &ans, class, ans_class, room, cap, day);
        final += ans;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            final_class[i] += ans_class[i];
            ans_class[i] = 0;
            class[i] = 0;
        }
    }
    printf("%d\n", final);
    for (int i = 0; i < n; i++)
        sum += final_class[i];
    printf("%d\n", sum);
    for (int i = 0; i < n; i++)
        printf("%d\n", final_class[i]);
    return 0;
}