#include <stdio.h>
#define MAXN 10000
// #define MAIN

int same_line(int dist[], int start, int end)
{
    if (start > end)
    {
        int tmp = start;
        start = end;
        end = tmp;
    }
    int distance = 0;
    for (int i = start - 1; i < end - 1; i++)
        distance += dist[i];
    return distance;
}

int stationDistance(int R_distance[],int G_distance[],int B_distance[],int G_origin,int G_destination,int startStation[],int endStation[])
{
    if (startStation[0] == endStation[0])
    {
        int id = startStation[0];
        int *ptr;
        if (id == 0)
            ptr = R_distance;
        else if (id == 1)
            ptr = G_distance;
        else
            ptr = B_distance;
        return same_line(ptr, startStation[1], endStation[1]);
    }
    int G_end = 0;
    while (G_distance[G_end] != 0)
        G_end++;
    G_end++;
    if ((startStation[0] == 0 && endStation[0] == 1) || (startStation[0] == 1 && endStation[0] == 0))
    {
        if (startStation[0] == 0 && endStation[0] == 1)
            return same_line(R_distance, startStation[1], G_origin) + same_line(G_distance, endStation[1], 1);
        else
            return same_line(R_distance, endStation[1], G_origin) + same_line(G_distance, startStation[1], 1);
    }
    else if ((startStation[0] == 1 && endStation[0] == 2) || (startStation[0] == 2 && endStation[0] == 1))
    {
        if (startStation[0] == 1 && endStation[0] == 2)
            return same_line(G_distance, startStation[1], G_end) + same_line(B_distance, endStation[1], G_destination);
        else
            return same_line(G_distance, endStation[1], G_end) + same_line(B_distance, startStation[1], G_destination);
    }
    else
    {
        if (startStation[0] == 0 && endStation[0] == 2)
            return same_line(R_distance, startStation[1], G_origin) + same_line(G_distance, 1, G_end) + same_line(B_distance, endStation[1], G_destination);
        else
            return same_line(B_distance, startStation[1], G_destination) + same_line(G_distance, 1, G_end) + same_line(R_distance, endStation[1], G_origin);
    }
}

#ifdef MAIN
int main(int argc, char const *argv[])
{
    int R_distance[MAXN]={0};
    int G_distance[MAXN]={0};
    int B_distance[MAXN]={0};
    int G_origin,G_destination;
    int startStation[2],endStation[2];
 
    int Rindex,Gindex,Bindex;
    Rindex =0;
    while(scanf("%d",&R_distance[Rindex])){
        if( R_distance[Rindex]==0){
            break;
        }
        Rindex++;
    }
    Gindex=0;
    while(scanf("%d",&G_distance[Gindex])){
        if( G_distance[Gindex]==0){
            break;
        }
        Gindex++;
    }   
    Bindex=0;
    while(scanf("%d",&B_distance[Bindex])){
        if( B_distance[Bindex]==0)
            break;
        Bindex++;
    }
    scanf("%d%d",&G_origin,&G_destination);
    scanf("%d%d",&startStation[0],&startStation[1]);
    scanf("%d%d",&endStation[0],&endStation[1]);
    int distanceSum =stationDistance(R_distance,G_distance,B_distance,G_origin,G_destination,startStation,endStation);
    printf("%d\n",distanceSum );
}
#endif