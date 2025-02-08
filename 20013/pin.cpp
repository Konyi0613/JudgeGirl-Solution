#include <bits/stdc++.h>
#include <random>
using namespace std;
double frandom() {
	return (double)(rand()%10) / 2;
}
double mrandom() {
	return (rand() * rand())%10;
}
int main() {
    srand(time(NULL));
    int testcase = 20;
    while (testcase--) {
		int n = 10;
		int m = (rand()%30)%n+1;
		printf("%d %d\n", n, m);

		set<int> S;
		for (int i = 0; i < n; i++) {
			while (1) {
				int x = rand()%10000+1;
				if (S.count(x) == 0) {
					S.insert(x);
					break;
				}
			}
		}
		for (auto e : S) {
			printf("%d", e), n--;
			printf("%c", " \n"[n==0]);
		}
	}
    return 0;
}
