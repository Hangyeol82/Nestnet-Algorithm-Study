def dfs(i):
    global ans
    if i == N:
        ans += 1
        return
    for j in range(N):
        # 같은 선상에 퀸이 없을 경우 백트래킹 수행
        if c1[j] == c2[i + j] == c3[i - j] == 0:
            c1[j] = c2[i + j] = c3[i - j] = 1
            dfs(i + 1)
            c1[j] = c2[i + j] = c3[i - j] = 0


N = int(input())
# 같은 선상에 퀸이 있는지 체크
c1 = [0] * N  # 열
c2 = [0] * (2 * N - 1)  # 우상향 대각선
c3 = [0] * (2 * N - 1)  # 우하향 대각선
ans = 0

dfs(0)
print(ans)