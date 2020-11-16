#include<bits/stdc++.h>

using namespace std;

class Apple{
public:
    int place;
    string id;
    int weight;
    int diameter;
    Apple(int place = 0, string id = "N/A", int weight = 0, int diameter = 0){//构造函数
        this->place = place;
        this->id = id;
        this->weight = weight;
        this->diameter = diameter;
    }
    ~Apple(){}//析构函数
};

int main()
{
    int n = 0;
    cin>>n;
    int p, w, d;
    string no;
    int max_w = 0;//最大重量
    int max_p = 0;//最大篮筐编号
    int index = -1;//记录a[]中符合条件的苹果的索引
    Apple a[n];//存放苹果的数组
    for(int i = 0; i<n; i++){
        cin>>p>>no>>w>>d;
        max_p = max(max_p, p);
        //if(p>max_p) max_p = p;
        Apple x(p, no, w, d);
        a[i] = x;
    }
    for(int i = 0; i<=max_p; i++){
        max_w = 0;
        bool flag = false;
        for(int j = 0; j<n; j++){//遍历篮筐
            if(a[j].place == i){
                flag = true;
                //max_w = max(max_w, a[j].weight);
                if(a[j].weight>max_w){max_w = a[j].weight; index = j;}
                //index = j;

            }
        }
        if(flag == true){
            cout<<a[index].place<<" "<<a[index].id<<" "<<a[index].weight<<" "<<a[index].diameter<<endl;
        }
    }
}


/*
7
1 N000001 175 77
2 N000002 180 83
2 N000003 160 66
1 N000004 160 63
1 N000005 165 68
4 N000006 183 85
2 N000007 170 74
*/