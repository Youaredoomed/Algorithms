#include <iostream>
using namespace std;
int t, k, result;
int mag1[8], mag2[8], mag3[8], mag4[8];

void cwrotate(int* mag) {
	int temp = mag[7];
	mag[7] = mag[6];
	mag[6] = mag[5];
	mag[5] = mag[4];
	mag[4] = mag[3];
	mag[3] = mag[2];
	mag[2] = mag[1];
	mag[1] = mag[0];
	mag[0] = temp;
}
void ccwrotate(int* mag) {
	int temp = mag[0];
	mag[0] = mag[1];
	mag[1] = mag[2];
	mag[2] = mag[3];
	mag[3] = mag[4];
	mag[4] = mag[5];
	mag[5] = mag[6];
	mag[6] = mag[7];
	mag[7] = temp;
}

int main() {
	cin >> t;
	for (int index_t = 1; index_t <= t; index_t++) {
		cin >> k;
		for (int i = 0; i < 8; i++)
			cin >> mag1[i];
		for (int i = 0; i < 8; i++)
			cin >> mag2[i];
		for (int i = 0; i < 8; i++)
			cin >> mag3[i];
		for (int i = 0; i < 8; i++)
			cin >> mag4[i];

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			if (a == 1) {
				if (b == 1) {
					cwrotate(mag1);
					if (mag1[3] != mag2[6]) {
						ccwrotate(mag2);
						if (mag2[1] != mag3[6]) {
							cwrotate(mag3);
							if (mag3[3] != mag4[6])
								ccwrotate(mag4);
							}
					}
				}
				else if (b == -1) {
					ccwrotate(mag1);
					if (mag1[1] != mag2[6]) {
						cwrotate(mag2);
						if (mag2[3] != mag3[6]) {
							ccwrotate(mag3);
							if (mag3[1] != mag4[6])
								cwrotate(mag4);
						}
					}
				}
			}
			else if (a == 2) {
				if (b == 1) {
					cwrotate(mag2);
					if (mag1[2] != mag2[7])
						ccwrotate(mag1);
					if (mag2[3] != mag3[6]) {
						ccwrotate(mag3);
						if (mag3[1] != mag4[6])
							cwrotate(mag4);
					}
				}
				else if (b == -1) {
					ccwrotate(mag2);
					if (mag1[2] != mag2[5])
						cwrotate(mag1);
					if (mag2[1] != mag3[6]) {
						cwrotate(mag3);
						if (mag3[3] != mag4[6])
							ccwrotate(mag4);
					}
				}
			}
			else if (a == 3) {
				if (b == 1) {
					cwrotate(mag3);
					if (mag3[7] != mag2[2]) {
						ccwrotate(mag2);
						if (mag2[5] != mag1[2])
							cwrotate(mag1);
					}
					if (mag3[3] != mag4[6])
						ccwrotate(mag4);
				}
				else if (b == -1) {
					ccwrotate(mag3);
					if (mag3[5] != mag2[2]) {
						cwrotate(mag2);
						if (mag2[7] != mag1[2])
							ccwrotate(mag1);
					}
					if (mag3[1] != mag4[6])
						cwrotate(mag4);
				}
			}
			else if (a == 4) {
				if (b == 1) {
					cwrotate(mag4);
					if (mag4[7] != mag3[2]) {
						ccwrotate(mag3);
						if (mag3[5] != mag2[2]) {
							cwrotate(mag2);
							if (mag2[7] != mag1[2])
								ccwrotate(mag1);
						}
					}
				}
				else if (b == -1) {
					ccwrotate(mag4);
					if (mag4[5] != mag3[2]) {
						cwrotate(mag3);
						if (mag3[7] != mag2[2]) {
							ccwrotate(mag2);
							if (mag2[5] != mag1[2])
								cwrotate(mag1);
						}
					}
				}
			}
		}
		// result °è»ê
		result = 0;
		if (mag1[0] == 1) {
			result += 1;
		}
		if (mag2[0] == 1) {
			result += 2;
		}
		if (mag3[0] == 1) {
			result += 4;
		}
		if (mag4[0] == 1) {
			result += 8;
		}

		cout << '#' << index_t << ' ' << result << endl;
	}
	return 0;
}