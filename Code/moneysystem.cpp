//money system
#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long v = 0;//������������
	long long n = 0;//Ŀ��Ǯ�� 
	long long money[25] = {0};//���ڴ�Ÿ��ֻ����������� 
	//�ϳ�xԪ����table[x]�ַ�����table��¼�� DP[j] += DP[j-h[i]] 
	long long dp[10000] = {1};
	cin>>v>>n;
	for(int i = 1; i<=v; i++){
		cin>>money[i];//�±��1��ʼ 
	}
	for(int i = 1; i<=v; i++){
		for(int j = money[i]; j<=n; j++){
			dp[j] += dp[j-money[i]];
		}
	}
	cout<<dp[n]<<endl;
}
