#include <iostream>
#include <vector>
#include <stack>
using namespace std;

char LKF(const int k, const int lkf, const int N) {
	int lkf2 = lkf * 2 + k + 3;

	if (N == 1) return 'm';
	else if (N == 2 || N == 3) return 'o';
	
	if (lkf2 < N) {
		return LKF(k + 1, lkf2, N);
	}
	else {
		if (N > lkf && N <= lkf + k + 3) {
			if (N == lkf + 1) return 'm';
			return 'o';
		}
		else {
			return LKF(1, 3, N - (lkf + k + 3));
		}
	}
}

int main() {
	int N;

	cin >> N;
	cout << LKF(1, 3, N) << '\n';

	return 0;
}