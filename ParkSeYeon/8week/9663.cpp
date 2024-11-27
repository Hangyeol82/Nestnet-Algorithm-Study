#include <iostream>
#include <vector>
using namespace std;

vector<int> horizontal;
vector<int> vertical;
vector<int> diagonal1; //right-down
vector<int> diagonal2;
int count2 = 0;

void set_flag(const int x, const int y, const int N, const int value) {
	int d1 = (x - y) + N - 1;
	int d2 = x + y;

	horizontal[y] = value;
	vertical[x] = value;
	diagonal1[d1] = value;
	diagonal2[d2] = value;
}

void dfs(const int x, const int y, const int indent, const int N) {
	if (indent == N) {
		count2++;
		return;
	}

	set_flag(x, y, N, 1);

	int dd1 = 0;
	int dd2 = 0;
	int yy = y + 1;

	for (int xx = 0; xx < N; xx++) {
		if (xx == x) continue;

		dd1 = (xx - yy) + N - 1;
		dd2 = xx + yy;
		if (horizontal[yy] == 1 || vertical[xx] == 1 || diagonal1[dd1] == 1 || diagonal2[dd2] == 1) continue;

		dfs(xx, yy, indent + 1, N);
	}

	set_flag(x, y, N, 0);
}

int main() {
	int N;

	cin >> N;
	horizontal = vector<int>(N, 0);
	vertical = vector<int>(N, 0);
	diagonal1 = vector<int>(2 * N - 1, 0);
	diagonal2 = vector<int>(2 * N - 1, 0);

	for (int x = 0; x < N; x++) {
		dfs(x, 0, 1, N);
	}

	cout << count2 << '\n';
	return 0;
}