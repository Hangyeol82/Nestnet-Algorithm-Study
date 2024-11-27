t = int(input())
for testcase in range(t):
    m, n, k = list(map(int, input().split()))
    arr = [[0 for j in range(n)] for i in range(m)]
    visit = [[0 for j in range(n)] for i in range(m)]

    for i in range(k):
        tx, ty = list(map(int, input().split()))
        arr[tx][ty] = 1

    x = [-1, 0, 1, 0]
    y = [0, -1, 0, 1]

    q = []

    cnt = 0

    for i in range(m):
        for j in range(n):
            if arr[i][j] == 0 or visit[i][j] == 1:
                continue

            visit[i][j] = 1
            q.append([i, j])

            while len(q) > 0:
                cur = q.pop()
                for dir in range(4):
                    nx = cur[0] + x[dir]
                    ny = cur[1] + y[dir]

                    if nx < 0 or nx >= m or ny < 0 or ny >= n:
                        continue
                    if arr[nx][ny] == 0 or visit[nx][ny] == 1:
                        continue

                    visit[nx][ny] = 1
                    q.append([nx, ny])

            cnt += 1
    
    print(cnt)