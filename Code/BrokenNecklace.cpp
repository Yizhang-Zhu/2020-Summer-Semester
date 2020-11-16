// //broken necklace
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    cin>>n;
    string necklace = "";
    cin>>necklace;
    int rr[1000], rb[1000], lr[1000], lb[1000];
    //rr:right red lb:left blue
    //把链倍长
    string s = necklace + necklace;
    //初始化
    for(int i = 1; i<=2*n; ++i){
        lb[i] = 0;
        lr[i] = 0;
        rr[i] = 0;
        rb[i] = 0;
    }
    //从左往右 leftred/leftblue
    for(int i = 1; i<2*n; ++i){
        if(s[i] == 'w'){
            lr[i] = lr[i-1]+1;
            lb[i] = lb[i-1]+1;
        }else if(s[i] == 'r'){
            lr[i] = lr[i-1]+1;
        }else if(s[i] == 'b'){
            lb[i] = lb[i-1]+1;
        }
    }
    //从右往左 rightred/rightblue
    for(int j = 2*n; j>=1; --j){
        if(s[j] == 'w'){
            rr[j] = rr[j+1]+1;
            rb[j] = rb[j+1]+1;
        }else if(s[j] == 'r'){
            rr[j] = rr[j+1]+1;
        }else if(s[j] == 'b'){
            rb[j] = rb[j+1]+1;
        }
    }
    int num = 0;
    for(int k = 2*n-1; k>=1; --k){
        num = max(num, max(lr[k], lb[k])+max(rr[k+1], rb[k+1]));
    }
    if(num>n){  //不能大于原长，这里不写会部分错误
        num = n;
    }
    cout<<num<<endl;

}


//自己按照题解写的，段错误
// #include<bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n = 0;
//     cin>>n;
//     string necklace = "";
//     cin>>necklace;
//     int bleft[n], rleft[n], bright[n], rright[n];//b:blue, r:red + left: from right to left, right: from left to right
//     bleft[n] = rleft[n] = bright[n] = rright[n] = {0};
//     //from left to right
//     for(int i = 1; i<=n; i++){
//         if(necklace[i] == 'w'){
//             bright[i-1]++;
//             rright[i-1]++;
//         }else if(necklace[i] == 'r'){
//             bright[i-1] = 0;
//             rright[i-1]++;
//         }else if(necklace[i] == 'r'){
//             bright[i-1]++;
//             rright[i-1] = 0;
//         }
//     }
//     //from right to left
//     for(int j = n-1; j>=0; j++){
//         if(necklace[j] == 'w'){
//             bleft[j+1]++;
//             rleft[j+1]++;
//         }else if(necklace[j] == 'r'){
//             bleft[j+1] = 0;
//             rleft[j+1]++;
//         }else if(necklace[j] == 'b'){
//             bleft[j+1]++;
//             rleft[j+1] = 0;
//         }
//     }
//     //max
//     int left[n] = {0};
//     int right[n] = {0};
//     for(int k = 0; k<n; k++){
//         if(bright[k]>=rright[k]) right[k] = bright[k];
//         else right[k] = rright[k];
//         if(bleft[k+1]>=rleft[k+1]) left[k+1] = bleft[k+1];
//         else left[k+1] = rleft[k+1];
//     }
//     int ans[n] = {0};
//     for(int t = 0; t<n; t++){
//         ans[t] = right[t]+left[t];
//     }
//     int max = 0;
//     max = *max_element(ans,ans+n);
//     cout<<max<<endl;



// }



//洛谷
// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// #include<map>
// #include<vector>
// #include<cstring>
// #include<cmath>
// using namespace std;
// int n,rR[400*2],rB[400*2],lR[400*2],lB[400*2],ans;
// //char c[400*2];
// string s="";
// //int fastRead()
// // {
// // 	int f=1,r=0;char c=getchar();
// // 	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
// // 	while(c>='0'&&c<='9'){r=r*10+c-'0';c=getchar();}
// // 	return f*r;
// // }
// int main()
// {
// 	// n=fastRead();
// 	// scanf("%s",c+1);
//     int n=0;
//     cin>>n;
//     cin>>s;
//     string c = s+s;
// 	// for(int i=1;i<=n;++i)
// 	// c[i+n]=c[i];
//     lB[0]=0;
//     lR[0]=0;
// 	for(int i=1;i<=n*2;++i)
// 	{
// 		if(c[i]=='w')
// 		{
// 			lR[i]=lR[i-1]+1;
// 			lB[i]=lB[i-1]+1;
// 		}
// 		else if(c[i]=='r')
// 		{
// 			lR[i]=lR[i-1]+1;
// 		}
// 		else if(c[i]=='b')lB[i]=lB[i-1]+1;
// 	}
// 	for(int i=n*2;i>=1;--i)
// 	{
// 		if(c[i]=='w')
// 		{
// 			rR[i]=rR[i+1]+1;
// 			rB[i]=rB[i+1]+1;
// 		}
// 		else if(c[i]=='r')
// 		{
// 			rR[i]=rR[i+1]+1;
// 		}
// 		else if(c[i]=='b')rB[i]=rB[i+1]+1;	
// 	}
// 	for(int i=(n<<1)-1;i>=1;--i)
//     ans=max(ans,max(lR[i],lB[i])+max(rR[i+1],rB[i+1]));
//     if(ans>n)ans=n;
//     printf("%d",ans);
//     // cout<<endl;

//     // for(int i =0; i<100; i++){
//     //     cout<<c[i];
//     // }
//     return 0;
// }