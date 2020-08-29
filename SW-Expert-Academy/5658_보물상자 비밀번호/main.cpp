#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int t, n, k, result;

int main() {
	cin >> t;
	for (int index_t = 1; index_t <= t; index_t++)
	{
		cin >> n >> k;
		int* hexNumbers = new int[n];

		// 16진수 1자리씩 받기.
		for(int i=0; i<n; i++)
		scanf("%1x", &hexNumbers[i]);

		vector<int> bvec;
		int edgeNum = n / 4;

		int temp2 = 0; // 초기화 위치

		for (int i = 0; i < edgeNum; i++) { // 스왑하는 케이스
			for (int aux = 0; aux < n; aux += edgeNum) { // 각 변마다 숫자구하기
				int temp = 0;
				for (int j = 0; j < edgeNum; j++) { 
					temp2 = j + i + aux;
					if (temp2 >= n)
						temp2 -= n;
					temp += hexNumbers[temp2] * pow(16, edgeNum - j - 1);
				}
				bvec.push_back(temp);
			}
		}
		sort(bvec.begin(), bvec.end());
		reverse(bvec.begin(), bvec.end());
		unique(bvec.begin(), bvec.end());

		result = bvec.at(k-1);
		
		cout << "#" << index_t << ' ' << result << endl;
		delete[] hexNumbers;
	}
}