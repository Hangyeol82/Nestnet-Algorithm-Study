#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int board[50][50]; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[50][50]; // 해당 칸을 방문했는지 여부를 저장
int T, M, N, K;    //T=테스트 케이스 수, M=열, N=행, K=배추의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int main(){
    //c++ 프로그램의 입출력 성능을 향상
    ios::sync_with_stdio(0);    //iostream 동기화 비활성화, C++만의 독립적 버퍼 사용 -> 속도 up / printf등 사용 불가
    cin.tie(0); //cin과 cout의 묶음 해제, cin 전 cout 버퍼 지우는 작업 생략, 입출력 많으면 성능 up
    cin >> T;
    int* num = new int[T]{};    //관련 조건이 없기 때문에 동적할당
    for(int t = 0; t < T; t++) {    //T번 반복
        cin >> M >> N >> K;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {    //보드 및 방문 여부 초기화
                board[i][j]=0;
                vis[i][j]=0;
            }
        }
        
        for(int i=0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++){ // (i, j)를 시작점으로 하고 싶은 상황
                if(board[i][j] == 0 || vis[i][j]) continue; // 해당 칸이 색칠이 안된 부분(0)이거나 이미 (i, j)를 방문했을 경우 넘어감
                // (i,j)는 새로운 그림에 속해있는 시작점
                num[t]++; // 배추 밭의 수 1 증가
                queue<pair<int,int> > Q;
                vis[i][j] = 1; // (i,j)로 BFS를 시작하기 위한 준비
                Q.push({i,j});
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위 밖일 경우 넘어감
                        if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                        vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    for(int i=0; i < T; i++) {
        cout << num[i] << endl;
    }

    free(num);
}