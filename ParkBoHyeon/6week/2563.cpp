#include <iostream>
using namespace std;

int main() {
    int paper[100][100] = {0};  // 도화지를 표현하는 2차원 배열
    int n;  // 색종이의 수
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        // 색종이가 덮는 영역을 1로 표시
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                paper[j][k] = 1;
            }
        }
    }

    // 1로 표시된 영역의 넓이 계산
    int area = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (paper[i][j] == 1) {
                area++;
            }
        }
    }

    cout << area << endl;

    return 0;
}