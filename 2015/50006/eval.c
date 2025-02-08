#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "eval.h"
//#define MAIN

int eval(int exp[]) {
    /* add your code */
    int result = 0, multiply = exp[1], last_op = 1;
    for (int i = 2; i < exp[0] + 1; i += 2) {
        if (exp[i] == 1 || exp[i] == 2) {
            if (last_op == 1)
                result += multiply;  
            else
                result -= multiply;
            multiply = exp[i + 1]; 
            last_op = exp[i];
        } else if (exp[i] == 3 || exp[i] == 4){
            if (exp[i] == 3)
                multiply *= exp[i + 1];
            else {
                if (exp[i + 1] == 0)
                    return -2147483647;
                else
                    multiply /= exp[i + 1];
            }
        } else
            return -2147483646;
    }
    if (last_op == 1)
        result += multiply;  
    else
        result -= multiply;
    return result;
}

#ifdef MAIN
int main() {
    int exp[1024];
    memset(exp, -1, sizeof(exp));
    scanf("%d", &exp[0]);
    for (int i = 1; i <= exp[0]; i++)
        scanf("%d", &exp[i]);
    int ret = eval(exp);
    printf("%d\n", ret);
    return 0;
}
#endif
