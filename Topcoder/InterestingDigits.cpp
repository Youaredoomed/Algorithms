#include <vector>
using namespace std;

class InterestingDigits {
public:
	vector<int> digits(int base) {
		vector<int> ans;

		for (int i = 2; i < base; i++) {
			if ((base - 1) % i == 0) ans.push_back(i);
		}

		return ans;
	}
};