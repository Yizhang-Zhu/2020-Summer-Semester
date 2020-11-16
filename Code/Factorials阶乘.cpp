//Factorials 阶乘
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    int end = 0;
    cin>>n;
    int result = 1;
    for(int i = 1; i<=n; i++){
        result = result*i;
        while(result % 10 ==0){
            result /= 10; //去掉末尾的0
        }
        result %= 10000; //记录最后四位
    }
    end = result % 10;
    cout<<end<<endl;
}
