#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, m, a, result;
int map[10][10];
int userA[101]; int userB[101];
vector<int> powerlist, store;

struct player {
	int x;
	int y;

	void move(int n) {
		if (n == 1) x--;
		else if (n == 2) y++;
		else if (n == 3) x++;
		else if (n == 4) y--;
	}
};

void init() {
	for (int i1 = 0; i1 < 10; i1++)
		for (int i2 = 0; i2 < 10; i2++)
			map[i1][i2] = 0;
	for (int i = 0; i < 101; i++) {
		userA[i] = 0; userB[i] = 0;
	}
	powerlist.clear();
	store.clear();
	result = 0, m = 0, a = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	for (int index_t = 1; index_t <= t; index_t++) {
		init();
		cin >> m >> a;
		for (int i = 1; i <= m; i++) cin >> userA[i];
		for (int i = 1; i <= m; i++) cin >> userB[i];

		for (int i_bc = 0; i_bc < a; i_bc++) {
			int x, y, r, pw;
			cin >> x >> y >> r >> pw;
			x--; y--;
			powerlist.push_back(pw * 10 + i_bc);
			store.push_back(x);
			store.push_back(y);
			store.push_back(r);
		}
		sort(powerlist.begin(), powerlist.end());

		for (int i_bc = powerlist.size() - 1; i_bc >= 0; i_bc--) {
			int a = (powerlist[i_bc] % 10) * 3;
			int x = store[a];
			int y = store[a + 1];
			int r = store[a + 2];
			for (int i1 = 0; i1 < 10; i1++)
				for (int i2 = 0; i2 < 10; i2++)
					if (abs(i1 - x) + abs(i2 - y) <= r)
						map[i2][i1] += pow(2, i_bc); // 열이 먼저
		}
		for(int i = 0; i<a; i++)
			powerlist[i] = powerlist[i] / 10;
		player A; A.x = 0, A.y = 0;
		player B; B.x = 9, B.y = 9;

		for (int i = 0; i <= m; i++){
			A.move(userA[i]);
			B.move(userB[i]);

			if (map[A.x][A.y] == 0 && map[B.x][B.y] == 0) {
				continue;
			}
			else if (map[A.x][A.y] == 0) {
				for (int index = a - 1; index >= 0; index--) {
					if ((map[B.x][B.y] >> index) & 1) {
						result += powerlist[index];
						break;
					}
				}
			}
			else if (map[B.x][B.y] == 0) {
				for (int index = a - 1; index >= 0; index--) {
					if ((map[A.x][A.y] >> index) & 1) {
						result += powerlist[index];
						break;
					}
				}
			}
			else {
				int a_value = 0;
				int b_value = 0;
				for (int index = a - 1; index >= 0; index--) {
					if ((map[A.x][A.y] >> index) & 1) {
						a_value = index; break;
					}
				}
				for (int index = a - 1; index >= 0; index--) {
					if ((map[B.x][B.y] >> index) & 1) {
						b_value = index; break;
					}
				}
				// 최상위 비트 두개가 다를때 , 두개의 합
				if (a_value != b_value) {
					result += powerlist[a_value];
					result += powerlist[b_value];
				}
				// 최상위 비트 두개가 같을때, and해서 두번째 찾기 ,없으면 안 더하고 있으면 더하고
				else {
					int temp = map[A.x][A.y] | map[B.x][B.y];
					result += powerlist[a_value];
					for (int index2 = a_value - 1; index2 >= 0; index2--) {
						if ((temp >> index2) & 1) {
							result += powerlist[index2];
							break;
						}
					}
				}
			}
		}
		cout << '#' << index_t << ' ' << result << endl;
	}
	return 0;
}