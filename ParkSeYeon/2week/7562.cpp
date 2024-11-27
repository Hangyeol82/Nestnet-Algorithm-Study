#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos {
	int x;
	int y;
};

bool is_bound(const pos& p, const int l) {
	return p.x >= 0 && p.x < l && p.y >= 0 && p.y < l;
}

bool is_equal(const pos& p1, const pos& p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

int bfs(const int l, const pos& start, const pos& end) {
	int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	queue<pos> q;
	vector<vector<int>> visited;

	visited.assign(l, vector<int>(l, -1));
	visited[start.y][start.x] = 0;
	q.push(start);

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			pos next = { now.x + dx[i], now.y + dy[i] };

			if (!is_bound(next, l)) continue;
			if (visited[next.y][next.x] != -1 && visited[next.y][next.x] <= visited[now.y][now.x] + 1) continue;

			visited[next.y][next.x] = visited[now.y][now.x] + 1;
			if (!is_equal(next, end)) q.push(next);
		}
	}

	return visited[end.y][end.x];
}

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int l;
		pos start = { 0, 0 };
		pos end = { 0, 0 };

		cin >> l;
		cin >> start.x >> start.y;
		cin >> end.x >> end.y;

		cout << bfs(l, start, end) << '\n';
	}

	return 0;
}