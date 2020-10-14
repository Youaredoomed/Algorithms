#include <iostream>
#include <stack>
using namespace std;
typedef unsigned long long ul;
stack<int> yes, no;

ul n, size;

int main() {
	cin >> n;
	ul sum = n * (n + 1) / 2;
	if (sum % 2 == 0) {
		cout << "YES" << '\n';
		ul temp = 0;
		for (int i = n; i > 0; i--) {
			if (temp + i <= (sum/2)) {
				temp += i;
				yes.push(i);
			}
			else no.push(i);
		}

		cout << yes.size() << '\n';
		while (!yes.empty()) {
			cout << yes.top() << ' ';
			yes.pop();
		}
		cout << '\n';
		cout << no.size() << '\n';
		while (!no.empty()) {
			cout << no.top() << ' ';
			no.pop();
		}

	}
	else
		cout << "NO" << '\n';
}