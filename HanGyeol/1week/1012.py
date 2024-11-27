import sys
input = sys.stdin.readline
from collections import deque

t = int(input())

for _ in range(t):
    answer = 0
    m, n, k = map(int,input().split())
    field = [[0]*m for _ in range(n)]
    check = [[0]*m for _ in range(n)]
    
    for _ in range(k):
        x, y = map(int, input().split())
        field[y][x] = 1
        
    queue = deque()
    
    for i in range(n):
        for j in range(m):
            if check[i][j] != 1 and field[i][j] == 1:
                queue.append([i,j])
                check[i][j] = 1
                answer += 1
                while(queue):
                    now = queue.popleft()
                    for y, x in [(1,0) , (0, 1), (-1,0) , (0,-1)]:
                        if 0 <= now[0]+y < n and 0 <= now[1]+x < m and field[now[0]+y][now[1]+x] == 1 and check[now[0]+y][now[1]+x] != 1:
                            queue.append([now[0]+y,now[1]+x])
                            check[now[0]+y][now[1]+x] = 1
    print(answer)
