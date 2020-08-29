/*
 -> 수정 내역
 1. direction -> drc , i -> row , j -> col  : 불변 변수와 가변 변수 헷갈리지 않게
 2. 바깥 루프 탈출 방법 -> 바깥루프 탈출조건 걸고 break;
 3. 일단 모든 경우에 이동한 상태에서 방향만 바꿔지게 바꿈
 4. 웜홀 나가자마자 벽에 부딪히는 경우 -> count만 올리고, 위치 변경은 하지않도록
 5. 웜홀 조건에서 row와 col이 모두 달라야 하는게 아니라 둘중 하나만 달라도 됌 ->  if (map[i1][j1] == temp && (i1 != row || j1 != col))
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
				if (map[i][j] == 0) { // 0인 위치에서 시작
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
											//웜홀 이동
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
							// 출발지점이면 종료
							if (i == row && j == col) {
								gameover = false;
								break;
							}
							/*
							//테스트용
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