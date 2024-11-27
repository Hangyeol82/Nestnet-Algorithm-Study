#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <queue>

using namespace std;

char arr[1000][1000] = {};
int dist[1000][1000] = {};

int main(void) {
	int h, w, n;
	int i, j;
	int ans = 0;

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	pair<int, int> point[10] = {};
	queue<pair<int, int>> q;

	scanf("%d %d %d", &h, &w, &n);

	for (i = 0; i < h; i++) {
		scanf("%s", arr[i]);
		for (j = 0; j < w; j++) {
			if (arr[i][j] == 'S') {
				point[0].first = i;
				point[0].second = j;
			}
			if (isdigit(arr[i][j])) {
				point[atoi(&arr[i][j])].first = i;
				point[atoi(&arr[i][j])].second = j;
			}
		}
	}

	for (i = 0; i < n; i++) {
		memset(dist, -1, 1000 * 1000 * sizeof(int));
		q.push({ point[i].first, point[i].second });
		dist[point[i].first][point[i].second] = 0;
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (dist[nx][ny] >= 0 || arr[nx][ny] == 'X') continue;

				q.push({ nx, ny });
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
			}
		}
		ans += dist[point[i+1].first][point[i+1].second];
	}

	printf("%d", ans);

	return 0;
}