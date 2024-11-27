from collections import deque
n,m=map(int,input().split())
field=[]
for i in range(n):field.append(list(map(int,list(input()))))
visited=[[[0 for k in range(2)] for i in range(m)]for j in range(n)]
wall_break=0
dx=[0,0,1,-1]
dy=[1,-1,0,0]

def bfs(start_x,start_y):
    global wall_break
    level=1
    q=deque([[start_x,start_y,level,wall_break]])
    visited[start_y][start_x][wall_break]=level

    while q:
        x,y,level,wall_break=q.popleft()
        
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<m and 0<=ny<n:

                if field[ny][nx]==0 and visited[ny][nx][wall_break]==0:
                    visited[ny][nx][wall_break]=level+1
                    q.append([nx,ny,level+1,wall_break])
                elif field[ny][nx]==1 and wall_break==0:
                    visited[ny][nx][wall_break+1]=level+1
                    q.append([nx,ny,level+1,wall_break+1])


bfs(0,0)
if visited[n-1][m-1][wall_break]:print(visited[n-1][m-1][wall_break])
else:print("-1")
