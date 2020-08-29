/*
 -> ���� ����
 1. direction -> drc , i -> row , j -> col  : �Һ� ������ ���� ���� �򰥸��� �ʰ�
 2. �ٱ� ���� Ż�� ��� -> �ٱ����� Ż������ �ɰ� break;
 3. �ϴ� ��� ��쿡 �̵��� ���¿��� ���⸸ �ٲ����� �ٲ�
 4. ��Ȧ �����ڸ��� ���� �ε����� ��� -> count�� �ø���, ��ġ ������ �����ʵ���
 5. ��Ȧ ���ǿ��� row�� col�� ��� �޶�� �ϴ°� �ƴ϶� ���� �ϳ��� �޶� �� ->  if (map[i1][j1] == temp && (i1 != row || j1 != col))
*/

#include <iostream>
using namespace std;
int t, n, result;

int main() {
	cin >> t;
	for (int index_t = 1; index_t <= t; index_t++) {
		cin >> n;
		int** map = new int*[n];
		for (int i = 0; i < n; i++) {
			map[i] = new int[n];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		int count = 0;
		result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) { // 0�� ��ġ���� ����
					for (int direction = 1; direction <= 4; direction++) { // 1 up 2 down 3 left 4 right
						int row = i; int col = j; int drc = direction; bool gameover = true;
						while (gameover) {
							switch (drc) {
								case 1:
									if (row > 0) {
										row--;
										int temp = map[row][col];
										if (temp == 0) {
											
										}
										else if (temp == 1 || temp == 4 || temp == 5) {
											count++;
											drc = 2;
										}
										else if (temp == 2) {
											count++;
											drc = 4;
											if (col == n-1) {
												count += 2;
												drc = 2;
											}
										}
										else if (temp == 3) {
											count++;
											drc = 3;
											if (col == 0) {
												count += 2;
												drc = 2;
											}
										}
										else if (temp >= 6 && temp <= 10) {
											//��Ȧ �̵�
											for (int i1 = 0; i1 < n; i1++) {
												for (int j1 = 0; j1 < n; j1++) {
													if (map[i1][j1] == temp && (i1 != row || j1 != col)) {
														if (i1 == 0 && drc == 1) {
															count++;
															drc = 2;
															i1 = n;
															break;
														}
														else if (i1 == n - 1 && drc == 2) {
															count++;
															drc = 1;
															i1 = n;
															break;
														}
														else if (j1 == 0 && drc == 3) {
															count++;
															drc = 4;
															i1 = n;
															break;
														}
														else if (j1 == n - 1 && drc == 4) {
															count++;
															drc = 3;
															i1 = n;
															break;
														}
														else {
															col = j1;
															row = i1;
															i1 = n;
															break;
														}
													}
												}
											}
										}
										else if (temp == -1) {
											gameover = false;
										}
									}
									else if (row == 0) {
										count++;
										drc = 2;
									}
									break;

								case 2:
									if (row < n-1) {
										row++;
										int temp = map[row][col];
										if (temp == 0) {

										}
										else if (temp == 2 || temp == 3 || temp == 5) {
											count++;
											drc = 1;
										}
										else if (temp == 1) {
											count++;
											drc = 4;
											if (col == n-1) {
												count += 2;
												drc = 1;
											}
										}
										else if (temp == 4) {
											count++;
											drc = 3;
											if (col == 0) {
												count += 2;
												drc = 1;
											}
										}
										else if (temp >= 6 && temp <= 10) {
											for (int i1 = 0; i1 < n; i1++) {
												for (int j1 = 0; j1 < n; j1++) {
													if (map[i1][j1] == temp && (i1 != row || j1 != col)) {
														if (i1 == 0 && drc == 1) {
															count++;
															drc = 2;
															i1 = n;
															break;
														}
														else if (i1 == n - 1 && drc == 2) {
															count++;
															drc = 1;
															i1 = n;
															break;
														}
														else if (j1 == 0 && drc == 3) {
															count++;
															drc = 4;
															i1 = n;
															break;
														}
														else if (j1 == n - 1 && drc == 4) {
															count++;
															drc = 3;
															i1 = n;
															break;
														}
														else {
															col = j1;
															row = i1;
															i1 = n;
															break;
														}
													}
												}
											}
										}
										else if (temp == -1) {
											gameover = false;
										}
									}
									else if (row == n-1) {
										count++;
										drc = 1;
									}
									break;

								case 3:
									if (col > 0) {
										col--;
										int temp = map[row][col];
										if (temp == 0) {

										}
										else if (temp == 3 || temp == 4 || temp == 5) {
											count++;
											drc = 4;
										}
										else if (temp == 1) {
											count++;
											drc = 1;
											if (row == 0) {
												count += 2;
												drc = 4;
											}
										}
										else if (temp == 2) {
											count++;
											drc = 2;
											if (row == n-1) {
												count += 2;
												drc = 4;
											}
										}
										else if (temp >= 6 && temp <= 10) {
											for (int i1 = 0; i1 < n; i1++) {
												for (int j1 = 0; j1 < n; j1++) {
													if (map[i1][j1] == temp && (i1 != row || j1 != col)) {
														if (i1 == 0 && drc == 1) {
															count++;
															drc = 2;
															i1 = n;
															break;
														}
														else if (i1 == n - 1 && drc == 2) {
															count++;
															drc = 1;
															i1 = n;
															break;
														}
														else if (j1 == 0 && drc == 3) {
															count++;
															drc = 4;
															i1 = n;
															break;
														}
														else if (j1 == n - 1 && drc == 4) {
															count++;
															drc = 3;
															i1 = n;
															break;
														}
														else {
															col = j1;
															row = i1;
															i1 = n;
															break;
														}
													}
												}
											}
										}
										else if (temp == -1) {
											gameover = false;
										}
									}
									else if (col == 0) {
										count++;
										drc = 4;
									}
									break;

								case 4:
									if (col < n-1) {
										col++;
										int temp = map[row][col];
										if (temp == 0) {

										}
										else if (temp == 1 || temp == 2 || temp == 5) {
											count++;
											drc = 3;
										}
										else if (temp == 3) {
											count++;
											drc = 2;
											if (row == n-1) {
												count += 2;
												drc = 3;
											}
										}
										else if (temp == 4) {
											count++;
											drc = 1;
											if (row == 0) {
												count += 2;
												drc = 3;
											}
										}
										else if (temp >= 6 && temp <= 10) {
											for (int i1 = 0; i1 < n; i1++) {
												for (int j1 = 0; j1 < n; j1++) {
													if (map[i1][j1] == temp && (i1 != row || j1 != col)) {
														if (i1 == 0 && drc == 1) {
															count++;
															drc = 2;
															i1 = n;
															break;
														}
														else if (i1 == n - 1 && drc == 2) {
															count++;
															drc = 1;
															i1 = n;
															break;
														}
														else if (j1 == 0 && drc == 3) {
															count++;
															drc = 4;
															i1 = n;
															break;
														}
														else if (j1 == n - 1 && drc == 4) {
															count++;
															drc = 3;
															i1 = n;
															break;
														}
														else {
															col = j1;
															row = i1;
															i1 = n;
															break;
														}
													}
												}
											}
										}
										else if (temp == -1) {
											gameover = false;
										}
									}
									else if (col == n-1) {
										count++;
										drc = 3;
									}
									break;
								}
							// ��������̸� ����
							if (i == row && j == col) {
								gameover = false;
								break;
							}
							/*
							//�׽�Ʈ��
							cout << endl;
							cout << "i= " << i << "  j= " << j << "  direction= " << direction;
							cout << endl;
							for (int i = 0; i < n; i++) {
								for (int j = 0; j < n; j++) {
									if (i == row && j == col)
										cout << '*' << "  ";
									else
										cout << map[i][j] << "  ";
								}
								cout << endl;
							}
							*/
						}
						if (count > result)
							result = count;
						count = 0;
					}
				}
			}
		}

		::cout << '#' << index_t << ' ' << result << endl;
		for (int i = 0; i < n; i++)
			delete[] map[i];
		delete[] map;
	}
	return 0;
}