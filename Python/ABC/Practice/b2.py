A = int(input())
B = int(input())
C = int(input())
X = int(input())

sum = 0
for i in range(min(int(X / 500), A) + 1):
    x = X - 500 * i
    for j in range(min(int(x / 100), B) + 1):
        y = x - 100 * j
        if (y <= 50 * C):
            sum += 1
print(sum)