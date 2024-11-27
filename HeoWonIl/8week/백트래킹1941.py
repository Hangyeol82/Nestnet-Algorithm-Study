import sys
input=sys.stdin.readline
from collections import deque

N=5
arr=[input() for _ in range(N)]
ans=0
ch=[[0]*N for _ in range(N)]
dx=[-1,0,1,0]
dy=[0,1,0,-1]

def bfs(a,b):
    v=[[0]*N for _ in range(N)]
    q=deque()
    q.append((a,b))
    v[a][b]=1
    adj_cnt=1
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<N and 0<=ny<N and v[nx][ny]==0 and ch[nx][ny]:
                v[nx][ny]=1
                adj_cnt+=1
                q.append((nx,ny))
    return adj_cnt==7
    
def is_adjacent():
    for i in range(N):
        for j in range(N):
            if ch[i][j]==1:
                return bfs(i,j)
    
def dfs(n,cnt,scnt):
    global ans
    # 가지 치기
    if cnt>7:
        return
    # 종료 조건
    if n==N*N:
        if cnt==7 and scnt>=4: # 7명이고, 이다솜파가 4명 이상인 경우
            if is_adjacent(): # 7명 모두 인접한 경우만 정답에 추가
                ans+=1
        return
    # n//5, n%5 지점을 포함하는 경우
    ch[n//N][n%N]=1
    dfs(n+1,cnt+1,scnt+int(arr[n//N][n%N]=='S'))
    ch[n//N][n%N]=0
    # n//5, n%5 지점을 포함하지 않는 경우
    dfs(n+1,cnt,scnt)
    
dfs(0,0,0)
print(ans)