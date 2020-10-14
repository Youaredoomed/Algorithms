#include <iostream>
using namespace std;

int n, answer;

int main() {
	cin >> n;
	for (int i = 5; i <= n; i += 5) {
		int temp = i / 5;
		answer++;
		while (true) {
			if (temp % 5 == 0) {
				answer++;
				temp /= 5;
			}
			else break;
		}
	}
	cout << answer << '\n';
}