from collections import deque

M, N, H = map(int, input().split())
box=[[[0 for k in range(M)] for i in range(N)]for j in range(H)]

for i in range(H):
    for j in range(N):box[i][j]=list(map(int,input().split()))

queue = deque()

# 익은 토마토 큐에 넣어두기
for z in range(H):
    for y in range(N):
        for x in range(M):
            if box[z][y][x] == 1:queue.append((x, y, z))

def BFS():
    dx = [-1, 1, 0, 0, 0, 0]
    dy = [0, 0, -1, 1, 0, 0]
    dz = [0, 0, 0, 0, -1, 1]
    while queue:
        x, y, z = queue.popleft()
        
        for i in range(6):
            nx,ny,nz = x + dx[i],y + dy[i],z + dz[i]
            if nx < 0 or nx >= M or ny < 0 or ny >= N or nz < 0 or nz >= H: continue #바운더리 체크
            
            if box[nz][ny][nx] == 0:    #익지 않은 토마토 만났을 때 
                box[nz][ny][nx] = box[z][y][x] + 1
                queue.append((nx, ny, nz))

BFS()
result = 0
for z in range(H):
    for y in range(N):
        for x in range(M):
            if box[z][y][x] == 0:
                print(-1)
                exit()
            result = max(result, box[z][y][x])
print(result - 1)
