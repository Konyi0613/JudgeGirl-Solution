#include <stdio.h>
#include <stdlib.h>
#include "mergeString.h"

int main(){
	int n;
	scanf("%d", &n);
	char** P = (char**)malloc((n + 1) * sizeof(char*));
    int lengthA = 0;
	for(int i = 0; i < n; i++){
		int m;
		scanf("%d", &m);
        lengthA += m;
		P[i] = (char*)malloc((m + 1) * sizeof(char));
		scanf("%s", P[i]);
		P[i][m] = '\0';
	}
	P[n] = NULL;
	char L[26];
	scanf("%s", L);
    char* A = (char *)malloc((lengthA + 1) * sizeof(char));
	mergeString(P, L, A);
    A[lengthA] = '\0';
    printf("%s\n", A);
}
