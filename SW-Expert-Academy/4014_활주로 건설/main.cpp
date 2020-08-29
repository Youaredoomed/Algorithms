#include <iostream>
using namespace std;
int t, n, x, result;

int main() {
	cin >> t;
	for (int index_t = 1; index_t <= t; index_t++) {
		cin >> n >> x;

		int** map = new int* [n];
		for (int index_map = 0; index_map < n; index_map++){
			map[index_map] = new int[n];
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];
	
		result = 0;
		// 가로방향
		for (int i_index = 0; i_index < n; i_index++) {
			bool okay = true;
			int temp = 1;
			bool hole = false;
			// 왼쪽 -> 오른쪽
			for (int j_index = 0; j_index < n - 1; j_index++) {
				if (map[i_index][j_index] == map[i_index][j_index + 1])
					temp += 1;
				else if (map[i_index][j_index] - map[i_index][j_index + 1] == 1) {
					hole = true;
					temp = 1;
				}
				else if (map[i_index][j_index] - map[i_index][j_index + 1] > 1){
					okay = false;
					temp = 1;
					break;
				}
				else if (map[i_index][j_index + 1] - map[i_index][j_index] == 1)
					if (temp >= x) {
						if (hole == true && temp < 2*x) {
							okay = false;
							break;
						}
						temp = 1;
						hole = false;
					}
					else {
						okay = false;
						temp = 1;
						break;
					}
				else if (map[i_index][j_index + 1] - map[i_index][j_index] > 1) {
					okay = false;
					temp = 1;
					break;
				}
			}
			
			// 오른쪽 -> 왼쪽
			if (okay == true) {
				temp = 1;
				bool hole = false;
				for (int j_index = n - 1; j_index > 0; j_index--) {
					if (map[i_index][j_index] == map[i_index][j_index - 1])
						temp += 1;
					else if (map[i_index][j_index] - map[i_index][j_index - 1] == 1){
						hole = true;
						temp = 1;
					}
					else if (map[i_index][j_index] - map[i_index][j_index - 1] > 1) {
						okay = false;
						temp = 1;
						break;
					}
					else if (map[i_index][j_index - 1] - map[i_index][j_index] == 1)
						if (temp >= x) {
							if (hole == true && temp < 2 * x) {
								okay = false;
								break;
							}
							temp = 1;
							hole = false;
						}
						else {
							okay = false;
							temp = 1;
							break;
						}
					else if (map[i_index][j_index - 1] - map[i_index][j_index] > 1) {
						okay = false;
						temp = 1;
						break;
					}
				}
			}
			if (okay == true)
				result += 1;
		}

		// 세로방향
		for (int j_index = 0; j_index < n; j_index++) {
			bool okay = true;
			int temp = 1;
			bool hole = false;
			// 위-> 아래
			for (int i_index = 0; i_index < n - 1; i_index++) {
				if (map[i_index][j_index] == map[i_index + 1][j_index])
					temp += 1;
				else if (map[i_index][j_index] - map[i_index + 1][j_index] == 1 ) {
					hole = true;
					temp = 1;
				}
				else if (map[i_index][j_index] - map[i_index + 1][j_index] > 1) {
					okay = false;
					temp = 1;
					break;
				}
				else if (map[i_index + 1][j_index] - map[i_index][j_index] == 1)
					if (temp >= x) {
						if (hole == true && temp < 2 * x) {
							okay = false;
							break;
						}
						temp = 1;
						hole = false;
					}
					else {
						okay = false;
						temp = 1;
						break;
					}
				else if (map[i_index + 1][j_index] - map[i_index][j_index] > 1) {
					okay = false;
					temp = 1;
					break;
				}
			}
			// 아래 -> 위
			if (okay == true) {
				temp = 1;
				hole = false;
				for (int i_index = n - 1; i_index > 0; i_index--) {
					if (map[i_index][j_index] == map[i_index - 1][j_index])
						temp += 1;
					else if (map[i_index][j_index] - map[i_index - 1][j_index] == 1) {
						hole = true;
						temp = 1;
					}
					else if (map[i_index][j_index] - map[i_index - 1][j_index] > 1) {
						okay = false;
						temp = 1;
						break;
					}
					else if (map[i_index - 1][j_index] - map[i_index][j_index] == 1)
						if (temp >= x) {
							if (hole == true && temp < 2 * x) {
								okay = false;
								break;
							}
							temp = 1;
							hole = false;
						}
						else {
							okay = false;
							temp = 1;
							break;
						}
					else if (map[i_index - 1][j_index] - map[i_index][j_index] > 1) {
						okay = false;
						temp = 1;
						break;
					}
				}
			}
			if (okay == true)
				result += 1;
		}
		cout << '#' << index_t << ' ' << result << endl;
	}
	return 0;
}