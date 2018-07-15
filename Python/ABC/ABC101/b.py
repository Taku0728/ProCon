N = int(input())
S = 0
NN = N
while N > 0:
    S += N % 10
    N = int(N / 10)
if NN % S == 0:
    print('Yes')
else:
    print('No')
