/*
UVA 11172 - Relational Operator


*/
#define _CRT_SECURE_NO_WARNINGS
#define REP(i, a, b) for(int i =int(a); i <= int(b); i++)
#include <stdio.h>

int main() {
	int tc, a, b;
	scanf("%d", &tc);

	REP(index, 1, tc) {
		scanf("%d %d", &a, &b);
		if (a > b) printf("%c", '>');
		else if (a < b) printf("%c", '<');
		else if (a == b) printf("%c", '=');
	}

	return 0;
}