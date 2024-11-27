#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int picture[101][101] = {0};  // 그림을 표현할 2차원 배열
    
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // 투명 종이가 덮는 영역의 카운트 증가
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                picture[x][y]++;
            }
        }
    }
    
    int covered = 0;  // 가려진 부분의 수
    
    // M을 초과하는 칸의 수 세기
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (picture[i][j] > M) {
                covered++;
            }
        }
    }
    
    cout << covered << endl;
    
    return 0;
}