N, M, X, Y = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
# xの最大(首都Xを含む)がyの最小(首都Yを含む)より小さいかどうか判断する
if max(X, max(x)) < min(Y, min(y)):
    print('Yes')
else:
    print('No')
