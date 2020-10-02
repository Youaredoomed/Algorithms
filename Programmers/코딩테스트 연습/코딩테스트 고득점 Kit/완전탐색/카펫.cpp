#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int x = brown / 2 + 2;
    int y = brown + yellow;

    int z = sqrt(x * x - 4 * y);
    answer.push_back((x + z) / 2);
    answer.push_back((x - z) / 2);

    return answer;
}