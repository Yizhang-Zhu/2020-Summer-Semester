//Fractions to Decimals
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n = 0;//���� 
	int d = 0;//��ĸ 
	int t = 0;//С����ǰ 
	int r = 0;//�������ݴ棩 
	int right = 0;//�����ŵ�λ�� 
	int left = 0;//�����ŵ�λ�� 
	//int x = 0;//С����ĳһλ���ݴ棩 
	int k = 0;//С�����ֵ�λ�� 
	int cnt = 0;//��¼λ������ĿҪ�󳬹�79λҪ������� 
	int decimal[100005] = {0};//decimal[i]������������С�����ֵ�iλ����0��ʼ��
	//������������ظ���˵������ѭ���� 
	map<int, int> remainder;//��¼֮ǰ���ֹ������� 
	int start = 0;//С��ѭ�����ֿ�ʼλ��
	int temp = 0;//С��ѭ����ǰ�����жϵ�λ��
	int end = 0;//С��ѭ�����ֽ���λ�� 
	bool flag = 0;//�Ƿ����� ����1��������0 
	cin>>n>>d;

	t = n/d;//�������� 
    int integer = t;
	r = n%d;//��������� 
	cnt = 2;//λ����1��ʼ����Ϊһ����С���� 
	r = n%d*10; 
	
	if(n/d!=0)cnt+=log10(n/d);
//	while(t != 0){//��������������Ҫ���ַ���
//		cnt++;
//		t /= 10;
//	}
	
	for(int i = 1; i<=d*2; i++){
		decimal[++k] =  r/d;//С��
		if(remainder[r]){//ĳ������֮ǰ���ֹ��� 
			left = remainder[r];//�����ŵ�����һ����λ��
			right = i-1;//������-1 
			break;//over 
		} 
		remainder[r] = i;
		if(r%d == 0){
			break;//��������over 
		}
		r = r%d*10;//��һλ 
	}
	//������������ֺ�С���� 	
	cout<<integer<<".";
	for(int i = 1; i<=k; i++){
		cnt++;
		if(i == left){
			cnt++;
			cout<<"(";
		}
		cout<<decimal[i];
		if(i == right){
			cout<<")";
			break;
			return 0;//�������������ַ�������������� 
		}
		if(cnt%76 == 0){
			cout<<"\n";
			cnt = 0;//���У�cnt�������¿�ʼ���� 
		}
	}
	
}



	







//��bug 
////Fractions to Decimals
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;//���� 
//	int d = 0;//��ĸ 
//	int t = 0;//С����ǰ 
//	int r = 0;//�������ݴ棩 
//	//int x = 0;//С����ĳһλ���ݴ棩 
//	int k = 0;//С�����ֵ�λ�� 
//	int cnt = 0;//��¼λ������ĿҪ�󳬹�79λҪ������� 
//	int decimal[100005] = {0};//decimal[i]������������С�����ֵ�iλ����0��ʼ��
//	//������������ظ���˵������ѭ���� 
//	int remainder[10000] = {0};//remainder[i]��ʾ����i��һ�γ��ֵ�λ��
//	int start = 0;//С��ѭ�����ֿ�ʼλ��
//	int temp = 0;//С��ѭ����ǰ�����жϵ�λ��
//	int end = 0;//С��ѭ�����ֽ���λ�� 
//	bool flag = 0;//�Ƿ����� ����1��������0 
//	cin>>n>>d;
//	memset(remainder, -1, sizeof(remainder));//��ʼ�� 
//	t = n/d;//�������� 
//	int integer = t; 
//	r = n%d;//��������� 
//	
//	//ѭ���жϴ��� 
//	while(true){
//		if(remainder[r] != -1){//ĳ�������ڶ��γ��֣�Ԥʾ��ѭ������ 
//			end = temp;
//			temp = remainder[r];
//		}
//		remainder[r] = temp;
//		r = r*10;//����*10��ĩβ��0
//		decimal[temp] = r/d; //��ǰ���������̾�����һ��С�� 
//		r = r%d;
//		if(r == 0){//���� 
//			flag = 1;
//			break;
//		}
//		temp++;//�ƶ�����һλ���� 		
//	}
//	
//	//���������ʽ
//	cnt = 1;//λ���ĳ�ʼ��1��ʼ����ΪС���� 
//	cout<<integer<<"."; //������������ֺ�С����
//	while(t != 0){//��������������Ҫ���ַ���
//		cnt++;
//		t /= 10;
//	} 
//	for(int i = 0; i<temp; i++){
//		cout<<decimal[i];
//		cnt++;
//		if(cnt%76 == 0){
//			cout<<"\n";
//		}
//	}
//	//���flag == 0������������
//	if(flag == 0){
//		//ѭ�����ֿ�ʼ 
//		cout<<"(";
//		cnt++;
//		if(cnt%76 == 0){
//			cout<<"\n";
//		}
//		for(int i = temp; i<end; i++){
//			cout<<decimal[i];
//			cnt++;
//			if(cnt%76 == 0){
//				cout<<"\n";
//			}
//		}
//		cout<<")";
//		cnt++;
//		if(cnt%76 == 0){
//			cout<<"\n";
//		}
//	}
//	return 0;
//	
//	 
//	
//	
//	
//	
//}
