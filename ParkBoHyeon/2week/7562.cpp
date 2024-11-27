#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define X first
#define Y second

int board[401][401];
int dist[401][401];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};   // 이동할 수 있는 8방향을 의미
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main () {
    int T;
    cin >> T;
    int* Case = new int[T]{};

    for (int t=0; t < T; t++) {
        int l, x1, y1, x2, y2;
        int level = 0, cnt = 0;
        cin >> l >> x1 >> y1; //l*l 체스판 크기 및 시작 위치 좌표
        cin >> x2 >> y2;    //목표 좌표 위치
        for (int i=0; i < l; i++) {
            for (int j=0; j < l; j++) {
                board[i][j] = 1;    //모든 블럭은 이동 가능
                dist[i][j] = -1;    //방문하지 않은 경우, 거리 = -1
            }
        }
        queue<pair<int, int>> Q;
        dist[x1][y1]++;     //시작위치 = 0이 된다.
        Q.push({x1, y1});   //시작 위치를 큐에 넣어준다.

        while(!Q.empty()) {     //Queue가 비거나, 목표지점에 도달할 때 까지
            pair<int, int> cur = Q.front(); Q.pop();    //가장 앞에있는 요소 cur에 넣고, pop()으로 삭제
            if (cur.X == x2 && cur.Y == y2) { // 목표 지점에 도달
                Case[t] = dist[x2][y2]; // 결과 저장
                break;
            }

            for (int dir=0; dir<8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l ) continue;  //범위를 벗어나는 경우
                if (dist[nx][ny] != -1) continue; //이미 방문한 경우
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;    //방문 표시
                Q.push({nx, ny});     //queue에 넣기
                cnt++;
            }
        }
    }
    for (int i=0; i < T; i++) {
        cout << Case[i] << endl;
    }

    delete(Case);
}