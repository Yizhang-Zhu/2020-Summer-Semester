//friday the thirteenth
//in: 20
//out: 36 33 34 33 35 35 34
//1900 年 1 月 1 日到 1900+n-1 年 12 月 31 日
#include<bits/stdc++.h>

using namespace std;

//判断某一年是闰年还是平年
bool leapyear(int x){
    bool flag = 0;
    if((x%400 == 0 && x%100 == 0) || (x%4 == 0 && x%100 != 0)){
        flag = 1;
    }else{
        flag = 0;
    }
    return flag;//闰年返回1，平年返回0
}

int main()
{
    int n = 0;
    cin>>n;
    int date[8] = {0,0,0,0,0,0,0,0};
    int sum = 1;
    sum += 12;
    date[sum%7]++;
    //int month[12];
    for(int i = 1900; i<1900+n; i++){
        int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(leapyear(i) == 1){
            //int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};//闰年
            month[1] = 29;
        }else if(leapyear(i) == 0){
            //int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//平年
        }
        if(i < 1900+n-1){
            for(int j = 0; j<12; j++){
                sum += month[j];
                date[sum%7]++;
            }
        }else{
            for(int k = 0; k<11; k++){
                sum += month[k];
                date[sum%7]++;
            }
        }

    }
    cout<<date[6]<<" "<<date[0]<<" "<<date[1]<<" "<<date[2]<<" "<<date[3]<<" "<<date[4]<<" "<<date[5]<<endl;

}