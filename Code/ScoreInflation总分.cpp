//Score Inflation �ܷ�
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m = 0;//����ʱ��
	int n = 0;//��Ŀ��������� 
	cin>>m>>n;
	int p[10001] = {0};//ĳһ������Ŀ�ķ��� -- value 
	int t[10001] = {0};//ĳһ������Ŀ��ʱ -- cost 
	int table[10001] = {0};//��¼���� value table
	//�������� 
	for(int i = 1; i<=n; i++){
		cin>>p[i]>>t[i];
	}
	//greedy alg
	for(int i = 1; i<=n; i++){
		for(int j = t[i]; j<=m; j++){//����ʱ�䲻�����޶���m 
			//table[j]�Ǻ�ʱ������j�ĵ÷����
			//�����������һ����ѡ��table[j]����һ���ⲻѡ������ѡ����һ����Ŀ���Ǻ�֮ǰһ������ʱj�£��÷�����һ����table[j-t[i]]�� �ټ�����ѡ��p[i] 
			table[j] = max(table[j], table[j-t[i]]+p[i]);
		}
	} 
	cout<<table[m]<<endl; 
	 
	
}
