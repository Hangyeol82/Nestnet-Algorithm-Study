import math

n = int(input())

star = [[0] * n for _ in range(n)]

def rec(x,y,m):
    if m == 1:
        star[x][y] = 1
    else:
        for i in range(x, x+m, m//3):
            for j in range(y, y+m, m//3):
                if i == x+m//3 and j == y+m//3:
                    continue
                else:
                    rec(i, j, m//3)

rec(0,0,n)
for i in range(n):
    for j in range(n):
        if star[i][j] == 1:
            print("*", end = "")
        else:
            print(" ", end = "")
    print()