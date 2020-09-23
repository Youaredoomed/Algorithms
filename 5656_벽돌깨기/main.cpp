/* 
*  5656. [���� SW �����׽�Ʈ] ���� ����
* 
���� ���� ����
1. if��  �� �ٷ� �ۼ��ص� ������ ������ �� ��� ��ȣ ���
2. �������� �ݵ�� �ʱ�ȭ
3. �Ҵ� ���� ��Ȯ�ϰ� ���ؼ� ��Ÿ�ӿ��� �߻�.
*/

#include <iostream>
using namespace std;

typedef short int si;
#define REP(i,a,b) for(si i = int(a); i < int(b); i++)
#define bigInt 0b01111111111111111111111111111110

si n, w, h;
int answer;

void sortBrick(si **map) {
	REP(iw, 0, w){
		si count = 0;
		REP(i, 0, h) if (map[i][iw] == 0) count++;
		REP(i, 0, count)
		for (int ih = h - 1; ih > 0; ih--) {
			// 0��ŭ �ݺ� (�־��� ��� �̹� ������ �� ���¿��� count�� ��ŭ �ݺ��Ҽ��� ����)
			if (map[ih][iw] == 0) { map[ih][iw] = map[ih - 1][iw]; map[ih - 1][iw] = 0; } // �� �ٷ� �ۼ��ص� ������ ������ �� ��� ��ȣ ���
		}
	}
}

void brick(si **map, si h_value, si w_value) {
	int c = map[h_value][w_value] - 1;
	map[h_value][w_value] = 0;
	si h1 = h_value;
	si w1 = w_value;

	REP(index, 0, c) {
		w1++;
		if (w1 == w) break;
		if (map[h1][w1] == 1)  map[h1][w1] = 0;
		else if (map[h1][w1] > 1) brick(map, h1, w1);
	} w1 = w_value;

	REP(index, 0, c) {
		w1--;
		if (w1 < 0) break;
		if (map[h1][w1] == 1)  map[h1][w1] = 0;
		else if (map[h1][w1] > 1) brick(map, h1, w1);
	} w1 = w_value;

	REP(index, 0, c) {
		h1++;
		if (h1 == h) break;
		if (map[h1][w1] == 1)  map[h1][w1] = 0;
		else if (map[h1][w1] > 1) brick(map, h1, w1);
	} h1 = h_value;

	REP(index, 0, c) {
		h1--;
		if (h1 < 0) break;
		if (map[h1][w1] == 1)  map[h1][w1] = 0;
		else if (map[h1][w1] > 1) brick(map, h1, w1);
	} h1 = h_value;
}

int countMap(si **map) {
	int count = 0;
	REP(iw, 0, w)
		for (int ih = h - 1; ih >= 0; ih--){
			if (map[ih][iw] != 0) count++;
			else break;}
	return count;
}

int simul(si** map) {
	REP(index_re, 0, w) { // �¿��� ��� Ȯ��
		int bul = 0;
		REP(index_h, 0, h) { // �� �� Ȯ��
			if (map[index_h][index_re] > 0) bul++;
			if (bul > n) break;
			if (map[index_h][index_re] > 1) {
				// �迭����
				si** saveMap = new si * [h];
				REP(i, 0, h) saveMap[i] = new si[w];
				REP(ih, 0, h) REP(iw, 0, w) saveMap[ih][iw] = map[ih][iw];

				brick(map, index_h,index_re);
				sortBrick(map);

				// ��� ����
				n -= bul;
				if (n == 0) { answer = min(answer, countMap(map));}
				else simul(map);

				n += bul;

				// �迭 ����
				REP(ih, 0, h) REP(iw, 0, w) map[ih][iw] = saveMap[ih][iw];
				REP(i, 0, h) { delete[] saveMap[i]; }
				delete[] saveMap;
			}
		}
	}
	// ������ �������� ����.
	if(n > 0) answer = min(answer, countMap(map) - n);
	return 1;
}

int main() {
	int t;
	cin >> t;
	REP(index_t, 1, t+1) {
		n = 0; w = 0; h = 0;
		answer = bigInt;
		cin >> n >> w >> h;
		si** map = new si * [h];
		REP(i1, 0, h) {map[i1] = new si[w];
		REP(i2, 0, w) { cin >> map[i1][i2]; }}

		simul(map);

		//��� �� ���� �迭 �Ҵ� ����
		if (answer < 0) answer = 0;
		cout << '#' << index_t << ' ' << answer << '\n';
		REP(i, 0, h){ delete[] map[i];}
		delete[] map;
	}
	return 0;
}