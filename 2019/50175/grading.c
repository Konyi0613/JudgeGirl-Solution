#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grading.h"
// #define DEBUG
// #define MAIN
#define maxL 1000

int compare1(const void *sub1, const void *sub2)
{
    Submission *sb1 = (Submission *)sub1;
    Submission *sb2 = (Submission *)sub2;
    return (sb1->studentID - sb2->studentID);
}

int compare2(const void *sub1, const void *sub2)
{
    Submission *sb1 = (Submission *)sub1;
    Submission *sb2 = (Submission *)sub2;
    return (sb1->subID - sb2->subID);
}

int compare3(const void *gd1, const void *gd2)
{
    int grade1 = *((int *)gd1);
    int grade2 = *((int *)gd2);
    return (grade2 - grade1);
}

void grading(char answer[10][maxL], Submission *sub, int num_of_submission)
{
    qsort(sub, num_of_submission, sizeof(Submission), compare1);
#ifdef DEBUG
    for (int i = 0; i < num_of_submission; i++)
        printf("studentID: %d, subID: %d\n", sub[i].studentID, sub[i].subID);
#endif
    int people = 1;
    int pre_people = sub[0].studentID;
    for (int i = 0; i < num_of_submission; i++)
        if (sub[i].studentID != pre_people)
        {
            people++;
            pre_people = sub[i].studentID;
        }
#ifdef DEBUG
    printf("people: %d\n", people);
#endif
    int sub_num_per_person[people];
    pre_people = sub[0].studentID;
    sub_num_per_person[0] = 0;
    int people_count = 0;
    for (int i = 0; i < num_of_submission; i++)
    {
        if (sub[i].studentID == pre_people)
            sub_num_per_person[people_count]++;
        else
        {
            pre_people = sub[i].studentID;
            people_count++;
            sub_num_per_person[people_count] = 1;
        }
    }
#ifdef DEBUG
    for (int i = 0; i < people; i++)
        printf("sub_num_per_person[%d] = %d\n", i, sub_num_per_person[i]);
#endif
    Submission *ptr = sub;
    for (int i = 0; i < people; i++)
    {
        qsort(ptr, sub_num_per_person[i], sizeof(Submission), compare2);
        ptr += sub_num_per_person[i];
    }
#ifdef DEBUG
    for (int i = 0; i < num_of_submission; i++)
        printf("studentID: %d, subID: %d\n", sub[i].studentID, sub[i].subID);
#endif
    int grade[num_of_submission];
    for (int i = 0; i < num_of_submission; i++)
    {
        grade[i] = 0;
        for (int j = 0; j < 10; j++)
        {
            char *ptr1 = &(answer[j][0]);
            char *ptr2 = &(sub[i].outputs[j][0]);
            if (strcmp(ptr1, ptr2) == 0)
                grade[i] += 10;
        }
    }
#ifdef DEBUG
    for (int i = 0; i < num_of_submission; i++)
        printf("grade[%d] = %d \n", i, grade[i]);
#endif
    ptr = sub;
    people_count = 0;
    for (int i = 0; i < people; i++)
    {
        for (int j = 0; j < sub_num_per_person[i]; j++)
            printf("Student %d gets %d with Submission %d.\n", ptr[j].studentID, grade[people_count + j], ptr[j].subID);
        qsort(&(grade[people_count]), sub_num_per_person[i], sizeof(int), compare3);
        printf("Student %d gets %d in this exam.\n", ptr[0].studentID, grade[people_count]);
        if (i != people - 1)
        {
            people_count += sub_num_per_person[i];
            ptr += sub_num_per_person[i];
        }
    }
}
#ifdef MAIN
int main()
{
    char answer[10][maxL];
    int num_of_submission;
    Submission *sub;

    for (int i = 0; i < 10; i++)
    {
        scanf("%s", answer[i]);
    }

    scanf("%d", &num_of_submission);

    sub = (Submission *)malloc(num_of_submission * sizeof(Submission));
    for (int i = 0; i < num_of_submission; i++)
    {
        scanf("%d %d", &sub[i].subID, &sub[i].studentID);
        for (int j = 0; j < 10; j++)
        {
            scanf("%s", sub[i].outputs[j]);
        }
    }
    grading(answer, sub, num_of_submission);
}
#endif