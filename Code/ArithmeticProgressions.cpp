//Arithmetic Progressions 等差数列
//a, a+b, a+2b,..., a+nb (n=0,1,2,3,...) 首项a，公差b
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;//N(3<= N<=25),要找的等差数列的长度
    int m = 0;//M(1<= M<=250),搜索双平方数的上界 0 <= p,q <= M.
    int k = 0;//当前（正在搜索）的等差数列长度
    cin>>n;
    cin>>m;
    bool exist = false;
    int ds[125001] = {0};//双重平方数double square 
    int index = 0;//下标
    bool in[125001] = {false};//记录哪些位置是双重平方数
    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=m; j++){
            in[i*i+j*j] = true;
        }
    }
    for(int i = 0; i<=sizeof(in); i++){
        if(in[i] == true){
            ds[++index] = i;
        }
    }
    for(int b = 1; b<ds[index]; b++){
        for(int i = 1; i<index-1; i++){
            if(ds[i] + (n-1)*b > ds[index]) break;
            for(k = 2; k<=n; k++){
                if(!in[ds[i]+(k-1)*b]){
                    break;
                }
            }
            if(k == n+1 && in[ds[i]+(n-1)*b]){
                cout<<ds[i]<<" "<<b<<endl;
                exist = true;//存在
            }
        }
    }
    if(exist == false){//不存在
        cout<<"NONE"<<endl;
    }

}