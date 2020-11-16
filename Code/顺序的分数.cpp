//顺序的分数

//普通数组法
#include<bits/stdc++.h>

using namespace std;

//既约分数，分子分母互质。判断互质。
bool judge(int m,int n){
    int temp;
    while(m%n>0){
        temp=n;
        n=m%n;
        m=temp;
    }
    if(n == 1){
        return 1;
    }else{
        return 0;
    }
} 

int main(){
    int n = 0;//输入的数字
    cin>>n;
    int index = 0; //记录下标,最后经过自增的结果是最大下标
    int x[10000] = {0};//记录分子的数组
    int y[10000] = {0};//记录分母的数组
    double f[10000] = {0.00};//记录分数的实际数值
    //i是分子，j是分母
    for(int i = 0; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(judge(i, j) && i<=j){
                index++;//index=0的位置不记录，从index=1开始
                x[index] = i;
                y[index] = j;
                double z = 1.00*i/j;
                f[index] = z;
            }
        }
    }
    //冒泡排序，升序
    for(int i = 1; i<=index; i++){
        for(int j = i+1; j<=index; j++){
            if(f[i]>f[j]){
                swap(f[i], f[j]);
                //f中的分数实际数值排序，则x、y中的分子分母也要排成对应的顺序
                swap(x[i], x[j]);
                swap(y[i], y[j]);
            }
        }
    }
    for(int i = 1; i<=index; i++){
        cout<<x[i]<<'/'<<y[i]<<endl;
    }
}


//map法--有问题---------------------------------------------------------------------------------------------------------
// #include<bits/stdc++.h>

// using namespace std;

// map<double, string, less<double>> fra;//以分数实际大小排序，升序
// double f[1000] = {0};
// string s[1000] = {" "};

// //既约分数，分子分母互质。判断互质。
// bool judge(int m,int n){
//     int temp;
//     while(m%n>0){
//         temp=n;
//         n=m%n;
//         m=temp;
//     }
//     if(n == 1){
//         return 1;
//     }else{
//         return 0;
//     }
// } 

// int main()
// {
//     int n = 0;
//     cin>>n;
//     cout<<"0/1"<<endl;
//     char c[3] = {'0','/','0'};
//     int cnt = 0;
//     for(int i = 1; i<=n; i++){
//         for(int j = i+1; j<=n; j++){
//             if(judge(i, j)){
//                 c[0] = i-'0';
//                 c[1] = '/';
//                 c[2] = j-'0';
//                 s[cnt] = c;
//                 //mapStudent.insert(pair<int, string>(3, "student_three"));
//                 double f[cnt] {i/j*1.0} ;//分数的大小
//                 fra.insert(pair<double, string>(f[cnt], s[cnt]));
//                 cnt++;
//             }
//         }
//     }
//     // for(map<double, string>::iterator it = fra.begin(); it != fra.end(); it++){
//     //     cout<<it->second<<endl;
//     // }
    
//     for(int i = 1; i<cnt; i++){
//         cout<<fra[f[i]]<<endl;
//     }
//     cout<<"1/1"<<endl;

// }


// // void test01(){
// //             map<string,int,less<string> > map1;
// //             map1.insert(pair<string,int>("aba",3));
// //             map1.insert(pair<string,int>("aaa",2));
// //             map1.insert(pair<string,int>("ddd",1));
// //             map1.insert(pair<string,int>("ccc",4));
        
// //             for(map<string,int>::iterator it=map1.begin(); it!=map1.end(); it++ ){
// //                 cout<<(*it).first<<" : "<<(*it).second<<endl;
// //             }
// // }


