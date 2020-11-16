//money system
#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long v = 0;//货币种类数量
	long long n = 0;//目标钱数 
	long long money[25] = {0};//用于存放各种货币面额的数组 
	//合成x元，有table[x]种方法（table记录） DP[j] += DP[j-h[i]] 
	long long dp[10000] = {1};
	cin>>v>>n;
	for(int i = 1; i<=v; i++){
		cin>>money[i];//下标从1开始 
	}
	for(int i = 1; i<=v; i++){
		for(int j = money[i]; j<=n; j++){
			dp[j] += dp[j-money[i]];
		}
	}
	cout<<dp[n]<<endl;
}
