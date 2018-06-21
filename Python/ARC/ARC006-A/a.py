E = [int(x) for x in input().split()]
B = int(input())
L = [int(x) for x in input().split()]
count = 0
for i in range(6):
    if E[i] in L:
        count += 1
if count == 6:
    print(1)
elif count == 5:
    if B in L:
        print(2)
    else:
        print(3)
elif count > 2:
    print(8 - count)
else:
    print(0)
    
#14:08