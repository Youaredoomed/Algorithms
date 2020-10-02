#include string
#include vector
#include algorithm
using namespace std;

bool solution(vectorstring phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for (int i1 = 0; i1 phone_book.size() - 1; i1++) {
        for (int i2 = 0; i2 phone_book[i1].length(); i2++) {
            if (phone_book[i1][i2] != phone_book[i1 + 1][i2]) break;
            else if (i2 == phone_book[i1].length() - 1) {
                answer = false;
            }
        }
        if (!answer) break;
    }
    return answer;
}