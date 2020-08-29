/* 2020.01.03
*  1953. [모의 SW 역량테스트] 탈주범 검거
*/
#include <iostream>
#include <vector>
using namespace std;

#define upSearch if (r > 0) {\
if ((1 << (ary[r - 1][c] - 1)) & _down) {\
	if (!((lastvisited.back().first == (r - 1)) && (lastvisited.back().second == c))) {\
		if (visited[r - 1][c] == false) { _count++; } lastvisited.push_back({ r,c }); r--; search(ary); r++;}}}

#define downSearch 	if (r < n - 1) {\
if ((1 << (ary[r + 1][c] - 1)) & _up) {\
	if (!((lastvisited.back().first == (r + 1)) && (lastvisited.back().second == c))) {\
		if (visited[r + 1][c] == false) { _count++; } lastvisited.push_back({ r,c }); r++; search(ary); r--;}}}

#define leftSearch 	if (c > 0) {\
if ((1 << (ary[r][c - 1] - 1)) & _right) {\
	if (!((lastvisited.back().first == r) && (lastvisited.back().second == (c - 1)))) {\
		if (visited[r][c - 1] == false) { _count++; } lastvisited.push_back({ r,c }); c--; search(ary); c++;}}}

#define rightSearch if (c < m - 1) {\
if ((1 << (ary[r][c + 1] - 1)) & _left) {\
	if (!((lastvisited.back().first == r) && (lastvisited.back().second == (c + 1)))) {\
		if (visited[r][c + 1] == false) { _count++; } lastvisited.push_back({ r,c }); c++; search(ary); c--;}}}

const char _up = 0b01001011; const char _down = 0b00110011; const char _left = 0b01100101; const char _right = 0b00011101;
int t, n, m, r, c, l,_count,l_count;
bool visited[50][50];
vector<pair<int, int>> lastvisited;

void search(int**& ary) {
	visited[r][c] = true;
	l_count++;
	if (l_count <= l) {
		switch (ary[r][c]) {
		case 1:
			upSearch
			downSearch
			leftSearch
			rightSearch
			break;
		case 2:
			upSearch
			downSearch
			break;
		case 3:
			leftSearch
			rightSearch
			break;
		case 4:
			upSearch
			rightSearch
			break;
		case 5:
			downSearch
			rightSearch
			break;
		case 6:
			downSearch
			leftSearch
			break;
		case 7:
			upSearch
			leftSearch
			break;
		}
	}
	l_count--;
	lastvisited.pop_back();
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		_count = 1;
		l_count = 1;
		lastvisited.push_back({ 51,51 });
		cin >> n >> m >> r >> c >> l;
		for (int bindex1 = 0; bindex1 < 50; bindex1++) {
			for (int bindex2 = 0; bindex2 < 50; bindex2++)
				visited[bindex1][bindex2] = false;
		}

		int** ary = new int* [n];
		for (int index1 = 0; index1 < n; index1++)
			ary[index1] = new int[m];

		for (int index2 = 0; index2 < n; index2++) {
			for (int index3 = 0; index3 < m; index3++)
				cin >> ary[index2][index3];
		}
		search(ary);
		cout << '#' << i + 1 << ' ' << _count << endl;
		for (int i = 0; i < n; i++)
			delete[] ary[i];
		delete[] ary;
	}
	return 0;
}