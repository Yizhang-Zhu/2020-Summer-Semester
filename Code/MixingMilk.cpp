//mixing milk
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;//商人一天需要的牛奶量
    int m = 0;//农民数量
    cin>>n>>m;
    int pi[5001] = {0};//农民 i 牛奶的价格
    int ai[5001] = {0};//农民 i 一天能卖给商人的牛奶数量
    int cost = 0;//商人买牛奶的开销
    for(int i = 1; i<=m; i++){
        cin>>pi[i]>>ai[i];
    }
    //冒泡排序，之后贪心算法.
    //价格升序，优先卖便宜的牛奶
    for(int j = 1; j<=m; j++){
        for(int r = m; r>=j; r--){
            if(pi[r]<pi[r-1]){
                swap(pi[r], pi[r-1]);
                swap(ai[r], ai[r-1]);
            }
        }
    }
    //贪心算法
    for(int k = 1; n>0; k++){
        if(n>=ai[k]){
            //这个农民提供的牛奶不够剩余需求的情况
            cost += pi[k]*ai[k];
            n -= ai[k]; //取得了ai[k]的牛奶量，还需要的量减少
        }else{
            //如果某农民提供的量大于余下的需求量，那只要一部分
            cost += pi[k]*n;
            n = 0;
        }
    }
    cout<<cost<<endl;
}