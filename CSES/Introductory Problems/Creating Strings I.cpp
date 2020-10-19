#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<char, int>> ch;
int siz, answer;
string astr, str;
int chosen[8];

int fact(int k) {
	if (k == 1) return 1;
	return k * fact(k - 1);
}

void cs() {
	if (astr.size() == siz)
		cout << astr << '\n';
	else {
		for (int j = 0; j < ch.size();j++) {
			if (chosen[j] == ch[j].second) continue;
			chosen[j]++;
			astr.push_back(ch[j].first);
			cs();
			chosen[j]--;
			astr.pop_back();
		}
	}
}

int main() {
	cin >> str;
	for (int i = 0; i < 8; i++) {
		chosen[i] = 0;
	}
	for (auto x : str) {
		int chk = false;
		for (auto &y : ch) {
			if (x == y.first) {
				chk = true;
				y.second++;
				break;
			}
		}
		if (!chk) ch.push_back({ x, 1 });
	}

	siz = str.size();
	answer = fact(siz);
	for (auto u : ch)
		if(u.second > 1) answer /= fact(u.second);
	cout << answer << '\n';
	sort(ch.begin(), ch.end());
	cs();
	return 0;
}