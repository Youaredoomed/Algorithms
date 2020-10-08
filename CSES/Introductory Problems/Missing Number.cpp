#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ui;

int main() {
	ui n = 0;
	cin >> n;
	n--;
	vector<ui> nums;
	for (int i = 0; i < n ; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
	ui answer = 0;
	for (auto x : nums)
		answer += x;

	answer = (n + 1) * (n + 2) / 2 - answer;

	cout << answer;
}