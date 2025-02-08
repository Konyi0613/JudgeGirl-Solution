#include <stdio.h>
#include <string.h>
int seeklarge(int check[17576]){
    int maxindex=0,max=check[0];
    for(int i=0;i<17576;i++){
        if(check[i] > max){
            maxindex = i;
            max = check[i];
        }
    }
    return maxindex;
}
void printlarge(int check[17576],int index){
    index++;
    char a,b,c;
    c = index % 26 + 'a';
    b = (index/26) % 26 + 'a';
    a = index /(26*26) + 'a';
    printf("%c%c%c\n",a,b,c);
}

int main(){
    int check[17576]={0}; 
    char input[100];
    while(scanf("%s",input) != EOF){
        int length = strlen(input);
        for(int i=0;i<=length-3;i++){
            int first,second,third;
            first = (input[i] - 'a') % 26;
            second = (input[i+1] - 'a') % 26;
            third = (input[i+2] - 'a') % 26;
            int index = first*26*26+second*26+third;
            check[index-1]++;
        }
    }
    for(int i=0;i<3;i++){
        int max;
        max = seeklarge(check);
        printlarge(check,max);
        check[max] = 0;
    }
    return 0;
}