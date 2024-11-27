import sys
input = sys.stdin.readline

from collections import deque
t = int(input())

for i in range(t):
    l = int(input())
    visited = [[0] * l for _ in range(l)]
    loc = list(map(int, input().split()))
    dest = list(map(int, input().split()))
    if loc == dest:
        print(0)
        continue
    queue = deque()
    queue.append(loc)
    answer = 0
    check = 0
    while check == 0:
        answer += 1
        for _ in range(len(queue)):
            now = queue.popleft()
            for (i,j)in [(2,-1),(2,1),(-2,1),(-2,-1),(1,-2),(1,2),(-1,2),(-1,-2)]:
                if 0 <= now[0] + i < l and 0 <= now[1] + j < l and visited[now[0]+i][now[1]+j] == 0:
                    if [now[0] + i, now[1] + j] == dest:
                        check = 1
                        break
                    queue.append([now[0] + i, now[1] + j])
                    visited[now[0]+i][now[1]+j] = 1
            if check == 1:
                break
    print(answer)