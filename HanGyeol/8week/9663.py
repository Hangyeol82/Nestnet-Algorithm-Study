n = int(input())
arr = []
ans = 0
def is_correct(x,y):
    for i in range(len(arr)):
        if abs(arr[i] - y) == abs(i - x):
            return False
    return True
def back(a):
    global ans
    if a == n:
        ans+=1
    else:
        for i in range(n):
            if i in arr:
                continue
            elif is_correct(a,i):
                arr.append(i)
                back(a+1)
                arr.pop()
back(0)
print(ans)