//Barn Repair 修理牛棚
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m = 0;//M(1<=M<=50),可能买到的木板最大的数目
    int s = 0;//S(1<=S<=200),牛棚的总数
    int c = 0;//;C(1<=C<=S),牛棚里牛的数目
    cin>>m>>s>>c;
    int stall[201] = {0};//记录有牛的棚的
    int gap[201] = {0};//记录间隔数的数组
    int gap_num = 0; //当前间隔数
    int board = 0;//所需木板最小长度
    bool cow[201] = {false};//布尔数组用来记录棚中是否有牛
    for(int i = 1; i<=c; i++){
        cin>>stall[i];
        cow[stall[i]] = true;
    }
    //给stall[]排序。冒泡排序。--这里如果不排序，测试点4.7.8会出错
    for(int i = 1; i<=c; i++){
        for(int j = 1; j<=c; j++){
            if(stall[j]<stall[j-1]){
                swap(stall[j], stall[j-1]);
            }
        }
    }
    //sort(stall+1, stall+c+1);
    for(int j = stall[1]; j<=stall[c]-1; j++){
        if(cow[j] == true && cow[j+1] == false){
            gap_num++;
        }else if(cow[j] == false){
            gap[gap_num]++;
        }
    }
    //给gap排序，冒泡排序。然后贪心算法。要想长度最短，就有优先选取短的gap加上board来连接。
    for(int i = 1; i<=gap_num; i++){
        for(int j = 1; j<=gap_num; j++){
            if(gap[j]<gap[j-1]){
                swap(gap[j], gap[j-1]);
            }
        }
    }
    //board初值：c，即每个有牛的棚子首先都要有一个
    board = c;
    //贪心算法
    for(int i = 1; i<=gap_num-m+1; i++){
        board += gap[i];
    }
    cout<<board<<endl;
    
    return 0;

}


// //洛谷参考

// #include<bits/stdc++.h>
// #define re register int
// using namespace std;
// int ans,a[201],b[201];
// int num,d[201],m,s,c;
// int main()
// {
//     scanf("%d%d%d",&m,&s,&c);
// 	for(re i=1;i<=c;i++)
// 	    scanf("%d",&a[i]),b[a[i]]=1;//桶排，有牛的牛棚号设为1 
// 	sort(a+1,a+c+1);                
// 	for(re i=a[1];i<=a[c]-1;i++)
// 	{
// 		if(b[i]==1&&b[i+1]==0)      //如果遇到一个有牛的牛棚下一个牛棚没有牛 
// 		num++;                      //间隔数+1 
// 		else if(b[i]==0)            //如果这个牛棚没有牛 
// 		d[num]++;                   //当前间隔下空牛棚数量+1 
// 	}
// 	sort(d+1,d+num+1);              //空牛棚数小的间隔优先搭建 
// 	for(re i=1;i<=num-m+1;i++)      // num-m+1表示需要搭建的间隔数 
// 	    ans+=d[i];
// 	cout<<ans+c<<endl;              //（输出时别忘了加上c QAQ）
// 	return 0;                      
// }
