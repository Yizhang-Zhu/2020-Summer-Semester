//Home on the Range 
#include<bits/stdc++.h>

using namespace std;
	
int n = 0;//���� 
char farm[252][252] = {0};//���� 
int num[252] = {0};//Ͱ�ţ�num[i]��ʾ��i��ľ�����num[i]��

//���� ��x��y�У��Ѷ�Ӧ�����ݼ�¼��num[]���� 
void cnt(int x, int y)
{
	bool flag = 1; 
	//farm[x][y]���Ϊ0��ֱ�ӷ�� 
	if(farm[x][y] == '0'){
		return;
	}else{
		bool flag = 1;
		//��ȡ�õ������δ�2�׿�ʼ 
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
	//���ݶ��� 
	cin>>n;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin>>farm[i][j];
		}
	} 
	//����
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cnt(i, j);
		}
	} 
	//���
	for(int i = 1; i<=n; i++){
		if(num[i] != 0){
			cout<<i<<" "<<num[i]<<endl;
		}
	} 	
} 
