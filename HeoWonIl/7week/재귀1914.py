def hanoi(n,s,e,o):
    if n==0:
        return
    hanoi(n-1,s,o,e)
    print(s,e)
    hanoi(n-1,o,e,s)

n=int(input())
answer = []
print(2**n-1)
if n <= 20:
    hanoi(n,1,3,2)