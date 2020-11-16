//a game
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;//正整数的个数
    int sum[101] = {0};//记录和，即总分
    int num[101] = {0};//存放各个正整数
    int dp[101][101] = {0};//动态规划表，dp[i][j]表示取i~j这个区间某玩家最高得分
    int player1_score = 0;//玩家1的得分
    int player2_score = 0;//玩家2的得分

    cin>>n;//输入的正整数个数
    for(int i = 1; i<=n; i++){
        cin>>num[i];
        sum[i] = sum[i-1]+num[i];
        dp[i][i] = num[i];//初始化
    }
    for(int i = n-1; i>=1; i--){
        for(int j = i+1; j<=n; j++){
            dp[i][j] = max((sum[j]-sum[i-1])-dp[i][j-1], 
            (sum[j]-sum[i-1])-dp[i+1][j]);
        }
    }
    player1_score = dp[1][n];
    player2_score = sum[n]-player1_score;//玩家2的得分就是总分-玩家1得分
    cout<<player1_score<<" "<<player2_score<<endl;

}