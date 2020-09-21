/*
	00272 TEX Quotes
*/
#define _CRT_SECURE_NO_WARNINGS
#define REP(i,a,b) for(int i = int(a); i<= int(b); i++)
#include <stdio.h>
#include <string.h>

int main() {
	// 10000이하에서 Runtime Error 
	char a[50000];
	scanf("%[^EOF]s", a); // EOF전까지 문자열 입력받기
	bool chk1 = true;

	REP(i, 0, strlen(a)){
		if ((a[i] == '"') && (chk1 == true)) {
			printf("%s", "``");
			chk1 = !chk1;
		}
		else if ((a[i] == '"') && (chk1 == false)) {
			printf("%s", "''");
			chk1 = !chk1;
		}
		else printf("%c", a[i]);
	}

	return 0;
}