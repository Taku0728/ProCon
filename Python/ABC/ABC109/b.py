# sys.exit()を使う
import sys
N = int(input())
s = []
# 全文字列をsに格納する
for i in range(N):
    s.append(input())
# 全要素s0について、他の要素s1と一致しているか
# enumerate(s)で(i, s0)を(インデックス, 要素)として使える
for i, s0 in enumerate(s):
    for j, s1 in enumerate(s):
        if i != j and s0 == s1:
            print('No')
            # プログラム終了
            sys.exit()

# sの全要素について、最後の文字s0[0]が次の要素のs1[-1]と一致しているか
s0 = s[0]
for i in range(1, len(s)):
    # 次の文字列を取得
    s1 = s[i]
    if s0[-1] != s1[0]:
        print('No')
        # プログラム終了
        sys.exit()
    # s0を次の文字列に書き変える
    s0 = s1
print('Yes')
