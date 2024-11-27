from collections import deque

answer = 0

dx = [-1, 0, 1, 0 , 0, 0]
dy = [0, -1, 0, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

q = deque()

tmt = []
m,n,h=map(int, input().split())
for _ in range(h):
    box = []
    for _ in range(n):
        box.append(list(map(int, input().split())))
    tmt.append(box)

for i in range(len(tmt)):
    for j in range(n):
        for k in range(m):
            if tmt[i][j][k] == 1:
                q.append((i, j, k, 0))

while q:
    z, x, y, day = q.popleft()
    answer = day
    for i in range(6):
        nz = z + dz[i]
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < n and 0 <= ny < m and 0 <= nz < h and tmt[nz][nx][ny] == 0:
            tmt[nz][nx][ny] = 1
            q.append((nz, nx, ny, day + 1))

for i in range(len(tmt)):
    for j in range(n):
        for k in range(m):
            if tmt[i][j][k] == 0:
                answer = -1
                break

print(answer)
