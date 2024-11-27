from sys import stdin, stdout
from collections import deque

dx = [-1, 1, -2, 2, -2, 2, -1, 1]
dy = [2, 2, 1, 1, -1, -1, -2, -2]

t = int(stdin.readline())
for testcase in range(t):
    l = int(stdin.readline())

    dist = [[-1 for j in range(l)] for i in range(l)]
    q = deque()

    now = list(map(int, stdin.readline().split()))
    goal = list(map(int, stdin.readline().split()))

    q.append([now[0], now[1]])
    dist[now[0]][now[1]] = 0

    def bfs():
        while len(q) > 0:
            cur = q.popleft()
            
            if cur[0] == goal[0] and cur[1] == goal[1]:
                return dist[cur[0]][cur[1]]

            for dir in range(8):
                nx = cur[0] + dx[dir]
                ny = cur[1] + dy[dir]

                if nx < 0 or nx >= l or ny < 0 or ny >= l: continue
                if dist[nx][ny] >= 0: continue

                q.append([nx, ny])
                dist[nx][ny] = dist[cur[0]][cur[1]] + 1

    stdout.write(f'{bfs()}\n')