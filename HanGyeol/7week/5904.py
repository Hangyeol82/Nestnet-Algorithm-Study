
import sys
sys.setrecursionlimit(10**9)
n = int(input())

k = 0
l = 3
i = 4

while l < n:
    k += 1
    l = l * 2 + i
    i += 1

def rec(k, x, l):
    prev_l = (l - (k + 3)) // 2
    if x <= prev_l:
        rec(k - 1, x, prev_l)
    elif prev_l < x <= prev_l + k + 3:
        if x - prev_l == 1:
            print('m')
        else:
            print('o')
    else:
        rec(k - 1, x - prev_l - (k + 3), prev_l)

rec(k, n, l)