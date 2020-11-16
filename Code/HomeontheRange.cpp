//Home on the Range 
#include<bits/stdc++.h>

using namespace std;
	
int n = 0;//阶数 
char farm[252][252] = {0};//牧场 
int num[252] = {0};//桶排，num[i]表示第i大的矩阵有num[i]个

//计数 对x行y列，把对应的数据记录入num[]数组 
void cnt(int x, int y)
{
	bool flag = 1; 
	//farm[x][y]如果为0，直接否决 
	if(farm[x][y] == '0'){
		return;
	}else{
		bool flag = 1;
		//可取用的正方形从2阶开始 
		for(int i = 1; i<=n-x; ++i){
			if(farm[x+i][y+i] == '1'){
				for(int j = i-1; j>=0; j--){
					if(farm[x+i][y+j] == '0'){
						flag = 0;
						break;
					}
				}
				for(int k = i-1; k>=0; k--){
					if(farm[x+k][y+i] == '0'){
						flag = 0;
						break;
					}
				}
			}else{
				flag = 0;
			}
			if(flag == 0){
				break;
			}else{
				num[i+1] += 1;
			}
		}

	}
	return;
}



int main()
{	
	//数据读入 
	cin>>n;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin>>farm[i][j];
		}
	} 
	//运算
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cnt(i, j);
		}
	} 
	//输出
	for(int i = 1; i<=n; i++){
		if(num[i] != 0){
			cout<<i<<" "<<num[i]<<endl;
		}
	} 	
} 
