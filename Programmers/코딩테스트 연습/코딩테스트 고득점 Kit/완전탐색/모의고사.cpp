#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count[3] = { 0, 0, 0 };
    for (int i = 0; i < answers.size(); i++) {
        if (i % 5 + 1 == answers[i])
            count[0]++;

        if (i % 2 == 0) { if (answers[i] == 2) count[1]++; }
        else if (i % 8 == 1) { if (answers[i] == 1) count[1]++; }
        else if (i % 8 == 3) { if (answers[i] == 3) count[1]++; }
        else if (i % 8 == 5) { if (answers[i] == 4) count[1]++; }
        else if (i % 8 == 7) { if (answers[i] == 5) count[1]++; }

        if (i % 10 == 0) { if (answers[i] == 3) count[2]++; }
        else if (i % 10 == 1) { if (answers[i] == 3) count[2]++; }
        else if (i % 10 == 2) { if (answers[i] == 1) count[2]++; }
        else if (i % 10 == 3) { if (answers[i] == 1) count[2]++; }
        else if (i % 10 == 4) { if (answers[i] == 2) count[2]++; }
        else if (i % 10 == 5) { if (answers[i] == 2) count[2]++; }
        else if (i % 10 == 6) { if (answers[i] == 4) count[2]++; }
        else if (i % 10 == 7) { if (answers[i] == 4) count[2]++; }
        else if (i % 10 == 8) { if (answers[i] == 5) count[2]++; }
        else if (i % 10 == 9) { if (answers[i] == 5) count[2]++; }
    }

    int hscore = max(max(count[0], count[1]), count[2]);
    for (int i = 0; i < 3; i++) {
        if (count[i] == hscore) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}