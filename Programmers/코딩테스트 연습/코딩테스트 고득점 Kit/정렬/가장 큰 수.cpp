#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool rev(string a, string b) {
    if (a[0] == b[0])
        return a + b > b + a;
    return a > b;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;

    for (auto x : numbers)
        str.push_back(to_string(x));
    sort(str.begin(), str.end(), rev);

    for (auto x : str)
        answer = answer + x;

    if (answer[0] == '0') answer = "0";
    return answer;
}