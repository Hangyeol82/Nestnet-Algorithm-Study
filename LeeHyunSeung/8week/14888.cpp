#include <stdio.h>

using namespace std;

int n;
int a[11], op[4];
int now;
int min = 1000000001, max = -1000000001;

void Calc(int cur) {
	if (cur == n) {
		if (now < min) min = now;
		if (now > max) max = now;
		return;
	}

	int temp = now;

	if (op[0] > 0) {
		now = temp + a[cur];
		op[0]--;
		Calc(cur + 1);
		op[0]++;
		
	}
	if (op[1] > 0) {
		now = temp - a[cur];
		op[1]--;
		Calc(cur + 1);
		op[1]++;

	}
	if (op[2] > 0) {
		now = temp * a[cur];
		op[2]--;
		Calc(cur + 1);
		op[2]++;

	}
	if (op[3] > 0) {
		now = temp / a[cur];
		op[3]--;
		Calc(cur + 1);
		op[3]++;

	}

	now = temp;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}

	now = a[0];
	Calc(1);

	printf("%d\n%d", max, min);

	return 0;
}