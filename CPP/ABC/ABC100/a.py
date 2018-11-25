A, B = map(int, input().split())
# AとBがどちらも8以下であればよい
if A <= 8 and B <= 8:
    print('Yay!')
else:
    print(':(')
