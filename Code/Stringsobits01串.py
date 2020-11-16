n,l,m = map(int, input().split())
num = []
for i in range(50):
    num.append([])
    for j in range(50):
        num[i].append(0)
for i in range(37):
    num[i][0] = 1
for i in range(37):
    for j in range(1, i+1):
        num[i][j] = num[i-1][j-1]+num[i-1][j]
pos1 = l
pos3 = n
while pos3>0:
    pos2 = 0
    for i in range(pos1+1):
        pos2 += num[pos3-1][i]
    if pos2<m:
        m -= pos2
        pos3 -= 1
        pos1 -= 1
        print("1", end='')
    else:
        pos3 -= 1
        print("0", end='')


