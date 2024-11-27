def hanoi(n, start, end, aux):
    if n == 1:
        print(f"{start} {end}")
        return
    hanoi(n-1, start, aux, end)
    print(f"{start} {end}")
    hanoi(n-1, aux, end, start)

n = int(input())
print(2**n - 1)  # 총 이동 횟수 출력

if n <= 20:
    hanoi(n, 1, 3, 2)


# n = int(input())

# def rec(x):
#     if x == 1:
#         return 1
#     else:
#         return rec(x-1)*2 + 1
# answer = rec(n)
# print(answer)

# if n <= 20:
#     arr = [[0,0] for _ in range(answer)]
#     arr[0][0] = 1
#     arr[0][1] = 3
#     for i in range(2, n+1):
#         l = rec(i)
#         for j in range(l):
#             if j < l//2:
#                 if arr[j][0] == 2:
#                     arr[j][0] = 3
#                 elif arr[j][0] == 3:
#                     arr[j][0] = 2
#                 if arr[j][1] == 2:
#                     arr[j][1] = 3
#                 elif arr[j][1] == 3:
#                     arr[j][1] = 2
#             elif j == l//2:
#                 arr[j][0] = 1
#                 arr[j][1] = 3
#             else:
#                 if arr[j-(l//2+1)][0] == 3:
#                     arr[j][0] = 1
#                 else:
#                     arr[j][0] = arr[j-l//2-1][0]+1
#                 if arr[j-(l//2+1)][1] == 3:
#                     arr[j][1] = 1
#                 else:
#                     arr[j][1] = arr[j-l//2-1][1]+1
#     for i in range(answer):
#         print(arr[i][0], arr[i][1])