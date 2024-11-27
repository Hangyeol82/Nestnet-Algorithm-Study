#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void hanoi(const int N, const int from, const int tmp, const int to) {
	if (N == 1) {
		cout << from + 1 << ' ' << to + 1 << '\n';
	}
	else {
		hanoi(N - 1, from, to, tmp);
		cout << from + 1 << ' ' << to + 1 << '\n';

		hanoi(N - 1, tmp, from, to);
	}
}

int main() {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	string count3 = to_string(pow(2, N));
	int position = count3.find('.');
	string count4 = count3.substr(0, position);
	count4[count4.size() - 1] -= 1;

	cout << count4 << '\n';

	if (N <= 20) {
		hanoi(N, 0, 1, 2);
	}

	return 0;
}