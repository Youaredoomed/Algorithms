#include <iostream>
using namespace std;

int n;

int main() {
	cin >> n;
	if (n == 1) cout << 1;
	else if (n <= 3) cout << "NO SOLUTION";
	else if (n == 4) cout << "2 4 1 3";
	else {
		if (n % 2 == 1) {
			for (int i = 1; i <= n / 2; i++) {
				cout << i << ' ' << i + n / 2 + 1 << ' ';
			}
			cout << n / 2 + 1;
		}
		else {
			for (int i = 1; i <= n / 2; i++) {
				cout << i << ' ' << i + n / 2 << ' ';
			}
		}
	}
}