#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, K;
	queue<pair<int, int>> q;
	int min_time = 0;
	vector<bool> visited;

	visited.assign(100001, false);

	cin >> N >> K;

	if (N != K) {
		if (N - 1 >= 0) {
			q.push({ 1, N - 1 });
			visited[N - 1] = true;
		}
		if (N + 1 <= 100000) {
			q.push({ 1, N + 1 });
			visited[N + 1] = true;
		}
		if (N * 2 <= 100000) {
			q.push({ 1, N * 2 });
			visited[N * 2] = true;
		}
	}

	while (!q.empty()) {
		pair<int, int> inf = q.front();
		q.pop();

		if (inf.second == K) {
			if (min_time == 0 || inf.first < min_time) min_time = inf.first;
			continue;
		}

		if (inf.second - 1 >= 0 && !visited[inf.second - 1]) {
			q.push({ inf.first + 1, inf.second - 1 });
			visited[inf.second - 1] = true;
		}
		if (inf.second + 1 <= 100000 && inf.second < K && !visited[inf.second + 1]) {
			q.push({ inf.first + 1, inf.second + 1 });
			visited[inf.second + 1] = true;
		}
		if (inf.second * 2 <= 100000 && inf.second < K && !visited[inf.second * 2]) {
			q.push({ inf.first + 1, inf.second * 2 });
			visited[inf.second * 2] = true;
		}
	}

	cout << min_time << '\n';
	return 0;
}