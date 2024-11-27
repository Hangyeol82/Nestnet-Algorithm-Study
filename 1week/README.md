# 1주차 과제

### 1. git 설정

1. git fork
2. git clone
3. 본인 이름의 디렉토리와, 그 하위 디렉토리로 1주차 디렉토리 만들기.
4. git push
5. create pull request

### 2. BFS 학습

https://blog.encrypted.gg/941  
이번주는 BFS 학습 및 문제풀이를 진행합니다.  
위의 블로그를 참고하셔도 좋고 이미 잘 아시는 내용이라면 학습 없이 바로 문제를 풀어도 좋습니다.  
개인적으로 이후에도 굉장히 많이 사용되고 중요한 파트라서 잘 학습해두시고 넘어가셨으면 합니다.
아래는 제가 익혀두고 사용하는 코드인데 필요하신분 참고 바랍니다.

<details>
    <summary>코드 보기</summary>

```cpp
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 502
using namespace std;

int board[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m; // n행 m열

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        fill(board[i], board[i] + m, 0);
        fill(visited[i], visited[i] + m, 0);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    visited[0][0] = 1;
    Q.push(make_pair(0, 0));

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        cout << "(" << cur.first << ", " << cur.second << ")\n";

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            //(nx, ny)는 cur의 상하좌우 칸이다.
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nx][ny] == 1 || board[nx][ny] == 0)
                continue;
            visited[nx][ny] = 1;
            Q.push(make_pair(nx, ny));
        }
    }

    return 0;
}
```

</details>

### 3. 문제풀이

아래의 문제 중 선택해서 3문제 푸시면 됩니다.

1. [1012번: 유기농 배추](https://www.acmicpc.net/problem/1012) (실버)
2. [7569번: 토마토](https://www.acmicpc.net/problem/7569) (골드)
3. [2206번: 벽 부수고 이동하기 ](https://www.acmicpc.net/problem/2206) (골드)
4. 자율
