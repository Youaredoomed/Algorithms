#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ul;

const int mo = 1000000007;
int n, answer;
ul ui;

int main() {
	cin >> n;
	answer = 2;
	for (int i = 1; i < n; i++) {
		answer *= 2;
		if (answer >= mo) answer %= mo;
	}
	cout << answer << '\n';
}