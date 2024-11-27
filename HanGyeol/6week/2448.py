n = int(input())

star = [[0] * (n*2-1) for _ in range(n)]
pattern = [[0,0],[1,-1],[1,1],[2,-2],[2,-1],[2,0],[2,1],[2,2]]

def rec(x,y,n):
    if n == 3:
        for i in pattern:
            star[x+i[0]][y+i[1]] = 1
    else:
        rec(x,y,n//2)
        rec(x+n//2,y-n//2,n//2)
        rec(x+n//2,y+n//2,n//2)

rec(0,n-1,n)

for i in range(n):
    for j in range(n*2-1):
        if star[i][j] == 1:
            print("*",end = "")
        else:
            print(" ",end = "")
    print()