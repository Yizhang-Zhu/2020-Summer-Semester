//Humble Numbers 丑数
#include<bits/stdc++.h>

using namespace std;

int k = 0;//集合元素个数
int n = 0;//所求的第n个丑数
int humble[100001] = {0};//丑数集合
int prime[101] = {0};//集合中的质数
int position[101];
int min_mun;

int main()
{
    cin>>k>>n;
    humble[0] = 1;
    for(int i = 1; i<=k; i++){
        cin>>prime[i];
    }
    for(int i = 1; i<=n; i++){
        min_mun = 2147483647;//要求最小，初始值要极大
        for(int j = 1; j<=k; j++){//暴搜集合中质数
            while(prime[j]*humble[position[j]]<=humble[i-1]){
                position[j]++;
            }
            min_mun = min(min_mun, prime[j]*humble[position[j]]);
        }
        humble[i] = min_mun;
    }
    cout<<humble[n]<<endl;

}