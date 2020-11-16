//回文质数
#include<bits/stdc++.h>

using namespace std;

//判断位数:除了11之外，偶数位的回文数一定不是质数，可排除
bool len(int x){
	if((1000<=x && x<=9999) || (100000<=x && x<=999999)){
        return 0;
    } 
	return 1;
} 

//判断质数
bool prime(int x){
    for(int i = 2; i<=sqrt(x); i++){
        if(x%i == 0){
            return 0;
        }
    }
    return 1;
}

//判断回文
bool pal(int x){
    //too slow???
//     char s[10];
//     //数字转化为字符串，方便之后回文的判断
//     sprintf(s, "%d", x);
//     int len = 0;
//     len = strlen(s);
//     for(int i = 0; i<len; i++){
//         if(s[i] != s[len-1-i]){
//             return 0;
//         }
//     }
//     return 1;
   	int num[20];
    int cnt = 1;
    //把各位数字存在数组num[]中，方便之后判断回文
	while(x>0){
		num[cnt] = x%10;
		x /= 10;
		cnt++;
	} 
    //判断回文
	for(int i = 1; i<=cnt/2; i++){
        if(num[i] != num[cnt-i]){
            return 0;
        }
    }
	return 1;
}



int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    //除了2，偶数不可能是质数
    if(a%2 == 0){
        a++;
    }else{
        //a不动
    }
    //一千万到一亿之间没有质数
    b = min(b, 10000001)
    for(int i = a; i<=b; i++){
        if(!len(i)){continue;}
        if(!pal(i)){continue;}
        if(!prime(i)){continue;}
        printf("%d\n", i);
    }
}