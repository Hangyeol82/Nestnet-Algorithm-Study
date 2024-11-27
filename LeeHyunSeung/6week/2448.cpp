#include <stdio.h>

using namespace std;

int arr[4000][10000] = { 0, };

void star(int level, int x_pos, int y_pos, int x, int y) {
	if (level > 3) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (x == 0 && y == 1) star(level / 2, x_pos * 2 + i, y_pos * 2 + j, 0, 1);
				else star(level / 2, x_pos * 2 + i, y_pos * 2 + j, i, j);
			}
		}
	}
	else {
		if (x == 0 && y == 1) {
			//arr[x_pos][y_pos] = 0;
		}
		else {
			arr[x_pos * 3][y_pos * 6] = 1;
			arr[x_pos * 3 + 1][y_pos * 6] = 1;
			arr[x_pos * 3 + 1][y_pos * 6 + 2] = 1;
			arr[x_pos * 3 + 2][y_pos * 6] = 1;
			arr[x_pos * 3 + 2][y_pos * 6 + 1] = 1;
			arr[x_pos * 3 + 2][y_pos * 6 + 2] = 1;
			arr[x_pos * 3 + 2][y_pos * 6 + 3] = 1;
			arr[x_pos * 3 + 2][y_pos * 6 + 4] = 1;
		}
	}
}

int main() {
	int n;

	scanf("%d", &n);

	star(n, 0, 0, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) printf(" ");
		for (int j = 0; j < (n / 3 * 6) - (n - i); j++) {
			if (arr[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}