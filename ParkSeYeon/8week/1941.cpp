#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> v;
vector<bool> combination(25, false);
int count2 = 0;
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };

bool is_bound(const int x, const int y) {
	return x >= 0 && y >= 0 && x < 5 && y < 5;
}

bool bfs(const int index) {
	queue<pair<int, int>> q;
	vector<bool> visited(25, false);
	int count = 1;

	int y = index / 5;
	int x = index % 5;
	q.push({ x, y });
	visited[index] = true;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		if (count == 7) return true;

		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { now.first + dx[i], now.second + dy[i] };
			int to_index = 5 * next.second + next.first;

			if (is_bound(next.first, next.second) && combination[to_index] && !visited[to_index]) {
				visited[to_index] = true;
				count++;

				q.push(next);
			}
		}
	}

	return false;
}

void dfs(const int index, const int indent, const int S) {
	int y = index / 5;
	int x = index % 5;
	int SS = (v[y][x] == 'S') ? S + 1 : S;

	if (indent == 7) {
		if (SS >= 4) {
			combination[index] = true;
			if (bfs(index)) count2++;
			combination[index] = false;
		}
		return;
	}

	combination[index] = true;
	
	for (int i = index; i < 25; i++) { //조합 중복 방지 (i = 0대신 i = index)
		if (combination[i]) continue;

		dfs(i, indent + 1, SS);
	}

	combination[index] = false;
}

int main() {
	for (int y = 0; y < 5; y++) {
		string str;

		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < 25; i++) {
		dfs(i, 1, 0);
	}

	cout << count2 << '\n';
	return 0;
}