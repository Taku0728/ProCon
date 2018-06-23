S = input()
L = ['dream', 'erase', 'dreamer', 'eraser']
f = False
while len(S) > 0:
    f = False
    for l in L:
        if len(S) >= len(l) and l == S[:len(l)]:
            S1 = S[len(l):]
            for k in L:
                if len(S1) == 0 or len(S1) >= len(k) and k == S1[:len(k)]:
                    f = True
                    break
            if f:
                S = S1
                break
    if not f: break
if f:
    print('YES')
else:
    print('NO')