#include <stdio.h>
#include "map.h"

void initMap(Map *m){
    m->end = 0;
    return;
}

int main(){
    Map m;
    initMap(&m);
    int i,n,op,value;
    char key[25];
    
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%s %d", key, &value);
            insert(&m, key, value);
        }
        else if(op == 2){
            scanf("%s", key);
            printf("%d\n",delete(&m, key));
        }
        else{
            scanf("%s", key);
            printf("%d\n",query(&m, key));
        }
    }
    
    return 0;
}