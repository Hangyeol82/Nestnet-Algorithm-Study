#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct tomato {
	int x;
	int y;
	int z;
};

bool is_all_value(const int M, const int N, const int H, const int value, const vector<vector<vector<int>>>& v) {
	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (v[z][y][x] != value) return false;
			}
		}
	}

	return true;
}

int main() {
	int M; //width
	int N; //height
	int H;
	vector<vector<vector<int>>> v;
	vector<vector<vector<int>>> visited;

	vector<int> dx = { -1, 1, 0, 0, 0, 0 };
	vector<int> dy = { 0, 0, -1, 1, 0, 0 };
	vector<int> dz = { 0, 0, 0, 0, -1, 1 };

	cin >> M >> N >> H;
	v.assign(H, vector<vector<int>>(N, vector<int>(M, -1)));
	visited.assign(H, vector<vector<int>>(N, vector<int>(M, -1)));

	for (int z = 0; z < H; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				cin >> v[z][y][x];

	if (is_all_value(M, N, H, 1, v)) {
		cout << "0\n";
		return 0;
	}
	if (is_all_value(M, N, H, -1, v)) {
		cout << "-1\n";
		return 0;
	}

	queue<tomato> q;

	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (v[z][y][x] == 1) {
					q.push({ x, y, z });
					visited[z][y][x] = 0;
					//break;
				}
			}
		}
	}
		
	while (!q.empty()) {
		tomato now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			tomato next = { now.x + dx[i], now.y + dy[i], now.z + dz[i] };

			if (next.x >= 0 && next.x < M && next.y >= 0 && next.y < N && next.z >= 0 && next.z < H && v[next.z][next.y][next.x] != -1 && visited[next.z][next.y][next.x] == -1) {
				q.push(next);

				visited[next.z][next.y][next.x] = visited[now.z][now.y][now.x] + 1;
				if (v[next.z][next.y][next.x] == 1) visited[next.z][next.y][next.x]--;

				v[next.z][next.y][next.x] = 1;
			}
		}
	}

	int count = -1;

	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (visited[z][y][x] > count) {
					count = visited[z][y][x];
				}
				if (v[z][y][x] == 0) {
					count = -1;
					break;
				}
			}
			if (count == -1) break;
		}
		if (count == -1) break;
	}

	cout << count << '\n';
	return 0;
}