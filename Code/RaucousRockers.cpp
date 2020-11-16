//Raucous Rockers
#include<bits/stdc++.h>

using namespace std;

int n = 0;//n首歌曲
int t = 0;//一张cd可以存放t分钟的歌曲
int m = 0;//有m张cd
int song_t[25] = {0};//记录每首歌的长度
int dp[25][25];//动态规划表
int maxamount = 0;//装入的最大歌曲数量

int main()
{
    cin>>n>>t>>m;
    for(int i = 1; i<=n; i++){
        cin>>song_t[i];
    }
    for(int  i = 1; i<=n; i++){
        for(int j = m; j>=1; j--){
            for(int k = t; k>=song_t[i]; k--){
                dp[j][k] = max(
                    dp[j][k],//不动
                    max(dp[j-1][t]+1,//多增加一张cd
                    dp[j][k-song_t[i]]+1)//不增加cd
                    );
            }
        }
    }
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=t; j++){
            maxamount = max(maxamount, dp[i][j]);
        }
    }
    cout<<maxamount<<endl;

    
}