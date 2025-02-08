#include <stdio.h>
#include <stdbool.h>

double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[])
{
    int id = 0;
    double sum = 0;
    while (orderItemID[id] != 0)
    {
        int search_id = 0;
        bool found = false, onsale = false;
        while (itemID[search_id] != 0)
        {
            if (orderItemID[id] == itemID[search_id])
            {
                found = true;
                int onsale_id = 0;
                while (onSaleItemID[onsale_id] != 0)
                {
                    if (onSaleItemID[onsale_id] == itemID[search_id])
                    {
                        onsale = true;
                        break;
                    }
                    onsale_id++;
                }
                break;
            }
            search_id++;
        }
        if (found)
        {
            if (onsale)
                sum += (orderQuantity[id] * price[search_id] * 0.8);
            else
                sum += (orderQuantity[id] * price[search_id]);
        }
        id++;
    }
    if (sum < 490)
        sum += 80;
    return sum;
}