
import math

x, y = int(input()), int(input())
x /= math.gcd(x, y)
y /= math.gcd(x, y)
d = y * (y + 1) / 2 - x
if d < 0:
    