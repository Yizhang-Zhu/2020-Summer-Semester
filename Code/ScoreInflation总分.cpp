//Score Inflation 总分
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m = 0;//竞赛时间
	int n = 0;//题目种类的数量 
	cin>>m>>n;
	int p[10001] = {0};//某一种类题目的分数 -- value 
	int t[10001] = {0};//某一种类题目耗时 -- cost 
	int table[10001] = {0};//记录分数 value table
	//读入数据 
	for(int i = 1; i<=n; i++){
		cin>>p[i]>>t[i];
	}
	//greedy alg
	for(int i = 1; i<=n; i++){
		for(int j = t[i]; j<=m; j++){//控制时间不超出限定的m 
			//table[j]是耗时不超过j的得分最大
			//两种情况：这一种题选：table[j]；这一种题不选，还是选择上一种题目，那和之前一样，耗时j下，得分是上一个（table[j-t[i]]） 再加上新选的p[i] 
			table[j] = max(table[j], table[j-t[i]]+p[i]);
		}
	} 
	cout<<table[m]<<endl; 
	 
	
}
