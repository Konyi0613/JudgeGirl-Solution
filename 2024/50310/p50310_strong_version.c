#include <stdio.h>
 
typedef long long ll;
 
void swap(int* a, int* b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
 
void sort(int s[], int t[], int l[], int p[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (l[i] < l[j]) {
                swap(&s[i], &s[j]);
                swap(&t[i], &t[j]);
                swap(&p[i], &p[j]);
                swap(&l[i], &l[j]);
            }
        }
    }
}
 
int conflict(int s1, int t1, int s2, int t2) {
    return !(t1 < s2 || t2 < s1);
}
 
void replace(int a[], int b[], int N) {
    for (int i = 0; i < N; i++) {
        a[i] = b[i];
    }
}
 
void dfs(int p[], int id[], int t[], int overlap[8][8], int curt, int* anst, int left, int r[], int ansr[], int i, int N, int M) {
    if (curt + left < *anst) return;
    if (i == M) {
        if (curt > *anst) {
            *anst = curt;
            replace(ansr, r, M);
            return;
        }
 
        int anscnt[N], curcnt[N];
        for (int j = 0; j <= N; j++) anscnt[j] = curcnt[j] = 0;
        for (int j = 0; j < M; j++) {
            curcnt[id[r[j]]]++;
            anscnt[id[ansr[j]]]++;
        }
 
        // printf("current list %d:\n", N);
        // for (int j = 0; j <= N; j++) {
            // printf("%d %d\n", curcnt[j], anscnt[j]);
        // }
 
        if (anscnt[0] < curcnt[0]) {
            replace(ansr, r, M);
            return;
        }
 
        for (int j = 1; j <= N; j++) {
            if (anscnt[j] != curcnt[j]) {
                if (anscnt[j] < curcnt[j]) replace(ansr, r, M);
                return;
            }
        }
 
        return;
    }
 
    left -= t[i];
 
    for (int j = p[i]; j <= N; j++) {
        int flg = 1;
        for (int k = 0; flg && k < i; k++) if (r[k] == j && overlap[i][k]) flg = 0;
        if (flg < 1) continue;
 
        r[i] = j;
        dfs(p, id, t, overlap, curt + t[i], anst, left, r, ansr, i + 1, N, M);
        r[i] = 0;
    }
 
    dfs(p, id, t, overlap, curt, anst, left, r, ansr, i + 1, N, M);
}
 
int main() {
    int N, M;
    int tt = 0;
    scanf("%d %d", &N, &M);
 
    int cap[N + 1], id[N + 1], anscnt[N + 1];
    cap[0] = id[0] = anscnt[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &cap[i]);
        id[i] = i;
        anscnt[i] = 0;
    }
 
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (cap[i] > cap[j]) swap(&cap[i], &cap[j]), swap(&id[i], &id[j]);
        }
    }
 
    int s[5][M], t[5][M], l[5][M], p[5][M], cnt[5];
    for (int i = 0; i < 5; i++) cnt[i] = 0;
    int w, sh, sm, th, tm, pp;
 
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d %d %d", &sh, &sm, &th, &tm, &pp, &w);
        --w;
        s[w][cnt[w]] = 60 * sh + sm, t[w][cnt[w]] = 60 * th + tm;
        l[w][cnt[w]] = t[w][cnt[w]] - s[w][cnt[w]] + 1;
 
        p[w][cnt[w]] = 1;
        while (p[w][cnt[w]] <= N && pp > cap[p[w][cnt[w]]]) p[w][cnt[w]]++;
        cnt[w]++;
    }
 
 
    int r[5][M], ansr[5][M];
 
    int ansval = 0;
    for (int i = 0; i < 5; i++) {
        int overlap[8][8];
        sort(s[i], t[i], l[i], p[i], cnt[i]);
 
        int all = 0;
        for (int j = 0; j < cnt[i]; j++) {
            r[i][j] = ansr[i][j] = 0;
            for (int k = 0; k < cnt[i]; k++) {
                overlap[j][k] = conflict(s[i][j], t[i][j], s[i][k], t[i][k]);
                if (j == k) overlap[j][k] = 0;
            }
 
            all += l[i][j];
        }
 
        dfs(p[i], id, l[i], overlap, ansval, &ansval, all, r[i], ansr[i], 0, N, cnt[i]);
    }
 
    printf("%d\n", ansval);
 
    for (int i = 0; i < 5; i++) {
        // printf("%d %d\n", i, cnt[i]);
        for (int j = 0; j < cnt[i]; j++) {
            // printf("%d ", ansr[i][j]);
            anscnt[id[ansr[i][j]]]++;
        }
        // printf("\n");
    }
 
    printf("%d\n", M - anscnt[0]);
    for (int i = 1; i <= N; i++) {
        printf("%d\n", anscnt[i]);
    }
}