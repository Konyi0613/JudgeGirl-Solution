#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000
#define MAXS 50
#define MAXK 100

int daniel_stubborn(int path[MAXK], int used[MAXN],int k){
    for(int i=0;i<k;i++){
        if(used[path[i]] == 1) return 0;
    }
    return 1;
}

void addtoset(int used[MAXN], int path[MAXK], int k){
    for(int i=0;i<k;i++){
        used[path[i]] = 1;
    }
    return;
}

void delfromset(int used[MAXN], int path[MAXK], int k){
    for(int i=0;i<k;i++){
        used[path[i]] = 0;
    }
    return;
}

void add(int edge[MAXN][MAXS], int child_cnt[MAXN],int path[6000][MAXK], int* cnt, int traverse_path[], int k){
    for(int i=0;i<k;i++){
        path[*(cnt)][i] = traverse_path[i];
    }
    *cnt = *cnt + 1;
    return;
}

void copy_answer(int* bestsol, int best_path_index[MAXS], int ans, int cur_sol[MAXS]){
    for(int i=0;i<ans;i++){
        best_path_index[i] = cur_sol[i];
    }
    *bestsol = ans;
    return;
}

void rec(int i, int cnt, int path[6000][MAXK], int* bestsol, int best_path_index[MAXS], int ans, int cur_sol[MAXS],int used[MAXN],int k){
    if(i >= cnt){
        if(ans > *bestsol) copy_answer(bestsol, best_path_index, ans, cur_sol);
        return;
    }
    if(daniel_stubborn(path[i], used, k) == 1){
        cur_sol[ans] = i;
        ans++;
        addtoset(used, path[i], k);
        rec(i+1, cnt, path, bestsol, best_path_index, ans,cur_sol, used, k);
        delfromset(used, path[i], k);
        ans--;
        cur_sol[ans] = -1;
    }
    rec(i+1, cnt, path, bestsol, best_path_index, ans,cur_sol, used, k);
    
} 

void addpath(int edge[MAXN][MAXS], int child_cnt[MAXN], int layer, int path[6000][MAXK], int* cnt, int traverse_path[],int index, int k){
    traverse_path[layer] = index;
    if(layer >= k-1) {
        add(edge, child_cnt, path, cnt, traverse_path, k);
        return;
    }
    for(int i = 0; i < child_cnt[index]; i++){
        addpath(edge,child_cnt,layer+1,path,cnt,traverse_path,edge[index][i],k);
    }
    return;
}

void printsol(int path[6000][MAXK], int bestsol, int k, int best_path_index[MAXS]){
    for(int i=0;i<bestsol;i++){
        for(int j=0;j<k;j++){
            printf("%d ",path[best_path_index[i]][j]);
        }
        printf("\n");
    }
    return;
}

int main(){
    int k, n;
    scanf("%d %d",&k, &n);
    int e;
    int edge[MAXN][MAXS];
    int child_cnt[MAXN] = {0};
    scanf("%d", &e);
    for(int i = 0; i < e ;i++){
        int u,v;
        scanf("%d %d",&u, &v);
        edge[u][child_cnt[u]] = v;
        child_cnt[u]++;
    }

    int path[6000][MAXK];
    int cnt = 0;
    int used[MAXN] = {0};
    for(int i=0;i<n/k;i++){
        int traverse_path[MAXK] = {0};
        addpath(edge, child_cnt, 0, path, &cnt, traverse_path, i, k);
    }
    int bestsol = -1;
    int best_path_index[MAXS];
    int cur_sol[MAXS];
    for(int i=0;i<MAXS;i++){
        cur_sol[i] = -1;
    }
    rec(0, cnt, path, &bestsol, best_path_index, 0, cur_sol, used, k);
    printsol(path, bestsol, k, best_path_index);
    
    return 0;
}