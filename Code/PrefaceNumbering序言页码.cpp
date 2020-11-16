#include<bits/stdc++.h>

using namespace std;

int letter_cnt[10];

void transform(int x)
{
    int t=0;
    while(x){
        t++;
        int position = x%10;
        if(position == 9){
            letter_cnt[t+4]++;
            letter_cnt[t+3]++;    
        }else{
            if(position >= 5){
                letter_cnt[t]++;
                position -= 5;
            }
            if(position == 4){
                letter_cnt[t]++;
                letter_cnt[t+3]++;
            }else{
                letter_cnt[t+3] += position;
            }
        }
        x /= 10;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        transform(i);
    }
    if(letter_cnt[4] != 0)cout<<'I'<<" "<<letter_cnt[4]<<endl;
    if(letter_cnt[1] != 0)cout<<'V'<<" "<<letter_cnt[1]<<endl;
    if(letter_cnt[5] != 0)cout<<'X'<<" "<<letter_cnt[5]<<endl;
    if(letter_cnt[2] != 0)cout<<'L'<<" "<<letter_cnt[2]<<endl;
    if(letter_cnt[6] != 0)cout<<'C'<<" "<<letter_cnt[6]<<endl;
    if(letter_cnt[3] != 0)cout<<'D'<<" "<<letter_cnt[3]<<endl;
    if(letter_cnt[7] != 0)cout<<'M'<<" "<<letter_cnt[7]<<endl;
}


//参考（copy）
// #include<iostream>
// #include<cstdio>
// #include<cstring>
// using namespace std;
// int cnt[10];
// inline void doit(int x)
// {
//     int t=0;
//     while(x)
//     {
//         t++;
//         int tmp=x%10;
//         if(tmp==9)
//         {
//             cnt[t+4]++;
//             cnt[t+3]++;    
//         }else
//         {
//         if(tmp>=5)
//         {
//             cnt[t]++;
//             tmp-=5;
//         }
//         if(tmp==4)    
//         {
//             cnt[t]++;
//             cnt[t+3]++;
//         }else
//         cnt[t+3]+=tmp;
//         }
//         x/=10;
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         doit(i);
//     if(cnt[4])    printf("I %d\n",cnt[4]);
//     if(cnt[1])    printf("V %d\n",cnt[1]);
//     if(cnt[5])    printf("X %d\n",cnt[5]);
//     if(cnt[2])    printf("L %d\n",cnt[2]);
//     if(cnt[6])    printf("C %d\n",cnt[6]);
//     if(cnt[3])    printf("D %d\n",cnt[3]);
//     if(cnt[7])    printf("M %d\n",cnt[7]);
// }

