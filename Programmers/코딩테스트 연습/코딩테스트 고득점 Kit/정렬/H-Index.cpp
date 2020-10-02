#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool rev(int a, int b) { return a > b; }

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), rev);

    for (int index = 0; index < citations.size(); index++) {
        if (citations[index] >= index + 1)
            answer = index + 1;
        else break;
    }

    return answer;
}