import sys
from queue import Queue

m, n = list(map(int, sys.stdin.readline().split()))

arr = [[0 for y in range(m)] for x in range(n)]
dist = [[0 for y in range(m)] for x in range(n)]

q = Queue()

for x in range(n):
    arr[x] = list(map(int, sys.stdin.readline().split()))
    for y in range(m):
        if arr[x][y] == 1:
            q.put([x, y])
        if arr[x][y] == 0:
            dist[x][y] = -1

mx = [1, -1, 0, 0]
my = [0, 0, 1, -1]

while not q.empty():
    cursor = q.get()
    for dir in range(4):
        nx = cursor[0] + mx[dir]
        ny = cursor[1] + my[dir]

        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if dist[nx][ny] >= 0:
            continue

        q.put([nx, ny])
        dist[nx][ny] = dist[cursor[0]][cursor[1]] + 1

def isDone():
    ans = 0
    for x in range(n):
        for y in range(m):
            if dist[x][y] == -1:
                return -1
            ans = max(ans, dist[x][y])
    return ans

print(isDone())