import sys
input = sys.stdin.readline
from collections import deque

n, m, k = map(int, input().split())

miro = [[0] for _ in range(n)]
for i in range(n):
    miro[i] = list(map(int, input().rstrip()))

queue = deque([[0,0]])
end = [[0] * m for _ in range(n)]
v = [[n*m+1]*m for _ in range(n)]

end[n-1][m-1] = 1
v[n-1][m-1] = 0
dx=[1,-1,0,0]
dy=[0,0,1,-1]
time = 1
queue = deque([[n-1,m-1,0]])

while(queue):
    time += 1
    for _ in range(len(queue)):
        now = queue.popleft()
        for i in range(4):
            if 0 <= now[0]+dx[i] < n and 0 <= now[1]+dy[i] < m and v[now[0]+dx[i]][now[1]+dy[i]] > now[2]:
                if miro[now[0]+dx[i]][now[1]+dy[i]] != 1: 
                    if now[0]+dx[i] == 0 and now[1]+dy[i] == 0:
                        print(time)
                        exit()
                    end[now[0]+dx[i]][now[1]+dy[i]] = time
                    v[now[0]+dx[i]][now[1]+dy[i]] = now[2]
                    queue.append([now[0]+dx[i], now[1]+dy[i], now[2]])
                if miro[now[0]+dx[i]][now[1]+dy[i]] == 1 and now[2] < k:
                    if now[0]+dx[i] == 0 and now[1]+dy[i] == 0:
                        print(time)
                        exit()
                    end[now[0]+dx[i]][now[1]+dy[i]] = time
                    v[now[0]+dx[i]][now[1]+dy[i]] = now[2]+1
                    queue.append([now[0]+dx[i],now[1]+dy[i],now[2]+1])

if end[0][0] == 0:
    print(-1)
else:
    print(end[0][0])