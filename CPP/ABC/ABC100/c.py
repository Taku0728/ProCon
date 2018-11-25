N = int(input())
A = list(map(int, input().split()))
count = 0
# すべてのAの要素について2で割り切れる回数を合計する
for a in A:
    while a % 2 == 0:
        a /= 2
        count += 1
print(count)
