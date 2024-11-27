#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> counts(3, 0);

void paper(const int N, const int x, const int y, const int range) {
	if (range == 1) {
		counts[v[y][x] + 1]++;
		return;
	}

	bool all = true;

	for (int yy = y; yy < y + range; yy++) {
		for (int xx = x; xx < x + range; xx++) {
			if (v[yy][xx] != v[y][x]) {
				all = false;
				break;
			}
		}
		if (!all) break;
	}

	if (!all) {
		for (int dy = 0; dy < range; dy += range / 3) {
			for (int dx = 0; dx < range; dx += range / 3) {
				paper(N, x + dx, y + dy, range / 3);
			}
		}
	}
	else {
		counts[v[y][x] + 1]++;
	}
}

int main() {
	int N;

	cin >> N;
	v.assign(N, vector<int>(N, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> v[y][x];
		}
	}

	paper(N, 0, 0, N);
	cout << counts[0] << '\n' << counts[1] << '\n' << counts[2] << '\n';

	return 0;
}