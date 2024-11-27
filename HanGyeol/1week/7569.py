import sys
from collections import deque

m, n, h = map(int,input().split())

tom = [[[0] * m for _ in range(n)] for _ in range(h)]

for i in range(h):
    for j in range(n):
        tom[i][j] = list(map(int, input().split()))

queue = deque()
l = []

for i in range(h):
    for j in range(n):
        for k in range(m):
            if tom[i][j][k] == 1:
                l.append((i,j,k))

answer = -1

while(l):
    queue.append(l)
    l = []
    while(queue):
        now = queue.popleft()
        for x1,y1,z1 in now:
            for x2,y2,z2 in [(1,0,0) , [-1,0,0], (0,1,0), (0,-1,0), (0,0,1), (0,0,-1)]:
                if 0 <= x1+x2 < h and 0 <= y1+y2 < n and 0 <= z1+z2 < m and tom[x1+x2][y1+y2][z1+z2] == 0:
                    l.append((x1+x2,y1+y2,z1+z2))
                    tom[x1+x2][y1+y2][z1+z2] = 1
        answer += 1

for i in range(h):
    for j in range(n):
        for k in range(m):
            if tom[i][j][k] == 0:
                print(-1)
                exit()

print(answer)