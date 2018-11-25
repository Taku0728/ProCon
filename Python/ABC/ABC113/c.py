# 都市の情報を格納するクラス
class ipy:
    def __init__(self, i, p, y):
        # 都市番号(全体)
        self.i = i
        # 県番号
        self.p = p
        # 誕生年
        self.y = y


N, M = map(int, input().split())
# 都市の情報を格納するipyのリスト
list_ipy = []
# 入力を受け取り、list_ipyの格納
for i in range(M):
    p, y = map(int, input().split())
    list_ipy.append(ipy(i, p, y))
# 都市を誕生年順にソート
list_ipy.sort(key=lambda x: x.y)
# 県の都市の数をカウントする辞書
p_count = {}
# 出力するidの２つの整数を格納する辞書
out = {}
# すべての都市xについてループ
for x in list_ipy:
    # 県の都市のカウントを増やす
    if x.p in p_count:
        p_count[x.p] += 1
    else:
        p_count[x.p] = 1
    # 全体のx.i番目の都市はx.p県のx.p番目の都市
    out[x.i] = [x.p, p_count[x.p]]
# idを出力する
for k in out:
    print('{0:06d}{1:06d}'.format(out[k][0], out[k][1]))
