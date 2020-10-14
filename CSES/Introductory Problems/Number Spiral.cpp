#include <iostream>
using namespace std;
typedef unsigned long long ul;

ul t, y, x, answer;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> y >> x;

		if (y >= x) {
			if (y % 2 == 0) answer = y * y - x + 1;
			else answer = y * y - 2 * y + x + 1;
		}
		else {
			if (x % 2 == 1) answer = x * x - y + 1;
			else answer = x * x - 2 * x + y + 1;
		}
		cout << answer << '\n';
	}
}