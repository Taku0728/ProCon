N, A, B = [int(x) for x in input().split()]
sum = 0
for i in range(1, N + 1):
    n = i
    s = 0
    while n > 0:
        s += n % 10
        n = int(n / 10)
    if A <= s <= B:
        sum += i
print(sum)