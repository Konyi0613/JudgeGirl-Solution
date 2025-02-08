#include <stdio.h>
#include <stdlib.h>
typedef struct vertex
{
    int x;
    int y;
} Vertex;
int quarant (Vertex v)
{
    if (v.x > 0 && v.y > 0)
        return 1;
    if (v.x < 0 && v.y > 0)
        return 2;
    if (v.x < 0 && v.y < 0)
        return 3;
    return 4;
}
 
int segment(Vertex v1, Vertex v2)
{
    int quarant1 = quarant(v1), quarant2 = quarant(v2);
    // find x
    if (quarant1 == quarant2)
        return 1;
    else if (abs(quarant1 % 4 - quarant2 % 4) == 1 || abs(quarant1 % 4 - quarant2 % 4) == 3)
        return 2;
    else
    {
        int tmp = 3;
        if ((v1.y) * (v2.x - v1.x) == (v2.y - v1.y) * v1.x)
            tmp --;
        return tmp;
    }
 
    //find y
}
 
 
 
int main()
{
    int n;
    scanf("%d", &n);
    Vertex vertex[n];
    for (int i = 0; i < n; i++)
        scanf("%d%d", &vertex[i].x, &vertex[i].y);
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += segment(vertex[0], vertex[i]);
    for (int i = 1; i < n - 1; i++)
        ans += segment(vertex[i], vertex[i+1]);
    printf("%d", ans);
}