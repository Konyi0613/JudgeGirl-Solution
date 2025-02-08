#include <stdio.h>
#include <ctype.h>
char s[1048576];
char* trim(char *s) {
	char *q = s;
	while (*q)	q++;
	q--;
	while (isspace(*q))	*q = 0, q--;
	while (isspace(*s))	s++;
	return s;
}
int main() {
	while (fgets(s, 1048576, stdin)) {
		char *q = trim(s);
		puts(q);
	}
	return 0;
}
