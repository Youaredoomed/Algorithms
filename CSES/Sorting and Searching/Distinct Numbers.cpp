#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> dn;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		dn.push_back(a);
	}
	sort(dn.begin(), dn.end());
	dn.erase(unique(dn.begin(), dn.end()), dn.end());

	cout << dn.size();
}