#include <iostream>
using namespace std;
int t, n, m, k, result;

int main() {
	cin >> t;
	for (int index_t = 1; index_t <= t; index_t++) {
		cin >> n >> m >> k;
		int colsize = n + k / 2 * 2 + 2;
		int rowsize = m + k / 2 * 2 + 2;

		int** paper = new int* [colsize];
		for (int i = 0; i < colsize; i++) {
			paper[i] = new int[rowsize];
		}
		// 전체 초기화 
		for (int i = 0; i < colsize; i++) {
			for (int j = 0; j < rowsize; j++) {
				paper[i][j] = 0;
			}
		}

		for (int i = k / 2 + 1; i <= k / 2 + n; i++) {
			for (int j = k / 2 + 1; j <= k / 2 + m; j++) {
				cin >> paper[i][j];
				paper[i][j] *= 100;
			}
		}

		for (int timeProgress = 1; timeProgress <= k; timeProgress++) {
			for (int i = 0; i < colsize; i++) {
				for (int j = 0; j < rowsize; j++) {
					if (paper[i][j] >= 10000 || paper[i][j] == 0)
						continue;

					int life = paper[i][j] / 100;
					int time = paper[i][j] % 100 + 1;

					if (life + 1 == time) {
						if (i > 0) { // Up
							int temp = paper[i - 1][j];
							if (temp < 20000) {
								if (((temp / 10000 == 1) && (temp - 10000 < paper[i][j])) || temp == 0) {
									paper[i - 1][j] = 10000 + paper[i][j] / 100 * 100;
								}
							}
						}

						if (i < colsize - 1) { // Down
							int temp = paper[i + 1][j];
							if (temp < 20000) {
								if (((temp / 10000 == 1) && (temp - 10000 < paper[i][j])) || temp == 0) {
									paper[i + 1][j] = 10000 + paper[i][j] / 100 * 100;
								}
							}
						}

						if (j > 0) { // Left
							int temp = paper[i][j - 1];
							if (temp < 20000) {
								if (((temp / 10000 == 1) && (temp - 10000 < paper[i][j])) || temp == 0) {
									paper[i][j - 1] = 10000 + paper[i][j] / 100 * 100;
								}
							}
						}

						if (j < rowsize -1 ) { // Right
							int temp = paper[i][j + 1];
							if (temp < 20000) {
								if (((temp / 10000 == 1) && (temp - 10000 < paper[i][j])) || temp == 0) {
									paper[i][j + 1] = 10000 + paper[i][j] / 100 * 100;
								}
							}
						}
					}

					if (2 * life == time) {
						paper[i][j] = 20000;
					}

					if (paper[i][j] > 0 && paper[i][j] < 10000)
						paper[i][j]++;
				}
			}
			for (int i = 0; i < colsize; i++) {
				for (int j = 0; j < rowsize; j++) {
					if (paper[i][j] / 10000 == 1)
						paper[i][j] -= 10000;
				}
			}
			/*
			//테스트용
			for (int i = 0; i < colsize; i++) {
				for (int j = 0; j < rowsize; j++) {
					cout.width(5);
					cout << paper[i][j] << ' ';	
				}
				cout << endl;
			}
			cout << endl;
			// 여기까지 테스트용
			*/
		}

		result = 0;
		for (int i = 0; i < colsize; i++) {
			for (int j = 0; j < rowsize; j++) {
				if(paper[i][j] < 20000 && paper[i][j] > 0)
					result++;
			}
		}

		cout << '#' << index_t << ' ' << result << endl;
		for (int i = 0; i < colsize; i++)
			delete[] paper[i];
		delete[] paper;
	}
	return 0;
}