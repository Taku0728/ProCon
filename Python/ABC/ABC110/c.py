def solve():
    s = input()
    t = input()
    d0 = {}
    d1 = {}
    if len(s) != len(t):
        print('No')
        return
    for i in range(len(s)):
        if s[i] in d0:
            if t[i] != d0[s[i]]:
                print('No')
                return
        elif t[i] in d1:
            if s[i] != d1[t[i]]:
                print('No')
                return
        else:
            d0[s[i]] = t[i]
            d1[t[i]] = s[i]
    print('Yes')


solve()
