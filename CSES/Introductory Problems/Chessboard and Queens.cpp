#include <iostream>
using namespace std;
const int n = 8;
int answer;
int board[n][n];

void search(int y) {
	if (y == n) {
		answer++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (board[i][y]) continue;

		for (int k = 0; k < n; k++) {
			if (!board[i][k]) board[i][k] = 3;
		}
		for (int k = 1; k <= n; k++) {
			if(i - k >= 0 && y - k >= 0)
				if (!board[i - k][y - k]) board[i - k][y - k] = 4;
			if(i + k < n && y + k < n)
				if (!board[i + k][y + k]) board[i + k][y + k] = 4;
		}
		for (int k = 1; k <= n; k++) {
			if (i - k >= 0 && y + k < n)
				if (!board[i - k][y + k]) board[i - k][y + k] = 5;
			if (i + k < n && y - k >= 0)
				if (!board[i + k][y - k]) board[i + k][y - k] = 5;
		}

		search(y + 1);

		for (int k = 0; k < n; k++) {
			if (board[i][k] == 3) board[i][k] = 0;
		}
		for (int k = 1; k <= n; k++) {
			if (i - k >= 0 && y - k >= 0)
				if (board[i - k][y - k] == 4) board[i - k][y - k] = 0;
			if (i + k < n && y + k < n)
				if (board[i + k][y + k] == 4) board[i + k][y + k] = 0;
		}
		for (int k = 1; k <= n; k++) {
			if (i - k >= 0 && y + k < n)
				if (board[i - k][y + k] == 5) board[i - k][y + k] = 0;
			if (i + k < n && y - k >= 0)
				if (board[i + k][y - k] == 5) board[i + k][y - k] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			if (a == '*') board[i][j] = 2;
		}
	}
	search(0);
	cout << answer;
}