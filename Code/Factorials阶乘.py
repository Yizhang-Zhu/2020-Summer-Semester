#Factorials 阶乘
a = int(input())
s = 1
for i in  range(1,a+1):
    s *= i
for i in reversed(str(s)):
    if int(i) != 0:
        print(int(i))
        break