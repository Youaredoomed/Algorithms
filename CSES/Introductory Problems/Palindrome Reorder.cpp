#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

bool chk, sol; char a;
string str;
vector<pair<char,int>> pr;
deque<char> answer;

int main() {
	a = 0;
	cin >> str;
	for (auto x : str) {
		chk = false;
		for (auto &y : pr) {
			if (y.first == x) {
				y.second++;
				chk = true;
				break;
			}
		}
		if(!chk) pr.push_back({ x,1 });
	}
	sol = true; chk = false;
	for (auto y : pr) {
		if (y.second % 2 == 1) {
			if (!chk) {
				chk = true;
				a = y.first;
			}
			else {
				cout << "NO SOLUTION";
				sol = false;
				break;
			}
		}
	}

	if (sol) {
		if(a != 0) answer.push_back(a);
		for (auto y : pr) {
			if (y.second > 1) {
				for (int i = 0; i < y.second / 2; i++) {
					answer.push_front(y.first);
					answer.push_back(y.first);
				}
			}
		}
		for (auto x : answer)
			cout << x;
	}
}