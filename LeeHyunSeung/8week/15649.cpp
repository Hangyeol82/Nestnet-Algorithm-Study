#include <stdio.h>

using namespace std;

int n, m;
int used[8];
int arr[8];

void NM(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i])
			continue;

		used[i] = 1;
		arr[cur] = i + 1;

		NM(cur + 1);

		used[i] = 0;
		arr[cur] = 0;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);

	NM(0);

	return 0;
}