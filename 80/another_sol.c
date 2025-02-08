#include<stdio.h>
int n, x1, x2, x3;
int y_1, y2, y3;
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d%d%d%d", &x1, &y_1, &x2, &y2, &x3, &y3);
        int a = (x1 - x2) * (x1 - x2) + (y_1 - y2) * (y_1 - y2), b = (x1 - x3) * (x1 - x3) + (y_1 - y3) * (y_1 - y3), c = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
        int mx = a > b && a > c ? a : b > a && b > c ? b : c;
        if(a == b || b == c || c == a)printf("isosceles\n");
        else if(a + b + c - mx == mx)printf("right\n");
        else if(a + b + c - mx < mx)printf("obtuse\n");
        else printf("acute\n");
    }
    return 0;
}