//greedy gift giver
#include<bits/stdc++.h>

using namespace std;

map<string, int> dic;//定义一个下标为字符串存整数的map,以名字为索引，记录钱的字典
string name[10000];//储存人名字的字符串数组
string giver;//当前送礼物的人-内层循环
string receiver;//当前收礼者-内层循环
int np = 0; //人数
int gift = 0;//礼物总金额
int num = 0;//送礼总人数

int main()
{
    cin>>np;
    getchar();
    for(int i = 0; i<np; i++){
        cin>>name[i];
    }
    for(int a = 0; a<np; a++){//外循环，np次 
        cin>>giver;
        cin>>gift>>num;
        dic[giver] -= gift;
        for(int j = 0; j<num; j++){//内层循环，根据num数的不同执行num次
            cin>>receiver;
            dic[receiver] += gift/num;//平分giver的gift
        }
        if(num != 0){
            dic[giver] += gift%num;//剩下的钱归还给giver
        }
    }
    for(int k = 0; k<np; k++){//输出
        cout<<name[k]<<" "<<dic[name[k]]<<endl;
    }
}