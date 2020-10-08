#include <string>
#include <iostream>
using namespace std;

int main() {
	string in;
	cin >> in;
	int answer = 0;
	int count = 1;
	for (int a = 0; a < in.size() - 1; a++) {
		if (in[a] == in[a + 1])
			count++;
		else {
			answer = max(answer, count);
			count = 1;
		}
	}
	answer = max(answer, count);
	cout << answer;
}