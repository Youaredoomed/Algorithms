/*
	2112. [모의 SW 역량테스트] 보호 필름

*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define REP(i,a,b) for(int i = int(a); i < int(b); i++)
int t, d, w, k, answer, r, pw;
bool result, bs;
bool cells[13][20], c[13][20];
vector<int> comb;

bool test(bool film[13][20]) {
	int count, best = 0;
	REP(iw, 0, w) {
		count = 1; best = 0;
		REP(id, 0, d - 1) {
			if (film[id][iw] == film[id + 1][iw]) count++;
			else count = 1;
			best = max(best, count);
			if (best >= k) break;
		}
		if (best < k) return false;
	}
	return true;
}

void combination(int k) {
	if (result) return; // 재귀문 빠져나오기
	if (comb.size() == r) {
		REP(ipw, 0, pw) {
			REP(index_l, 0, r) {
				bs = (ipw >> index_l) & 1;
				REP(i, 0, w) c[comb[index_l] - 1][i] = bs;
			}
			result = test(c);
			if (result) { answer = r;  break; }
		}

		if (result) return;

		REP(index_l, 0, r) {
			REP(i, 0, w) c[comb[index_l] - 1][i] = cells[comb[index_l] - 1][i];
		}
	}
	else if (k == d + 1) {}
	else {
		comb.push_back(k);
		combination(k + 1);
		comb.pop_back();
		combination(k + 1);
	}
}

void init() {
	d = 0, w = 0, k = 0, r = 0;
	answer = k; result = false;
	REP(i1, 0, d) REP(i2, 0, w) { cells[i1][i2] = 0; c[i1][i2] = 0; }
}

int main() {
	scanf("%d", &t);
	REP(index_t, 1, t + 1) {
		init();
		scanf("%d %d %d", &d ,&w, &k);
		REP(i1, 0, d) REP(i2, 0, w) { scanf("%d", &cells[i1][i2]); c[i1][i2] = cells[i1][i2]; }

		/*  알고리즘 구현  */
		if (test(c)) answer = 0;
		else {
			REP(index, 1, k) {
				r = index;  pw = pow(2, index);
				combination(1);
				if (result) break;
			}
			if (!result)  answer = k;
		}

		/* 출력 */
		printf("#%d %d\n", index_t, answer);
	}
	return 0;
}