#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int a = 0;
    int pw = pow(2, numbers.size());
    for (int i = 0; i < pw; i++) {
        int num = 0;
        for (int j = 0; j < numbers.size(); j++) {
            if ((i >> j) & 1 == 1)
                num += numbers[j];
            else
                num -= numbers[j];
        }
        if (num == target)
            answer++;
    }
    return answer;
}