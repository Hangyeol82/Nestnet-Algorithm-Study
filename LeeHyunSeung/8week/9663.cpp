#include <stdio.h>

using namespace std;

bool use1[40], use2[40], use3[40];

int count = 0;
int n;

void NQueen(int cur) {
	if (cur == n) {
		count++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (use1[i] || use2[i + cur] || use3[cur - i + n - 1])
			continue;

		use1[i] = 1;
		use2[i + cur] = 1;
		use3[cur - i + n - 1] = 1;

		NQueen(cur + 1);

		use1[i] = 0;
		use2[i + cur] = 0;
		use3[cur - i + n - 1] = 0;
	}
}

int main(void) {
	scanf("%d", &n);

	NQueen(0);

	printf("%d\n", count);

	return 0;
}