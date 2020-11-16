// //test

// #include<bits/stdc++.h>

// using namespace std;

// int main()
// {

// }



/*
LGOJ P2727 01串 Stringsobits
主要算法：先算出来C(i,j)的值(递推预处理)，然后再逐位判断这一位是1还是0 
*/ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=31+10;
ll C[MAXN][MAXN],n,L,m;//要开long long 因为最大为2^31=max_int+1，开int爆精度 
int main()
{
	scanf("%lld%lld%lld",&n,&L,&m);
	for(int i=0;i<=36;i++) C[i][0]=1;
	for(int i=0;i<=36;i++)
		for(int j=1;j<=i;j++)
		C[i][j]=C[i-1][j-1]+C[i-1][j];//C(i,j)=C(i-1,j-1)+C(i-1,j)
	ll temp1=L;//还剩几个可选 
	ll temp3=n;//操作的是第几位 
	while(temp3>0)
	{
		ll temp2=0;
		for(int i=0;i<=temp1;i++)
		{
			temp2+=C[temp3-1][i];//算出如果这一位要想是1，低位需要先占用的方案个数 
		}
		if(temp2<m)//如果"挨得上"这一位是1 
		{
			m-=temp2;
			temp3--;//将操作指针后移 
			temp1--;//选掉一个1，剩下可选的-1 
			printf("1");
		}
		else//"挨不上"这一位是1 
		{
			temp3--; 
			printf("0");
		}
	}
	printf("\n");
	return 0;
}
