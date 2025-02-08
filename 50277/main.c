#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
#define MAXNUM 20
void maxPerimeter(int num, char str[][MAXSIZE], int s1, int s2, int pos1, int pos2, 
                int* max, int p, int str0Pos){
    int found = 0;
    if(s2 != 0){
    for(int i = pos1; i < strlen(str[s1]); i++){
        for(int j = pos2; j < strlen(str[s2]); j++){
            if(str[s1][i] == str[s2][j]){
                found = 1;
                if(s1 == 0)
                    maxPerimeter(num, str, 1, 2, j, 0, max, 0, i);
                else{
                    //printf("%d length %d\n", s1, i-pos1+1);
                    //printf("%d %d\n", s1+1, (s2+1)%num);
                    maxPerimeter(num, str, s1+1, (s2+1)%num, j, 0, max, p+i-pos1, str0Pos);
                }
            }
        }
    }
    if(!found)  return;
    }
    else{
    int tmpP;
    for(int i = pos1; i < strlen(str[s1]); i++){
        for(int j = 0; j < str0Pos; j++){
            if(str[s1][i] == str[s2][j]){
                tmpP = p+(i-pos1)+(str0Pos-j);
                //printf("%d %d %d\n", p, (i-pos1+1), (str0Pos-j));
                //printf("%d\n", tmpP);
                if(*max < tmpP)
                    *max = tmpP;
            }
        }
    }
    }
    return;
}
int main(){
    char str[MAXNUM][MAXSIZE];
    int numStr = 0;
    while(scanf("%s", str[numStr]) != EOF){
        numStr++;
    };
    int max = 0;
    int *ptrMax = &max;
    maxPerimeter(numStr, str, 0, 1, 0, 0, ptrMax, 0, 0);
    printf("%d\n", *ptrMax);
}