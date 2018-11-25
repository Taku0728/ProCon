N, M = map(int, input().split())
# 綺麗さ、おいしさ、人気度それぞれに対して正負の組み合わせ８通り
d = [[1, 1, 1], [1, 1, -1], [1, -1, 1], [1, -1, -1],
     [-1, 1, 1], [-1, 1, -1], [-1, -1, 1], [-1, -1, -1]]
# すべてのケーキについてdとの内積を求める（ケーキの点数）
array = [[] for _ in range(8)]
for i in range(N):
    x, y, z = map(int, input().split())
    for n in range(8):
        array[n].append(d[n][0] * x + d[n][1] * y + d[n][2] * z)
best = -9999999999999999999
for a in array:
    # 降順に並べ替える
    a.sort(reverse=True)
    # 大きいものからM個選び、点数の合計を計算する
    best = max(best, sum(a[:M]))
print(best)
