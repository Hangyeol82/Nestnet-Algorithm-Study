from collections import deque
from itertools import combinations

student = [input().strip() for _ in range(5)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def is_connected(comb):
    queue = deque([comb[0]])
    visited = set([comb[0]])
    count = 1
    
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if (nx, ny) in comb and (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append((nx, ny))
                count += 1
                if count == 7:
                    return True
    return False

def count_s(comb):
    return sum(1 for x, y in comb if student[x][y] == 'S')

positions = [(i, j) for i in range(5) for j in range(5)]
correct_position = list(combinations(positions, 7))

result = 0
for comb in correct_position:
    if count_s(comb) >= 4 and is_connected(comb):
        result += 1

print(result)