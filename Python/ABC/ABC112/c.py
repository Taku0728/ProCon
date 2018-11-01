N = int(input())
lx, ly, lh = [], [], []
for i in range(N):
    x, y, h = map(int, input().split())
    lx.append(x)
    ly.append(y)
    lh.append(h)
# すべての座標(i, j)について全探索
# つまり全ての座標について頂点かどうか確認する
for i in range(101):
    for j in range(101):
        # 高さが0でないところを一つ探す
        k = 0
        while lh[k] == 0:
            k += 1
        # その高さから頂点の高さHを計算する
        H = int(abs(lx[k]-i)) + int(abs(ly[k]-j)) + lh[k]
        # すべての点について高さhが正しいか検証
        b = True
        for k in range(len(lh)):
            if lh[k] != max(H - int(abs(lx[k]-i)) - int(abs(ly[k]-j)), 0):
                b = False
                break
        # すべての高さが正しければ頂点の座標と高さを出力する
        if b:
            print(i, j, H)
