#include <stdio.h>

using namespace std;

char arr[6561][6561] = { 0, };

void star(int level, int x_pos, int y_pos, int x, int y) {
	if (level > 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (x == 1 && y == 1) star(level / 3, x_pos * 3 + i, y_pos * 3 + j, 1, 1);
				else star(level / 3, x_pos * 3 + i, y_pos * 3 + j, i, j);
			}
		}
	} else {
		if (x == 1 && y == 1) arr[x_pos][y_pos] = ' ';
		else arr[x_pos][y_pos] = '*';
	}
}

int main() {
	int n;

	scanf("%d", &n);

	star(n, 0, 0, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}