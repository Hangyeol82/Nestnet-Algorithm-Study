import sys
input = sys.stdin.readline

from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    numbers = list(map(int,input().split()))
    visited = [0] * n
    answer = 0
    for i in range(n):
        if visited[i] == 1:
            continue
        queue = deque([i+1])
        result = 1
        check = i+1
        team = [i+1]
        while(queue):
            node = queue.popleft()
            visited[node-1] = 1
            if numbers[node-1] == check:
                answer += result
                break
            if visited[numbers[node-1]-1] == 0:
                result += 1
                team.append(numbers[node-1])
                queue.append(numbers[node-1])
            else:
                for j in team:
                    if j == numbers[node-1]:
                        break
                    else:
                        result -= 1
                answer += result
                break
    print(n-answer)