#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

// #define MAIN

void mergeString(char **P, char L[26], char *A)
{
    while (1)
    {
        uint8_t j = 0;
        uint8_t min_index = 255;
        while (P[j] != NULL)
        {
            if (*P[j] == '\0')
            {
                j++;
                continue;
            }
            if (min_index == 255)
                min_index = j;
            if (strchr(L, *P[min_index]) - strchr(L, *P[j]) > 0)
                min_index = j;
            j++;
        }
        if (min_index == 255)
            return;
        *A = *P[min_index];
        A++;
        P[min_index]++;
    }
}

#ifdef MAIN
#include <stdlib.h>
 
int main(){
    int n;
    scanf("%d", &n);
    char* P[n + 1];
    char* freeP[n];
    int lengthA = 0;
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d", &m);
        P[i] = (char*)malloc((m + 1) * sizeof(char));
        scanf("%s", P[i]);
        // We may change the pointers in P in mergeString,
        // so we make a copy of P to free them in the last step.
        freeP[i] = P[i];
        lengthA += m;
    }
    P[n] = NULL;
 
    char L[26], buffer[30];
    scanf("%s", buffer);
    strncpy(L, buffer, 26);
 
    char* A = (char *)malloc((lengthA + 1) * sizeof(char));
    mergeString(P, L, A);
    A[lengthA] = '\0';
    printf("%s\n", A);
 
    // free the memory
    for(int i = 0; i < n; i++){
        free(freeP[i]);
    }
    free(A);
}
#endif