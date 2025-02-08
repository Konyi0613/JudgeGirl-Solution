void mergeString(char** P, char L[26], char* A){
	int n = 0;
	while(P[n] != 0) n++;
	int order[127];
	for(int i = 0; i < 26; i++){
		order[L[i]] = i;
	}
	order[0] = 26;

    int lengthA = 0;
	int find = 1;
	while(find){
		int i = 0;
		for(int j = 0; j < n; j++){
			if(order[P[j][0]] < order[P[i][0]]){
				i = j;
			}
		}
		find = P[i][0] != 0;
		if(find){
            A[lengthA] = P[i][0];
			P[i]++;
            lengthA++;
		}
	}
    A[lengthA] = '\0';
}