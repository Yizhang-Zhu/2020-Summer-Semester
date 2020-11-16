//Stamps 邮票
#include<bits/stdc++.h>

using namespace std;

int k = 0, n = 0;//k:邮票总数, n:面额数量
int up = 0;//所求上限
int s[51] = {0};//面额,最多50种
int stamp[2000001];//stamp[i]表示构成面值i所需邮票数量

int main()
{
    cin>>k>>n;
    //初始化
    for(int i = 0; i<=50; i++){
        s[i] = 0;//面值初始化
    }
    for(int i = 1; i<=2000000; i++){
        stamp[i] = 123456789;//之后要取小值，初始要很大
    }
    stamp[0] = 0;
    //读取各种面额数据到s[]
    for(int i = 1; i<=n; i++){
        cin>>s[i];
    }
    //DP dp[i]=min(dp[i],dp[i-value[i]]+cost[i]) cost为1
    for(int i = 1; i<=n; i++){
        for(int j = s[i]; j<=2000000; j++){
            if(stamp[j-s[i]]+1<=k){
                stamp[j] = min(stamp[j], stamp[j-s[i]]+1);
            }
        }
    }
    for(int i = 1; i<=2000000; i++){
        if(stamp[i] == 123456789){
            up = i-1;
            break;
        }
    }
    cout<<up<<endl;
    return 0;
}