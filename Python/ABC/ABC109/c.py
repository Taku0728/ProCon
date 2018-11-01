# math.gcd()を使う
import math
N, X = map(int, input().split())
# 一行の入力をリストxに入れる
x = list(map(int, input().split()))
# すべての(x[i]-X)の最大公約数が答え
# 最初の最大公約数
t = abs(x[0] - X)
for a in x:
    # 最大公約数を更新
    t = math.gcd(t, abs(a - X))
print(t)
