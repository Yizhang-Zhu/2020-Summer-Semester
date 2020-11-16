//Prime Cryptarithm 牛式 
#include<bits/stdc++.h>

using namespace std;


int num[10] = {0};//用数组储存输入的数字
bool in[10] = {0};//记录对应位置是否有集合内数字的bool数组


//某个3/4位数的各位上的数字都由集合内的元素构成
//3位数
bool judge3(int x){
    bool flag = 0;
    int a = x%10; //个位数
    int b = x/10%10;//十位数
    int c = x/100;//百位数
    if(in[a] && in[b] && in[c]){
        flag = 1;
    }
    return flag;
}
//4位数
bool judge4(int x){
    bool flag = 0;
    int a = x%10; //个位数
    int b = x/10%10;//十位数
    int c = x/100%10;//百位数
    int d = x/1000;//千位数
    if(in[a] && in[b] && in[c] && in[d]){
        flag = 1;
    }
    return flag;
}

int main()
{
    int n = 0;//数字的个数
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>num[i];
        in[num[i]] = true;
    }
    int cnt = 0;//计数器counter
    for(int a = 1; a<=n; a++){
        for(int b = 1; b<=n; b++){
            for(int c = 1; c<=n; c++){
                for(int d = 1; d<=n; d++){
                    for(int e = 1; e<=n; e++){
                        int A = 100*num[a]+10*num[b]+num[c];
                        int B = 10*num[d]+num[e];
                        if(A*num[e]>=100 && A*num[e]<=999 && A*num[d]>=100 && A*num[d]>=100 && A*B>=1000 && A*B<=9999 && judge3(A*num[e]) && judge3(A*num[d]) && judge4(A*B)){
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;

}