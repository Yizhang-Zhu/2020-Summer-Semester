//Stringsobits 01串
/*
考虑排好序的 N(N<=31)位二进制数.
你会发现,这很有趣.因为他们是排列好的,而且包含所有可能的长度为 N 且含有 1 的个数小于等于L(L<=N)的数.
你的任务是输出第 I（1<=I<=长度为 N 的二进制数的个数）大的,长度为 N,且含有 1 的个数小于等于 L 的那个二进制数.

输入格式:
共一行,用空格分开的三个整数 N,L,I.

输出格式:
共一行,输出满足条件的第 I 大的二进制数.
*/
#include<bits/stdc++.h>

using namespace std;


//十进制转化为二进制
string trans(int x){
    char s1[1000];
    int cnt1 = 0;
    int num1[1000] = {0};
    while(x != 0){
        num1[++cnt1] = x%2;
        x /= 2;
    }
    //倒序输出
    for(int i = cnt1; i>=1; i--){
        s1[i] = num1[i]-'0';
    }
    return s1;

}

// //判断1的数量是否不超过i
// bool l_judge(string bi, int l){
//     int cnt = 0;
//     for(int a = 1; a<=500; a++){
//         if(bi[a] == '1') cnt++;
//     }
//     if(cnt<=l){
//         return 1;
//     }else{
//         return 0;
//     }
// }

bool l_judge(int x, int l){
    //转二进制
    int cnt = 0;
    int num[1000] ={0};
    char bi[1000] = {'0'};
    string s;
    while(x != 0){
        num[++cnt] = x%2;
        x /= 2;
    }
    //倒序输出为所需
    for(int r = cnt; r>=1; r--){
        for(int j = 1; j<=cnt; j++){
            bi[j] = num[r]-'0';
        }
    }
    s = bi;
    //判断s中的1的数量是否不超过l
    int t = 0;
    for(int r = 1; r<=1000; r++){
        if(s[r] == '1') t++;
    }
    if(t<=l){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    int n = 0;
    int i = 0;
    int l = 0;
    cin>>n>>l>>i;
    int max = 0;//上限
    int max_i = 0;//第i大
    int all[1000] = {0};//有效：1~n
    // for(int a = 1; a<=l; a++){
    //     num[i] = 1;
    // }
    for(int k = n-1; k>=n-l; k--){
        max += pow(2, k);
    }
    //cout<<max;
    // for(int k = 1; k<=n; k++){
    //     for(int m = 0; m<=max; m++){
    //         trans(m);
    //         if(l_judge(bi, l)){
    //             all[k] = m;
    //         }
    //     }
    // }
    for(int k = max, index = 1; k>=1, index<=n; k--, index++){
        if(l_judge(k, l)){
            all[index] = k;
        }
    }

    //max_i = max+1-i;
    //max_i=all[i];
    //cout<<all[max_i]<<endl;
    // for(int k = 0; k<=1000; k++){
    //     if(all[k]!=0){
    //         cout<<all[k]<<" ";
    //     }
    // }
    max_i = all[i];
    cout<<trans(max_i);
    //cout<<max<<" "<<max_i<<endl;

}