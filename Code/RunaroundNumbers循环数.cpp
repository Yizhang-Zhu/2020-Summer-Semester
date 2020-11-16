//Runaround Numbers循环数
#include<bits/stdc++.h>

using namespace std;

int n = 0;//输入的数字
int len = 0;//数字的长度
int num[10] = {0};//存放各位上的数字
int reverse_num[10] = {0};//逆序的各位上的数字
int path[10] = {0};//记录走过的位置，“足迹”

//把一个大数字的各位数字存入数组中
int transform(int x)
{
    int cnt = 0;//计数器，最后相当于数字的长度
    while(x>0){
        reverse_num[++cnt] = x%10;//此时存入的是逆序的
        x /= 10;
    }
    //把逆序的转化成原来的数字顺序
    for(int i = 1; i<=cnt; i++){
        num[i] = reverse_num[cnt-i+1];
    }
    return cnt;//返回长度
}

//判断num[]是否循环
bool loopnum()
{
    memset(path, 0, sizeof(path));//初始化
    int p = 1;//指向数组元素,p = 1为开始的位置
    for(int i = 1; i<=len; i++){
        if(num[p] == 0){//循环数不可能出现0，出现0就不动了，不和题意
            return 0;
        }
        if(path[num[p]] != 0){//走过的位置重复了，不符合题意
            return 0;
        }
        path[num[p]]++;//如果走到了之前没走过的位置，标记
        p = (p+num[p])%len;//移到下一个位置
        if(p == 0){
            p = len;
        }
    }
    if(p != 1){
        return 0;//没回到原来的位置，不合题意
    }
    return 1;
}


int main()
{
    cin>>n;//1-9位数
    for(int i = n+1; ; i++){
        len = transform(i);
        if(loopnum()){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}