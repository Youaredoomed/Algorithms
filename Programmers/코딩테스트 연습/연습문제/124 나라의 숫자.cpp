#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    do {
        if (n % 3 == 1)
            answer = "1" + answer;
        else if (n % 3 == 2)
            answer = "2" + answer;
        else if (n % 3 == 0)
            answer = "4" + answer; n--;
        n = n / 3;
    } while (n > 3);

    if (n > 0) {
        if (n % 3 == 1)
            answer = "1" + answer;
        else if (n % 3 == 2)
            answer = "2" + answer;
        else if (n % 3 == 0)
            answer = "4" + answer;
    }
    return answer;
}