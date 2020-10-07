#include <string>
#include <vector>

using namespace std;

struct qw {
    int x;
    int y;
    void next(int a) {
        if (a == 0) x++;
        else if (a == 1) y++;
        else if (a == 2) { x--; y--; }
    }
};

vector<int> solution(int n) {
    vector<int> answer;
    int** map = new int* [n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[i + 1];
    }
    int count = 1, state = 0;
    qw qw; qw.x = -1; qw.y = 0;
    for (int i = n; i > 0; i--) {
        for (int index = 0; index < i; index++) {
            qw.next(state);
            map[qw.x][qw.y] = count;
            count++;
        }
        state++;
        if (state == 3) state = 0;
    }
    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = 0; i2 < i1 + 1; i2++)
            answer.push_back(map[i1][i2]);
    }

    return answer;
}