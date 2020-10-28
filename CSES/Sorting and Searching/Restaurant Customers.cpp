#include <iostream>
#include <map>
using namespace std;

int n,a,b,answer;
map<int, int> rc;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		rc[a]++;
		rc[b]--;
	}
	int temp = 0;
	for (auto x : rc) {
		temp += x.second;
		answer = max(answer, temp);
	}
	cout << answer;
}