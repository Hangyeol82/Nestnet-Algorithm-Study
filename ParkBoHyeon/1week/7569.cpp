#include <iostream>
#include <tuple>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int board[100][100][100];
int dist[100][100][100];
int N,M,H;
//{1, 0, 0 / 0, 1, 0 / 0, 0, 1 / 0, -1, 0 / 0, 0, -1 / -1, 0, 0}
int dz[6] = {1,0,0,0,0,-1}; //높이
int dx[6] = {0,1,0,-1,0,0}; //행
int dy[6] = {0,0,1,0,-1,0}; //열

int main(void){
    //c++ 프로그램의 입출력 성능을 향상
    ios::sync_with_stdio(0);    //iostream 동기화 비활성화, C++만의 독립적 버퍼 사용 -> 속도 up / printf등 사용 불가
    cin.tie(0); //cin과 cout의 묶음 해제, cin 전 cout 버퍼 지우는 작업 생략, 입출력 많으면 성능 up
    cin >> M >> N >> H;
    queue<tuple<int,int,int> > Q;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++) {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1)
                    Q.push({i,j,k});
                if(board[i][j][k] == 0)
                    dist[i][j][k] = -1;
            }
        }
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; dir++){
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if(nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nz][nx][ny] >= 0) continue;
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            Q.push({nz,nx,ny});
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }
    cout << ans;
}