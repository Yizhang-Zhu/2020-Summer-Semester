//Cow Pedigrees奶牛家谱
#include<bits/stdc++.h>

using namespace std;

int n = 0;//节点数
int k = 0;//二叉树的高度
int dp[101][201];//动态规划表
int num = 0;//可能的家谱树数量
int resluts = 0;//num模9901

int main()
{
	cin>>n>>k;
	for(int i = 1; i<=k; i++){
		dp[i][1] = 1;
    }
	for(int i = 1; i<=k; i++){
		for(int j = 3; j<=n; j+=2){
			for(int t = 1; t<=j-2; t+=2){
				dp[i][j] = (dp[i][j]+dp[i-1][t]*dp[i-1][j-1-t])%9901;
            }
        }
    }
    num = dp[k][n]-dp[k-1][n]+9901;
    resluts = num%9901;
	cout<<resluts<<endl;
}