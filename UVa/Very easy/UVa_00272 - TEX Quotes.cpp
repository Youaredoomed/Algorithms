/*
	00272 TEX Quotes
*/
#define _CRT_SECURE_NO_WARNINGS
#define REP(i,a,b) for(int i = int(a); i<= int(b); i++)
#include <stdio.h>
#include <string.h>

int main() {
	// 10000���Ͽ��� Runtime Error 
	char a[50000];
	scanf("%[^EOF]s", a); // EOF������ ���ڿ� �Է¹ޱ�
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