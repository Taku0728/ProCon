N = int(input())
L = [int(input()) for _ in range(N)]
print(sum(L))
print(max(0, 2 * max(L) - sum(L)))
