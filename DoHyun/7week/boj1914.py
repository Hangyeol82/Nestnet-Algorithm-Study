N=int(input())
print(2**N-1)
def hanoi(a,b,n):
    if n==1:
        print(a,b)
        return
    hanoi(a,6-a-b,n-1)
    print(a,b)
    hanoi(6-a-b,b,n-1)
if N<=20:hanoi(1,3,N)

