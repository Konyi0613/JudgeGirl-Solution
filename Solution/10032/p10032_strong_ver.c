#define MAXLEN 505
 
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define debug

struct slice{
    char* data;
    int index;
};
 
int compare(const void *a, const void *b);
 
int main(){
    char input[MAXLEN];
    scanf("%s", input);
 
    int input_len = strlen(input);
    //紀錄每個字母為首的輸出順序
    struct slice *sort = (struct slice*)malloc(sizeof(struct slice) * input_len);
    for(int i = 0; i < input_len; i++){
        sort[i].index = i;
        sort[i].data = input + i;
    }
 
    #ifdef debug
    printf("\n=====\n");
    printf("before sort\n");
    for(int i = 0; i < input_len; i++)
        printf("%s\n", sort[i].data);
    printf("=====\n");
    #endif
 
    qsort(sort, input_len, sizeof(struct slice), compare);
 
    #ifdef debug
    printf("\n=====\n");
    printf("after sort\n");
    for(int i = 0; i < input_len; i++)
        printf("%s %d\n", sort[i].data, sort[i].index);
    printf("=====\n");
    #endif
 
 
    for(int i = 0; i < input_len; i++){
        //以此為頭的子字串輸出
        int index = sort[i].index;
        int len = input_len - index;
 
        for(int j = 1; j <= len; j++){
            char output[MAXLEN];
            strncpy(output, input + index, j);
            output[j] = '\0';
 
            #ifdef debug
                printf("sort[i - 1] %s\n", sort[i - 1].data);
            #endif
 
            //避免重複輸出 往前找相同開頭的其他子字串 相同則不輸出
            if(i > 0 && strncmp(sort[i - 1].data, output, j) == 0)
                continue;
            else
                printf("%s\n", output);
        }
 
    }   
 
    free(sort);
    return 0;
}
 
 
int compare(const void *a, const void *b){
    struct slice* data1 = (struct slice*)a;
    struct slice* data2 = (struct slice*)b;
 
    return strcmp(data1->data, data2->data); 
}