#include <stdio.h>
#include "GPA_calculation.h"

void GPA_calculation(struct Student all_student[], int N)
{
    int award_num = N / 20 + 1;
    if (N % 20 == 0)
        award_num--;
    int rank[N]; // if rank[i] = j, then student[j] has i^th rank
    int ranked_people = 0;
    for (int i = 0; i < N; i++)
    {
        rank[i] = 0;
        double gpa = 0;
        all_student[i].N_credit = 0;
        for (int j = 0; j < all_student[i].N_class; j++)
        {
            double score = 0;
            if (all_student[i].all_class[j].score[0] == 'A')
                score = 4;
            else if (all_student[i].all_class[j].score[0] == 'B')
                score = 3;
            else if (all_student[i].all_class[j].score[0] == 'C')
                score = 2;
            if (all_student[i].all_class[j].score[1] == '+')
                score += 0.3;
            else if (all_student[i].all_class[j].score[1] == '-')
                score -= 0.3;
            gpa += (score * (all_student[i].all_class[j].academic_credit));
            all_student[i].N_credit += all_student[i].all_class[j].academic_credit;
        }
        gpa /= all_student[i].N_credit;
        all_student[i].GPA = gpa;
        int new_rank = 0;
        for (int j = 0; j < ranked_people; j++)
        {
            if (all_student[i].GPA > all_student[rank[j]].GPA)
                break;
            new_rank++;
        }
        for (int j = ranked_people; j > new_rank; j--)
            rank[j] = rank[j - 1];
        rank[new_rank] = i;
        ranked_people++;
    }
    int awarded_people = 0;
    int i = 0;
    while (i < award_num)
    {
        if (all_student[rank[i]].N_credit >= 15 && all_student[rank[i]].GPA >= 3.38)
        {
            printf("%d %s %f\n", i + 1, all_student[rank[i]].name, all_student[rank[i]].GPA);
            awarded_people++;
        }
        i++;
    }
}
/*
int main(int argc, char const *argv[])
{
    struct Student all_student[10000];
    int N, i, j;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s%d", all_student[i].name, &all_student[i].N_class);
        for (j = 0; j < all_student[i].N_class; j++)
        {
            scanf("%d%s", &all_student[i].all_class[j].academic_credit, all_student[i].all_class[j].score);
        }
        all_student[i].N_credit = 0;
        all_student[i].GPA = 0.0;
    }

    GPA_calculation(all_student, N);

    return 0;
}
*/
