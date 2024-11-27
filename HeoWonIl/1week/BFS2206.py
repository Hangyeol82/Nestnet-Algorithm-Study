from collections import deque

n, m = map(int, input().split())
graph = []
ch = [[[0] * 2 for _ in range(m)] for _ in range(n)]
ch[0][0][0] = 1

for i in range(n):
    graph.append(list(map(int, input())))

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def bfs(a, b, c):
    q = deque()
    q.append((a, b, c))
    while q:
        x, y, flag = q.popleft()
        if x == n - 1 and y == m - 1:
            return ch[x][y][flag]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if graph[nx][ny] == 1 and flag == 0:
                    ch[nx][ny][1] = ch[x][y][0] + 1
                    q.append((nx, ny, 1))
                elif graph[nx][ny] == 0 and ch[nx][ny][flag] == 0:
                    ch[nx][ny][flag] = ch[x][y][flag] + 1
                    q.append((nx, ny, flag))
    return -1

print(bfs(0, 0, 0))