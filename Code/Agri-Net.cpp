//Agri-Net -- ��С������ Prim�㷨 
#include<bits/stdc++.h>
#define initialize_weight 0x7f //���� 

using namespace std;

int main()
{
	int n = 0;//����Ľ��� 3-100
	int matrix[101][101] = {0};//����ľ���
	int minlen = 0;//��С���ȣ�����
	//edge��ʾ������С�������еĵ�������С�������еĵ���������С��Ȩ,���Գ�ֵ���뼫�� 
	int edge[10001] = {0};
	bool tree[10001] = {0};//������С�������ڵĵ�Ϊfalse 
	
	//edge��ʾ������С�������еĵ�������С�������еĵ���������С��Ȩ,���Գ�ֵ���뼫�� 	
	memset(edge, initialize_weight, sizeof(edge));//��ʼ�� 
	cin>>n;
	edge[1] = 0; 
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin>>matrix[i][j];
		}
	}	
	
	for(int i = 1; i<=n; i++){
		int e = 0;//ÿ��loop����ʼ�� 
		for(int j = 1; j<=n; j++){
			//���ĳ����j�������������ڣ���Ȩ����С���Ͱ������������� 
			if(!tree[j] && edge[j]<edge[e]){
				e = j; 
			} 
		}
		tree[e] = 1;//��������������
		for(int k = 1; k<=n; k++){
			if(!tree[k] && matrix[e][k]<edge[k]){
				edge[k] = matrix[e][k];
			}
		}
	}
	
	for(int i = 1; i<=n; i++){
		minlen += edge[i];
	}
	cout<<minlen<<endl;

	
}
