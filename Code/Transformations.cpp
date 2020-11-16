//transformations
#include<bits/stdc++.h>

using namespace std;

int n = 0;
char a[15][15],b[15][15],c[15][15],d[15][15];

//判断两个b、c图像（矩阵）是否相等
int equal(){
    int flag = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(b[i][j] == c[i][j]){
                flag = flag*1;
            }else{
                flag = flag*0;
            }
        }
    }
    return flag;//相等返回1，不等返回0
}

//1.顺时针90度
int f1(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            b[j][n-i+1] = a[i][j];
        }
    }
    int flag = equal();
    return flag;
}

//2.顺时针180度
int f2(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            b[n-i+1][n-j+1] = a[i][j];
        }
    }
    int flag = equal();
    return flag;
}

//3.顺时针270度
int f3(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            b[n-j+1][i] = a[i][j];
        }
    }
    int flag = equal();
    return flag;
}

//4.反射
int f4(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            b[i][n-j+1] = a[i][j];
        }
    }
    int flag = equal();
    return flag;
}

//5.组合
int f5(){
    f4();
    int flag = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            a[i][j]=b[i][j];//重置矩阵;
        }
    }
    if(f1()){flag = 1;}
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            a[i][j]=b[i][j];//重置矩阵;
        }
    }
    if(f2()){flag = 1;}
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            a[i][j]=b[i][j];//重置矩阵;
        }
    }
    if(f3()){flag = 1;}
    
    return flag;
}


//6.不改变
int f6(){
    int flag = equal();
    return flag;
}

// //function
// void func(){
//     if(f1()){
//         cout<<1;
//         return;
//     }
//     if(f2()){
//         cout<<2;
//         return;
//     }
//     if(f3()){
//         cout<<3;
//         return;
//     }
//     if(f4()){
//         cout<<4;
//         return;
//     }
//     if(f5()){
//         cout<<5;
//         return;
//     }
//     if(f6()){
//         cout<<6;
//         return;
//     }
//     cout<<7;
// }


int main()
{
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
            d[i][j]=a[i][j];
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>c[i][j];
        }
    }
    //func();
    if(f1()){
        cout<<1;
    }else if(f2()){
        cout<<2;
    }else if(f3()){
        cout<<3;
    }else if(f4()){
        cout<<4;
    }else if(f5()){
        cout<<5;
    }else if(f6()){
        cout<<6;
    }else{
        cout<<7;
    }

}