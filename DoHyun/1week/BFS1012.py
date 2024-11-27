T=int(input())


def BFS(x,y):   
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]        
    queue = [(x,y)]
    field[x][y] = 0 

    while queue:
        x,y = queue.pop(0)

        for i in range(4): 
            nx,ny = x + dx[i],y + dy[i]
            if nx < 0 or nx >= M or ny < 0 or ny >= N:continue  #바운더리 체크
            if field[nx][ny] == 1 :     #배추 먹고 또 이동
                queue.append((nx,ny))
                field[nx][ny] = 0



for _ in range(T):
    M,N,K=map(int,input().split())
    field=[[0 for j in range(N)] for i in range(M)]
    result = 0
    for i in range(K):
        a,b=map(int,input().split())
        field[a][b]=1

    for i in range(M):  #배추가 1인 칸 찾기 
        for j in range(N):
            if field[i][j] == 1:
                BFS(i,j)
                result += 1

    print(result)
