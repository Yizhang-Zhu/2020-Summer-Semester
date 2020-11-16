//Dual Palindromes双重回文数
#include<bits/stdc++.h>

using namespace std;



//int num[500] = {0};//记录mod b之后的余数。

// void baseTransform(int a, int b){//进制转换，把a转化成b进制
//     int t = 0;
//     while(a != 0){
//         num[++t] = a%b;
//         a = a/b;
//     }
//     num[0] = t;//首位记录有效长度
// }

bool pal(int a, int b){//判断是否回文
    int num[500] = {0};
    //进制转换
    int t = 0;
    while(a != 0){
        num[t++] = a%b;
        a = a/b;
    }
    //num[0] = t;//首位记录有效长度
    //判断回文
    //回文的充要条件：num[x] = num[num[0]+1-x]
    bool flag = 1;
    // for(int i = 1; i<=num[0]; i++){
    //     if(num[i] != num[num[0]+1-i]){
    //         flag = 0;
    //     }
    // }
    int i = 0;
    int j = t-1;
    while(i<j){
        if(num[i++] != num[j--]){
            flag = 0;
        }
    }
    //num[500] = {0};
    return flag;
}

// bool judge(int x){//判断是否满足题设：两个进制下回文
//     int palcnt = 0;
//     int flag = 0;
//     for(int i = 1; i<=10; i++){
//         //baseTransform(x, i);
//         if(pal(x, i)){
//             palcnt++;
//         }else{
//             //palcnt不变
//         }
//         if(palcnt >= 2){
//             flag = 1;
//             break;
//         }
//     }
//     return flag;
    
// }


int main()
{
    int n; //个数
    int low; //输入的下限
    cin>>n>>low;
    int outcnt = 0; //输出计数器
    for(int i = low+1; outcnt != n; i++){
        int palcnt = 0; //回文计数器
        for(int b = 2; b<=10 && palcnt<2; b++){//b是进制
            if(pal(i, b)){
                palcnt++;
            }
        }
        if(palcnt>=2){
            cout<<i<<endl;
            outcnt++;
        }
    }
    return 0;
}