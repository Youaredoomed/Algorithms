#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 99999999999
typedef long long ll;

ll n, answer, sum;

vector<int> apple;

void search(int k) {
	if (k > apple.size()) {
		answer = min(abs(sum), answer);
		return;
	}
	sum += apple[k-1];
	search(k + 1);
	sum -= 2* apple[k - 1];
	search(k + 1);
	sum += apple[k - 1];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		apple.push_back(a);
	}
	answer = INF;
	search(1);

	cout << answer;
}