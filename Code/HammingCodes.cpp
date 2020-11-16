//Hamming Codes 海明码 
/*给出 N,B和D:找出 N 个编码（1 <= N <= 64）,
每个编码有 B 位（1 <= B <= 8）,使得
两两编码之间至少有 D 个单位的汉明距离（1 <= D <= 7）*/
#include<bits/stdc++.h>

using namespace std;

int n = 0, b = 0, d = 0;
int ham_code[100] = {0};//Hamming Code
int cnt = 0;//ham_code的索引 

//判断汉明距离是否>=d 
bool judge_ham(int x, int y)
{
	int flag = x^y;//取异或,有几个1，汉明距离就是几 
	int dis = 0;//汉明距离
	while(flag>0){
		if(flag%2 == 1){//二进制某位为1 
			dis++;
		}
		flag = flag>>1;//右移一位 
	} 
	if(dis >= d){
		return true;
	}else{
		return false;
	}
} 

//判断某个数i是不是与ham_code表中的每一个数的汉明距离>=d 
bool ham(int x)
{
	for(int i = 1; i<=cnt; i++){
		if(judge_ham(x, ham_code[i]) == false){
			return false;
		}
	}
	return true;
}

int main()
{
	cin>>n>>b>>d;
	//index++;
	for(int i = 0; i<256 && cnt<n; i++){
		if(ham(i)){
			ham_code[++cnt] = i;
		}
	}
	//输出，注意格式 
	for(int i = 1; i<=cnt; i++){
		if(i%10 == 1){
			cout<<ham_code[i];
		}else{
			cout<<" "<<ham_code[i]; 
		}
		
		if(i%10 == 0){
			cout<<"\n";//每行10个 
		}
	}
	return 0;
	
	
}
