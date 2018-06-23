K, S = [int(x) for x in input().split()]
sum = 0
for i in range(0, min(K, S) + 1):
    for j in range(0, min(K, S - i) + 1):
        if S - i - j <= K:
            sum += 1
print(sum)