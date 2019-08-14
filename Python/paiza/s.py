
def get_abc(k):
    if len(abc) < k + 1:
        for i in range(len(abc), k + 1):
            abc.append('A' + abc[i - 1] + 'B' + abc[i - 1] + 'C')
    return abc[k]


def out(k, s, t):
    ret = ''
    if k == 0:
        return ''
    if t == 0:
        return ret
    if s == 0:
        ret += 'A'
    s = max(0, s - 1)
    t = max(0, t - 1)
    if t < length[k - 1]:
        return ret + out(k - 1, s, t)
    if s < length[k - 1]:
        ret += out(k - 1, s, length[k - 1])
    s = max(0, s - length[k - 1])
    t = max(0, t - length[k - 1])
    if t == 0:
        return ret
    if s == 0:
        ret += 'B'
    s = max(0, s - 1)
    t = max(0, t - 1)
    if t < length[k - 1]:
        return ret + out(k - 1, s, t)
    if s < length[k - 1]:
        ret += out(k - 1, s, length[k - 1])
    s = max(0, s - length[k - 1])
    t = max(0, t - length[k - 1])
    if t == 0:
        return ret
    if s == 0:
        ret += 'C'
    return ret


k, s, t = map(int, input().split())
length = [0, 3]
for i in range(1, 50):
    length.append(length[i] + length[i] + 3)
abc = ['']
print(out(k, s-1, t))
