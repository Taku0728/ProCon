m = int(input())
km = int(m / 1000)
vv = 0
if m < 100:
    vv = 0
elif m <= 5000:
    vv = m / 100
elif m <= 30000:
    vv = km + 50
elif m <= 70000:
    vv = (m - 30000) / 5000 + 80
else:
    vv = 89
print('{:02}'.format(int(vv)))
