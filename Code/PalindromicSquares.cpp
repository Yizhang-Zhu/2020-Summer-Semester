//Palindromic Squares 回文平方数
//给定一个进制 B(2<=B<=20 十进制),输出所有的大于等于1，小于等于 300 且它的平方用 B 进制表示时是回文数的数.
#include<bits/stdc++.h>

using namespace std;

int b; //输入的b进制
int num[500];//记录mod b之后的余数。注意！！num中倒序输出才是想要的结果

void baseTransform(int a, int b){//进制转换，把a转化成b进制
    int t = 0;
    while(a != 0){
        num[++t] = a%b;
        a = a/b;
    }
    num[0] = t;//首位记录长度

}

bool judge(){//判断是否回文
    //回文的充要条件：num[x] = num[num[0]+1-x]
    bool flag = 1;
    for(int i = 1; i<=num[0]; i++){
        if(num[i] != num[num[0]+1-i]){
            flag = 0;
        }
    }
    return flag;
}

int main()
{
    cin>>b;
    //暴力搜索大于等于1小于等于300的数
    for(int j = 1; j<=300; j++){
        baseTransform(j*j, b);
        if(judge()){
            baseTransform(j, b);
            for(int k = num[0]; k>=1; k--){//倒序输出num数组
                if(num[k] <= 9){
                    cout<<num[k];
                }else{
                    cout<<(char)(num[k]+'A'-10);
                }
            }
            cout<<' ';//间隔空格
            baseTransform(j*j, b);
            for(int k = num[0]; k>=1; k--){//倒序输出num数组
                if(num[k] <= 9){
                    cout<<num[k];
                }else{
                    cout<<(char)(num[k]+'A'-10);
                }
            }
            cout<<"\n";
        }
    }

    
}