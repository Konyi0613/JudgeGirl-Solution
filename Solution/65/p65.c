#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

typedef struct exp{
    long long value;
    int next;
} Exp;

long long compute(char number[51]){
    int length = strlen(number);
    long long value = 0;
    for(int i=0;i<length;i++){
        value = value*10 + number[i] - '0';
    }
    return value;
}

Exp operation(char operator[MAX][51],int start){
    if(isdigit(operator[start][0])){
        long long number = compute(operator[start]);
        return (Exp){number,start+1};
    }
    char op[20];
    Exp e1,e2;
    if(strcmp(operator[start],"(") == 0){
        start++;
        strcpy(op,operator[start]);
        e1 = operation(operator,start+1);
        e2 = operation(operator,e1.next);
    }

    //printf("%s %lld %lld\n",op,e1.value,e2.value);

    if(strcmp(op,"+") == 0)
        return (Exp){e1.value + e2.value,e2.next+1};
    else if(strcmp(op,"-") == 0)
        return (Exp){e1.value - e2.value,e2.next+1};
    else if(strcmp(op,"*") == 0)
        return (Exp){e1.value * e2.value,e2.next+1};
    else if(strcmp(op,"/") == 0)
        return (Exp){e1.value / e2.value,e2.next+1};
}

int main(){
    char operator[MAX][51];
    int index = 0;
    char flag;
    while(scanf("%s%c",operator[index],&flag)){
        index++;
        if(flag == '\n')
            break;
    }
    char variable[33];
    char value[20];
    while(scanf("%s = %s",variable,value) != EOF){
        for(int i=0;i<index;i++){
            if(strcmp(operator[i],variable) == 0){
                strcpy(operator[i],value);
            }
        }
    }
    Exp e = operation(operator,0);
    printf("%lld\n",e.value);
    return 0;
}