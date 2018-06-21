x,y,R=input().split()
c=[input() for _ in range(9)]
i,j=0,0
if R.find('U')>-1:i=-1
if R.find('D')>-1:i=1
if R.find('L')>-1:j=-1
if R.find('R')>-1:j=1
p,q=int(y)-1,int(x)-1
a=''
for _ in range(4):
    a+=c[p][q]
    if not 0<=p+i<9:i=-i
    if not 0<=q+j<9:j=-j
    p+=i
    q+=j
print(a)