#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
	int x;
	int y;
	int broke;
};

int main() {
	int N; //height
	int M; //width
	vector<vector<int>> v;
	queue<point> q;
	vector<vector<vector<int>>> visited;

	vector<int> dx = { -1, 1, 0, 0 };
	vector<int> dy = { 0, 0, -1, 1 };

	cin >> N >> M;
	v.assign(N, vector<int>(M, 0));
	visited.assign(N, vector<vector<int>>(M, vector<int>(2, -1)));

	for (int y = 0; y < N; y++) {
		string str;

		cin >> str;

		for (int x = 0; x < M; x++) {
			v[y][x] = str[x] - '0';
		}
	}

	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			point next = { now.x + dx[i], now.y + dy[i], now.broke };

			if (next.x >= 0 && next.x < M && next.y >= 0 && next.y < N) {
				if (v[next.y][next.x] == 0 && (visited[now.y][now.x][now.broke] + 1 < visited[next.y][next.x][next.broke] || visited[next.y][next.x][next.broke] == -1)) {
					visited[next.y][next.x][next.broke] = visited[now.y][now.x][now.broke] + 1;
					q.push(next);
				}
				if (now.broke == 0 && v[next.y][next.x] == 1) {
					next.broke = 1;
					q.push(next);
					visited[next.y][next.x][1] = visited[now.y][now.x][now.broke] + 1;
				}

			}
		}
	}

	int count = 0;
	vector<int> v0 = visited[N - 1][M - 1];
	if (v0[0] == -1 && v0[1] == -1) cout << "-1\n";
	else if (v0[0] != -1 && v0[1] == -1) cout << v0[0] << '\n';
	else if (v0[0] == -1 && v0[1] != -1) cout << v0[1] << '\n';
	else cout << min(v0[0], v0[1]) << '\n';

	//cout << visited[N - 1][M - 1] << '\n';
	return 0;
}