import sys, copy
from collections import deque
input = sys.stdin.readline

n,m = map(int, input().split())

miro = [0 for _ in range(n)]

for i in range(n):
    miro[i] = list(map(int,input().rstrip()))

st = [[0] * m for _ in range(n)]
end = [[0] * m for _ in range(n)]
st[0][0] = 1
end[n-1][m-1] = 1
queue = deque([(0,0)])
while(queue):
    now = queue.popleft()
    for x,y in [(1,0),(0,1),(-1,0),(0,-1)]:
        if 0 <= now[0]+x < n and 0 <= now[1]+y < m and st[now[0]+x][now[1]+y] == 0 and miro[now[0]+x][now[1]+y] != 1:
            st[now[0]+x][now[1]+y] = st[now[0]][now[1]]+1
            queue.append((now[0]+x,now[1]+y))

queue = deque([(n-1,m-1)])

while(queue):
    now = queue.popleft()
    for x,y in [(1,0),(0,1),(-1,0),(0,-1)]:
        if 0 <= now[0]+x < n and 0 <= now[1]+y < m and end[now[0]+x][now[1]+y] == 0 and miro[now[0]+x][now[1]+y] != 1:
            end[now[0]+x][now[1]+y] = end[now[0]][now[1]]+1
            queue.append((now[0]+x,now[1]+y))
if end[0][0] != 0:
    answer = end[0][0]
else:
    answer = 9999999
for i in range(n):
    for j in range(m):
        if miro[i][j] == 1:
            min1 = 9999999
            min2 = 9999999
            for x,y in [(1,0),(0,1),(-1,0),(0,-1)]:
                if 0<=i+x<n and 0<=j+y<m and min1 > st[i+x][j+y] and st[i+x][j+y] != 0:
                    min1 = min(min1,st[i+x][j+y])
                if 0<=i+x<n and 0<=j+y<m and min2 > end[i+x][j+y] and end[i+x][j+y] != 0:
                    min2 = min(min2,end[i+x][j+y])
            if min1 + min2 < 9999999 and answer > min1 + min2:
                answer = min1+min2+1
if answer == 9999999:
    print(-1)
else:
    print(answer)