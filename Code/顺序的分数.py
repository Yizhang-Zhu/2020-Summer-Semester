from fractions import Fraction
#python可以处理分数的函数,Fraction(i, j)是既约分数i/j
n = int(input())#输入的数字
fraction_set = set()
for i in range(n+1):
    for j in range(1, n+1):
        if i<=j:
            fraction_set.add(Fraction(i, j))
#去除重复元素，用集合
fraction_list = list(fraction_set)
fraction_list.sort()
for num in fraction_list:
    print(num.numerator, end='')
    print('/', end='')
    print(num.denominator)