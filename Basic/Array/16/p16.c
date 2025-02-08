#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[1000] = {0}, odd[1000] = {0}, even[1000] = {0};
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
        {
            even[evens] = i;
            evens++;
        }
        else
        {
            odd[odds] = i;
            odds++;
        }
    for (int i = 0; i < odds; i++)
        if (i == odds - 1)
            printf("%d\n", a[odd[i]]);
        else
            printf("%d ", a[odd[i]]);
    for (int i = 0; i < evens; i++)
        if (i == evens - 1)
            printf("%d\n", a[even[i]]);
        else
            printf("%d ", a[even[i]]);
}