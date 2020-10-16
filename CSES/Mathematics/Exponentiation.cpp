#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ul;

const int mo = 1000000007;

ul modpow(ul a, ul b) {
	if (b == 0) return 1;
	ul u = modpow(a, b / 2);
	u = (u * u) % mo;
	if (b % 2 == 1) u = u * a % mo;
	return u;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ul a, b;
		ul answer = 1;
		cin >> a >> b;
		answer = modpow(a, b);
		cout << answer << '\n';
	}
}