#include <iostream>
using namespace std;
typedef unsigned long long ui;

int ary[200000];

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];
	ui answer = 0;
	for (int i = 1; i < n; i++) {
		if (ary[i] < ary[i - 1]) {
			int a = ary[i - 1] - ary[i];
			answer += a;
			ary[i] += a;
		}
	}
	cout << answer;
}