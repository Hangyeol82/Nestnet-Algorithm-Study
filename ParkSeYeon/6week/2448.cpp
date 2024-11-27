#include <iostream>
#include <vector>
using namespace std;

vector<string> v;

void star(const int x, const int y, const int N) {
	if (N == 3) {
		v[y][x] = '*';
		v[y + 1][x - 1] = '*';
		v[y + 1][x + 1] = '*';
		for (int dx = -2; dx <= 2; dx++) v[y + 2][x + dx] = '*';
	}
	else {
		star(x, y, N / 2);
		star(x - N / 2, y + N / 2, N / 2);
		star(x + N / 2, y + N / 2, N / 2);
	}
}

int main() {
	int N;
	int width;

	cin >> N;
	width = 6 * (N / 3) - 1;

	for (int y = 0; y < N; y++) {
		v.push_back(string(width, ' '));
	}
	star(width / 2, 0, N);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}