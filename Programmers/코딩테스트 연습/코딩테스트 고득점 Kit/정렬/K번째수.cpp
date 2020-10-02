#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto x : commands) {
        int i = x[0] - 1;
        int j = x[1] - 1;
        vector<int> cut;

        for (int index = i; index <= j; index++) {
            cut.push_back(array[index]);
        }
        sort(cut.begin(), cut.end());
        answer.push_back(cut[x[2] - 1]);
    }
    return answer;
}