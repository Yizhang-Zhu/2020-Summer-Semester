n = int(input())
a = 1
list = []
for i in range(n):
    a = input()
    list.append(a)
list2 = set(list)
len = len(list2)
print(len)