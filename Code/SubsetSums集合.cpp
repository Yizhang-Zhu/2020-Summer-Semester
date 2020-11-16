//Subset Sums集合
#include<bits/stdc++.h>

using namespace std;

int n = 0;
int half = 0;
int dp[1000000] = {0};

//集合内元素累加
int sum(int x)
{
    return ((x+1)*x/2);
}

int main()
{
    cin>>n;
    if(sum(n)%2 != 0){
        cout<<0<<endl;
        return 0;
    }
    half = sum(n)/2;//半数和，即切割后子集合的元素之和
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = half; j>=i; j--){
            dp[j] += dp[j-i];
        }
    }
    cout<<dp[half]/2<<endl;

}