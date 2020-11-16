# n=input()
# m=input()
# print(n,m)

# n = int(input())
# a = 1
# list = []
# for i in range(n):
#     a = input()
#     list.append(a)
# list2 = set(list)
# l=len(list2)
# print(l)


# n = int(input())
# l = int(input())
# m = int(input())
n,l,m = map(int, input().split())
a = []
for i in range(50):
	a.append([])
	for j in range(50):
		a[i].append(0)
for i in range(37):
	a[i][0] = 1
for i in range(37):
	for j in range(1, i+1):
		a[i][j] = a[i-1][j-1]+a[i-1][j]
temp1 = l
temp3 = n
while temp3>0:
	temp2 = 0
	for i in range(temp1+1):
		temp2 += a[temp3-1][i]
	if temp2<m:
		m -= temp2
		temp3 -= 1
		temp1 -= 1
		print("1", end='')
	else:
		temp3 -= 1
		print("0", end='')
#print("\n")