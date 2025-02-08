#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "reservation.h"

// #define MAIN

Reservation *GetReservation(Reservation *head, int nP, int StartTime, int EndTime)
{
    if (head == NULL)
    {
        head = (Reservation *)malloc(sizeof(Reservation));
        head->nP = nP;
        head->StartTime = StartTime;
        head->EndTime = EndTime;
        head->next = NULL;
        return head;
    }
    Reservation *now = head;
    Reservation *last = NULL;
    while (now != NULL && now->StartTime < StartTime)
    {
        last = now;
        now = now->next;
    }
    Reservation *new = (Reservation *)malloc(sizeof(Reservation));
    new->nP = nP;
    new->StartTime = StartTime;
    new->EndTime = EndTime;
    if (last == NULL)
    {
        new->next = head;
        head = new;
    }
    else
    {
        new->next = now;
        last->next = new;
    }
    return head;
}

int ReserveRoom(RoomStatus List[], int nR, int nP, int StartTime, int EndTime)
{
    int found = 0;
    for (int id = 0; id < nR; id++)
    {
        if (List[id].capacity < nP)
            continue;
        if (List[id].reservation == NULL)
        {
            List[id].reservation = GetReservation(NULL, nP, StartTime, EndTime);
            found = 1;
            break;
        }
        Reservation *ptr = List[id].reservation;
        bool overlap = false;
        while (ptr != NULL)
        {
            if (StartTime < ptr->EndTime && EndTime > ptr->StartTime)
            {
                overlap = true;
                break;
            }
            ptr = ptr->next;
        }
        if (overlap)
            continue;
        found = 1;
        List[id].reservation = GetReservation(List[id].reservation, nP, StartTime, EndTime);
        break;
    }
    return found;
}

#ifdef MAIN
int main()
{
    int n = 3;
    RoomStatus list[n];
    for (int i = 0; i < n; i++)
    {
        list[i].capacity = i + 2;
        list[i].reservation = NULL;
    }
    int nP, sTime, eTime;
    while (scanf("%d %d %d", &nP, &sTime, &eTime) != EOF)
        printf("%d", ReserveRoom(list, n, nP, sTime, eTime));
    puts("");
    printf("---Room Status List---\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ---", list[i].capacity);
        for (Reservation *tmp = list[i].reservation; tmp != NULL; tmp = tmp->next)
            printf("->(%d:%d, %d)", tmp->nP, tmp->StartTime, tmp->EndTime);
        puts("");
    }
    printf("---      End       ---\n");
    return 0;
}
#endif