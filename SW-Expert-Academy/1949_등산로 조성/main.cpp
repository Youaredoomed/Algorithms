#include <iostream>
#include <vector>
using namespace std;
int tc, n, k, _count, result;
bool use_k;
vector<int> mapsave;

void search(int** map, int& i, int& j, bool** visited) {
	int row_value = i, col_value = j;
	visited[row_value][col_value] = true;
	_count++;

	if (row_value > 0) { // up
		if (!visited[row_value - 1][col_value]) {
			if (map[row_value][col_value] > map[row_value - 1][col_value]) {
				row_value--;
				search(map, row_value, col_value, visited);
				row_value++;
			}
			else if (!use_k && (map[row_value][col_value] > map[row_value - 1][col_value] - k)) {
				use_k = true;
				// mapdata º¯°æ
				mapsave.push_back(map[row_value - 1][col_value]);
				map[row_value - 1][col_value] = map[row_value][col_value] - 1;
				row_value--;
				search(map, row_value, col_value, visited);
				row_value++;
				use_k = false;
				map[row_value - 1][col_value] = mapsave.back();
				mapsave.pop_back();
			}
		}
	}

	if (row_value < n-1) { // down
		if (!visited[row_value + 1][col_value]) {
			if (map[row_value][col_value] > map[row_value + 1][col_value]) {
				row_value++;
				search(map, row_value, col_value, visited);
				row_value--;
			}
			else if (!use_k && (map[row_value][col_value] > map[row_value + 1][col_value] - k)) {
				use_k = true;
				mapsave.push_back(map[row_value + 1][col_value]);
				map[row_value + 1][col_value] = map[row_value][col_value] - 1;
				row_value++;
				search(map, row_value, col_value, visited);
				row_value--;
				use_k = false;
				map[row_value + 1][col_value] = mapsave.back();
				mapsave.pop_back();
			}
		}
	}

	if (col_value < n-1) { // right
		if (!visited[row_value][col_value + 1]) {
			if (map[row_value][col_value] > map[row_value][col_value + 1]) {
				col_value++;
				search(map, row_value, col_value, visited);
				col_value--;
			}
			else if (!use_k && (map[row_value][col_value] > map[row_value][col_value + 1] - k)) {
				use_k = true;
				mapsave.push_back(map[row_value][col_value + 1]);
				map[row_value][col_value + 1] = map[row_value][col_value] - 1;
				col_value++;
				search(map, row_value, col_value, visited);
				col_value--;
				use_k = false;
				map[row_value][col_value + 1] = mapsave.back();
				mapsave.pop_back();
			}
		}
	}

	if (col_value > 0) { // left
		if (!visited[row_value][col_value - 1]) {
			if (map[row_value][col_value] > map[row_value][col_value - 1]) {
				col_value--;
				search(map, row_value, col_value, visited);
				col_value++;
			}
			else if (!use_k && (map[row_value][col_value] > map[row_value][col_value - 1] - k)) {
				use_k = true;
				mapsave.push_back(map[row_value][col_value - 1]);
				map[row_value][col_value - 1] = map[row_value][col_value] - 1;
				col_value--;
				search(map, row_value, col_value, visited);
				col_value++;
				use_k = false;
				map[row_value][col_value - 1] = mapsave.back();
				mapsave.pop_back();
			}
		}
	}
	if (result < _count)
		result = _count;
	visited[row_value][col_value] = false;
	_count--;
}

void init(bool** visited) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {
	cin >> tc;
	for (int test_num = 1; test_num <= tc; test_num++) {
		cin >> n >> k;
		int** map = new int* [n]; bool** visited = new bool* [n];
		for (int index0 = 0; index0 < n; index0++) {
			map[index0] = new int[n];
			visited[index0] = new bool[n];
		}

		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				visited[i][j] = false;
				if (max < map[i][j]) max = map[i][j];
			}
		}

		_count = 0; result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == max) {
					search(map,i,j, visited);
					init(visited);
				}
			}
		}


		cout << '#' << test_num << ' ' << result << endl;
		for (int i = 0; i < n; i++){
			delete[] map[i];
			delete[] visited[i];
		}
		delete[] map; delete[] visited;
	}
	return 0;
}