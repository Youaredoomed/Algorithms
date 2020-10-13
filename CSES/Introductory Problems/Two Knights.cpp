#include  <iostream>
using namespace std;
typedef unsigned long long ul;

int main() {
	int n;
	cin >> n;
	ul answer = 0;
	cout << answer << '\n';
	if (n >= 2) {
		answer = 6;
		cout << answer << '\n';
	}
	int temp = 6;
	for (ul k = 3; k < n + 1; k++) {
		if (k >= 5) {
			temp = 22 + 8 * (k - 5);
		}
		else if(k == 4) temp = 14;
		answer = answer + (2 * k - 1) * (k - 1) * (k) - temp - 2;
		cout << answer << '\n';
	}
}