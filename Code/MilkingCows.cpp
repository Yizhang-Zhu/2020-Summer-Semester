//milking cows
#include<bits/stdc++.h>

using namespace std;

int main()
{
    bool time[1000001] = {false};//利用布尔数组暴力搜索，初始为flase
    int n = 0;
    cin>>n;
    int start = 1000001;
    int end = 0;
    for(int i = 0; i<n; i++){
        int a = 0;
        int b = 0;
        cin>>a>>b;
        start = min(start, a);//第一个农民开始的时间
        end = max(end, b);//最后一个农民结束的时间
        for(int j = a; j<b; j++){
            time[j] = true;//有农民在给奶牛挤奶，则布尔数组对应项改为true
        }
    }
    int somebody = 0;//最长至少有一人在挤奶的时间段
    int nobody = 0;//最长的无人挤奶的时间段
    int result1 = 0;//第一问结果
    int result2 = 0;//第二问结果
    for(int j = start; j<end; j++){
        if(time[j] == true){
            somebody++;//有人
            if(somebody>=result1){
                result1 = somebody;
            }
            nobody = 0;//有人，无人区间清零
        }else{
            somebody = 0;//无人，有人区间清零
            nobody++;//无人
            if(nobody>=result2){
                result2 = nobody;
            }
        }

    }
    cout<<result1<<" "<<result2<<endl;

}