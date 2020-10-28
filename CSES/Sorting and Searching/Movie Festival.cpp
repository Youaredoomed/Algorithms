#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer, a, b;
vector<pair<int, int>> mf;

bool comp(pair<int,int> v, pair<int, int> w) {
	if (v.second == w.second)
		return v.first < w.first;
	return v.second < w.second;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		mf.push_back({ a,b });
	}

	sort(mf.begin(), mf.end(), comp);

	vector<pair<int, int>>::iterator it;
	it = mf.begin();
	answer++;
	int temp = it->second;

	for (auto x : mf) {
		if (temp < x.second) {
			if (temp <= x.first) {
				answer++;
				temp = x.second;
			}
		}
	}
	cout << answer;
}