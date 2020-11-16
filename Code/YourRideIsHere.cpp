//your ride is here
#include<bits/stdc++.h>

using namespace std;

bool judge(string a, string b){
    int len1 = a.size();
    int len2 = b.size();
    int sum1 = 1;
    int sum2 = 1;
    bool flag = 0;
    for(int i = 0; i < len1; i++) sum1 *= ((int)a[i]-64);
    for(int j = 0; j < len2; j++) sum2 *= ((int)b[j]-64);
    if(sum1%47 == sum2%47) flag = 1;
    else flag = 0;

    return flag;
}

int main()
{
    string group;
    string ufo;
    getline(cin, group);
    getline(cin, ufo);
    //cout<<group<<" "<<ufo<<endl;  test the input 
    int p = judge(group, ufo);
    if(p == 1) cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;


}