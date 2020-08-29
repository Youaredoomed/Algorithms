/* 2105.디저트 카페
* 2020.01.06
* 가장 긴 경로부터 탐색시작해서 작은 경로 순으로 가면 실행시간을 줄일 수 있다.
* 가능한 모든 경로를 검색하기 때문에 가장 늦은 알고리즘..
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, row_value, col_value, _max;
vector<int> path;

bool isUnique() {
	for (int i = 0; i < path.size() - 1; i++) {
		if (path.at(i) == path.at(i + 1))
			return false;
	} return true;
}

int main() {
	cin >> t;
	for (int index_t = 0; index_t < t; index_t++) {
		_max = 0;
		cin >> n;
		int** ary = new int * [n];
		for (int index1 = 0; index1 < n; index1++)
			ary[index1] = new int[n];
		for (int index2 = 0; index2 < n; index2++) {
			for (int index3 = 0; index3 < n; index3++)
				cin >> ary[index2][index3];
		}

		for (int row_index = 0; row_index < n-2; row_index++) {
			for (int col_index = 1; col_index < n-1; col_index++) {
				row_value = row_index; col_value = col_index;
				int possibleOne = 0;
				int possibleTwo = 0;
				if ((row_value + col_value) < (n-1)) { possibleOne = col_value; }
				else if ((row_value + col_value) >= (n-1)) { possibleOne = (n - 2) - row_value; }
				for (int index_po = possibleOne; index_po > 0; index_po--) {
					row_value = row_index + index_po; col_value = col_index - index_po;
					if (row_value > col_value) { possibleTwo = n - 1 - row_value; }
					else if (row_value <= col_value) { possibleTwo = n - 2 - col_value ; }
					if (col_value + index_po + possibleTwo >= n) { possibleTwo = possibleTwo - (col_value + index_po + possibleTwo - n + 1); }
					for (int index_pt = possibleTwo; index_pt > 0; index_pt--) {
						row_value = row_index; col_value = col_index;
						path.push_back(ary[row_value][col_value]);
						for (int index_one = 0; index_one < index_po; index_one++){
							row_value++; col_value--;
							path.push_back(ary[row_value][col_value]);
						}
						for (int index_two = 0; index_two < index_pt; index_two++){
							row_value++; col_value++;
							path.push_back(ary[row_value][col_value]);
						}
						for (int index_three = 0; index_three < index_po; index_three++){
							row_value--; col_value++;
							path.push_back(ary[row_value][col_value]);
						}
						for (int index_four = 0; index_four < index_pt-1; index_four++){
							row_value--; col_value--;
							path.push_back(ary[row_value][col_value]);
						}
						sort(path.begin(), path.end());
						if (!isUnique()) {path.clear();}
						if (_max < path.size()) { _max = path.size(); }
						path.clear();
					}
				}
			}
		} if (_max == 0) { _max = -1; }

		cout << '#' << index_t + 1 << ' ' << _max << '\n';
		for (int i = 0; i < n; i++)
			delete[] ary[i];
		delete[] ary;
	}
	return 0;
}