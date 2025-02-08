#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
//#define MAIN

struct Class {
    int credit, type, score;
    // type = 0 : compulsory, 1 : elective, 2 : others
};

struct Student {
    char id[4];
    int k;
    struct Class classes[10];
 
    // calculate values below by yourself
    double gpa_avg, comp_avg, elec_avg;
    int major, total;
};

int cmp(const void *p1, const void *p2)
{
    struct Student *s1 = (struct Student *)p1;
    struct Student *s2 = (struct Student *)p2;
    double eps = 0.000000009;
    if (s1->gpa_avg - s2->gpa_avg > eps)
        return 1;
    else if (fabs(s1->gpa_avg - s2->gpa_avg) < eps)
    {
        if (s1->comp_avg - s2->comp_avg > eps)
            return 1;
        else if (fabs(s1->comp_avg - s2->comp_avg) < eps)
        {
            if (s1->elec_avg - s2->elec_avg > eps)
                return 1;
            else if (fabs(s1->elec_avg - s2->elec_avg) < eps)
            {
                if (s1->major > s2->major)
                    return 1;
                else if (s1->major == s2->major)
                {
                    if (s1->total > s2->total)
                        return 1;
                }
            }
        }
    }
    return -1;
}

void scholarship(int n, struct Student students[])
{
    for (int i = 0; i < n; i++)
    {
        students[i].major = 0;
        students[i].total = 0;
        double score_comp = 0, score_elec = 0, gpa_sum = 0;
        int comp_credit = 0, elec_credit = 0;
        for (int j = 0; j < students[i].k; j++)
        {
            students[i].total += students[i].classes[j].credit;
            if (students[i].classes[j].type != 2)
            {
                students[i].major += students[i].classes[j].credit;
                if (students[i].classes[j].type == 0)
                {
                    score_comp += (students[i].classes[j].credit * students[i].classes[j].score);
                    comp_credit += students[i].classes[j].credit;
                }
                else
                {
                    score_elec += (students[i].classes[j].credit * students[i].classes[j].score);
                    elec_credit += students[i].classes[j].credit;
                }
            }
            double gpa_now = 0;
            if( students[i].classes[j].score>=90) gpa_now = 4.3;
            else if( students[i].classes[j].score>=85 ) gpa_now = 4;
            else if( students[i].classes[j].score>=80 ) gpa_now = 3.7;
            else if( students[i].classes[j].score>=77 ) gpa_now = 3.3;
            else if( students[i].classes[j].score>=73 ) gpa_now = 3.0;
            else if( students[i].classes[j].score>=70 ) gpa_now = 2.7;
            else if( students[i].classes[j].score>=67 ) gpa_now = 2.3;
            else if( students[i].classes[j].score>=63 ) gpa_now = 2.0;
            else if( students[i].classes[j].score>=60 ) gpa_now = 1.7;
                gpa_sum += (students[i].classes[j].credit * gpa_now);
        }
        students[i].gpa_avg = gpa_sum / students[i].total;
        students[i].comp_avg = score_comp / comp_credit;
        students[i].elec_avg = score_elec / elec_credit;
        //printf("i = %d, gpa_avg = %f, comp_avg = %f, elec_avg = %f, major = %d, total = %d\n", 
        //i, students[i].gpa_avg, students[i].comp_avg, students[i].elec_avg, students[i].major, students[i].total);
    }
    qsort(students, n, sizeof(struct Student), cmp);
    int qualified_num = (n-1)/20+1;
    printf("%d\n", qualified_num);
    for (int i = 0; i < qualified_num; i++)
        printf("%s\n", students[n - 1 - i].id);
}

#ifdef MAIN
int main() {
    int n;
    scanf("%d", &n);
 
    struct Student students[505];
    for (int i = 0; i < n; i++) {
        scanf("%s", students[i].id);
        scanf("%d", &students[i].k);
 
        for (int j = 0; j < students[i].k; j++) {
            scanf("%d %d %d", &students[i].classes[j].credit, &students[i].classes[j].type, &students[i].classes[j].score);
        }
    }
 
    scholarship(n, students);
}
#endif