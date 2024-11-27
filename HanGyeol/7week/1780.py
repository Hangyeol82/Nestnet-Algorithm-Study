n = int(input())

paper = [[0] * n for _ in range(n)]

for i in range(n):
    paper[i] = list(map(int, input().split()))
minus = 0
zero = 0
plus = 0
def rec(x1,y1,s):
    global minus, zero, plus
    check = paper[x1][y1]
    not_true = 0
    if s != 1:
        for i in range(s):
            for j in range(s):
                if paper[x1+i][y1+j] != check:
                    not_true = 1
                    break
            if not_true == 1:
                break
    if not_true == 0:
        if paper[x1][y1] == -1:
            minus += 1
        elif paper[x1][y1] == 0:
            zero += 1
        else:
            plus += 1
    else:
        for i in range(x1,x1+s,s//3):
            for j in range(y1,y1+s,s//3):
                rec(i,j,s//3)

rec(0,0,n)

print(minus)
print(zero)
print(plus)