#include <stdio.h>
#define MAX 17
 
void print(int matrix[],int r,int c){
    for(int i=0;i<r*c;i++){
        printf("%d",matrix[i]);
        if(i % c == (c-1))
            printf("\n");
        else
            printf(" ");
    }
}
 
void copy(int matrix[],int answer[],int r,int c){
    for(int i=0;i<r*c;i++)
        answer[i] = matrix[i];
}

int fill(int r,int c,int row[],int column[],int matrix[],int answer[],int index,int used[]){
    int a = index / c, b = index % c;
    if(b == 0 && a > 0 && row[a-1] != 0)
        return 0;
    if(index >= r*c){
        copy(matrix,answer,r,c);
        return 1;
    }
    for(int i=1;i<=r*c;i++){
        if(used[i] == 0){
            if(row[a] - i >= 0 && column[b] - i >= 0){
                row[a] -= i;
                column[b] -= i;
                matrix[index] = i; 
                used[i] = 1;
                if(fill(r,c,row,column,matrix,answer,index+1,used) == 1)
                    return 1;
                row[a] += i;
                column[b] += i;
                used[i] = 0;
            }
            else
                return 0;
        }
    }
    return 0;
}
 
int main(){
    int r,c;
    int row[MAX],column[MAX];
    while(scanf("%d%d",&r,&c) != EOF){
        for(int i=0;i<r;i++)
            scanf("%d",&row[i]);
        for(int i=0;i<c;i++)
            scanf("%d",&column[i]);
        int matrix[MAX] = {0}, answer[MAX] = {0}, used[MAX] = {0};
        fill(r,c,row,column,matrix,answer,0,used);
        if(answer[0] == 0)
            printf("no solution\n");
        else
            print(answer,r,c);
    }
    return 0;
}