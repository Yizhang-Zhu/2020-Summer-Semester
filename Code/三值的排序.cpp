//三值的排序 
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n = 0;//输入序列的长度 
	//记录1.2.3的数量 
	int first = 0;
	int second = 0;
	int third = 0;
	int cnt = 0; //交换次数计数器
	int list[1001] = {0};//记录输入的序列
	int order[1001] = {0};//记录恰当的顺序
	int delt[1001] = {0};//记录差值 
	//记录delt数组中1、2、-1、-2的数量 
	int delt_1 = 0;
	int delt_2 = 0;
	int delt_m1 = 0;
	int delt_m2 = 0;
	int a = 0;
	int b = 0;
	cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>list[i];
		if(list[i] == 1){
			first++;
		}else if(list[i] == 2){
			second++;
		}else if(list[i] == 3){
			third++;
		}
	} 
	for(int i = 1; i<=first; i++){
		order[i] = 1;
	}
	for(int i = 1+first; i<=first+second; i++){
		order[i] = 2;
	}
	for(int i = 1+first+second; i<=n; i++){
		order[i] = 3;
	}
	for(int i = 1; i<=n; i++){
		delt[i] = list[i]-order[i];
		if(delt[i] == 1){
			delt_1++;
		}else if(delt[i] == 2){
			delt_2++;
		}else if(delt[i] == (-2)){
			delt_m2++;
		}else if(delt[i] == (-1)){
			delt_m1++;
		}
	}
	a = min(delt_2, delt_m2);
	b = max(delt_2, delt_m2);
	cnt = min(delt_1, delt_m1)+a+(b-a)*2;
	cout<<cnt<<endl;
	
	
	
	
}
