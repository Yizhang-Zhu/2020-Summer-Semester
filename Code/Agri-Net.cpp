//Agri-Net -- 最小生成树 Prim算法 
#include<bits/stdc++.h>
#define initialize_weight 0x7f //超大 

using namespace std;

int main()
{
	int n = 0;//矩阵的阶数 3-100
	int matrix[101][101] = {0};//输入的矩阵
	int minlen = 0;//最小长度，所求
	//edge表示不在最小生成树中的点与在最小生成树中的点相连的最小边权,所以初值必须极大 
	int edge[10001] = {0};
	bool tree[10001] = {0};//不在最小生成树内的点为false 
	
	//edge表示不在最小生成树中的点与在最小生成树中的点相连的最小边权,所以初值必须极大 	
	memset(edge, initialize_weight, sizeof(edge));//初始化 
	cin>>n;
	edge[1] = 0; 
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin>>matrix[i][j];
		}
	}	
	
	for(int i = 1; i<=n; i++){
		int e = 0;//每轮loop都初始化 
		for(int j = 1; j<=n; j++){
			//如果某条边j还不在生成树内，且权重最小，就把它加入生成树 
			if(!tree[j] && edge[j]<edge[e]){
				e = j; 
			} 
		}
		tree[e] = 1;//把它加入生成树
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
