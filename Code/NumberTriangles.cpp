//number triangles 数字三角形
#include<bits/stdc++.h>

using namespace std;

int P[1001][1001] = {0};//塔，P[层数][左起第几个]，从1开始
int D[1001][1001] = {0};//动态规划表，初始化

int main(){
    int n = 0;
    cin>>n;//输入的三角形塔的层数

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cin>>P[i][j];
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            D[i][j] = max(D[i-1][j-1], D[i-1][j])+P[i][j];
        }
    }
    int max_sum = 0;
    for(int i = 1; i<=n; i++){
        max_sum = max(max_sum, D[n][i]);
    }
    cout<<max_sum<<endl;
    return 0;
}