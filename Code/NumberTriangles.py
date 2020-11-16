#Number Triangles 数字金字塔--动态规划
def numtri():
    N = int(input())#输入塔的层数
    P = [[]for i in range(N)]
    for i in  range(N):
        L = []
        S = input()
        L = S.split(sep = ' ')
        for a in L:
            P[i].append(int (a))
    D = [[]for i in range(N)]#初始化动态规划表
    for i in range(N):
        for j in range(i+1):
            D[i].append(P[i][j])
    for i in range(N-2, -1, -1):
        for j in range(i+1):
            if D[i+1][j]+P[i][j] >= D[i+1][j+1]+P[i][j]:
                D[i][j] = D[i+1][j]+P[i][j]
            else:
                D[i][j] = D[i+1][j+1]+P[i][j]
    print(D[0][0])

numtri()