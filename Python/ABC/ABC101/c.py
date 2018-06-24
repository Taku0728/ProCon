N, K = [int(x) for x in input().split()]
input()
if (N - K) % (K - 1) == 0:
    print(int((N - K) / (K - 1)) + 1)
else:
    print(int((N - K) / (K - 1) + 2))