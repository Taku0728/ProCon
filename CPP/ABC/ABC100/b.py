
# nがちょうど100でD回割り切れるかどうかを確かめる関数
def right(n, D):
    for i in range(D):
        if n == 0 or n % 100 != 0:
            return False
        n = int(n / 100)
    if n % 100 == 0:
        return False
    return True


D, N = map(int, input().split())
count = 0
i = 0
# すべての自然数iに対してright(i, D)を確かめる
# right(i, D)がN個カウントされるまで続ける
while count < N:
    if right(i, D):
        count += 1
    i += 1
print(i - 1)
