//Hamming Codes ������ 
/*���� N,B��D:�ҳ� N �����루1 <= N <= 64��,
ÿ�������� B λ��1 <= B <= 8��,ʹ��
��������֮�������� D ����λ�ĺ������루1 <= D <= 7��*/
#include<bits/stdc++.h>

using namespace std;

int n = 0, b = 0, d = 0;
int ham_code[100] = {0};//Hamming Code
int cnt = 0;//ham_code������ 

//�жϺ��������Ƿ�>=d 
bool judge_ham(int x, int y)
{
	int flag = x^y;//ȡ���,�м���1������������Ǽ� 
	int dis = 0;//��������
	while(flag>0){
		if(flag%2 == 1){//������ĳλΪ1 
			dis++;
		}
		flag = flag>>1;//����һλ 
	} 
	if(dis >= d){
		return true;
	}else{
		return false;
	}
} 

//�ж�ĳ����i�ǲ�����ham_code���е�ÿһ�����ĺ�������>=d 
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
	//�����ע���ʽ 
	for(int i = 1; i<=cnt; i++){
		if(i%10 == 1){
			cout<<ham_code[i];
		}else{
			cout<<" "<<ham_code[i]; 
		}
		
		if(i%10 == 0){
			cout<<"\n";//ÿ��10�� 
		}
	}
	return 0;
	
	
}
