#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int answer, n, x, sz;
deque<int> wg;

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		wg.push_back(a);
	}

	sort(wg.begin(), wg.end());
	sz = wg.size();

	while (sz > 0) {
		answer++;
		if (sz > 1) {
			int temp = wg.front() + wg.back();
			if (temp > x) {
				wg.pop_back();
				sz--;
			}
			else {
				wg.pop_back();
				wg.pop_front();
				sz -= 2;
			}
		}
		else break;
	}
	cout << answer;
}