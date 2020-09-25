/*
2117. [모의 SW 역량테스트] 홈 방범 서비스
피드백 사항 정리
-> 논리 오류 확인할때는 로그를 활용할 것..
-> 마름모꼴 범위 구하는 방법은 abs(i3-i1) + abs(i4-i2)가 맞다.  abs(i3+i4-i1-i2)가 아님에 주의
*/

#include <iostream>
using namespace std;

#define REP(i,a,b) for(int i = int(a); i < int(b); i++)
int t, n, m, answer;

int main() {
	cin >> t;
	REP(index_t, 1, t + 1) {
		/*  입력  */
		n = 0, m = 0, answer = 0;
		cin >> n >> m;
		bool** map = new bool*[n];
		REP(i,0,n) map[i] = new bool[n];
		REP(i1,0,n) REP(i2,0,n) cin >> map[i1][i2];

		/* 알고리즘 구현부 */
		REP(i1, 0, n) REP(i2, 0, n) {
			int k = 0, value = 0, temp = 0;
			if (map[i1][i2] == true) { answer = max(answer, 1); temp += m; }
			while (true) {
				int count = 0;
				k++;
				REP(i3, 0, n) REP(i4, 0, n) {
					if (abs(i3-i1) + abs(i4-i2) == k) {
						if (map[i3][i4] == true) {temp += m;}}
					else if (abs(i3 - i1) + abs(i4 - i2) == k + 1) count++;
				}
				if (2 * k * k + 2 * k + 1 <= temp) { value = temp;}
				if ((2 * k * k + 6 * k + 5 - temp) >= count * m) break;
			}
			answer = max(answer, value/m );
		}
		/*  출력  */
		cout << '#' << index_t << ' ' << answer << '\n';
		REP(i, 0, n) delete[] map[i];
		delete[] map;
	}
	return 0;
}
