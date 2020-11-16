//提交代码

//铺放砖块

#include<bits/stdc++.h>

using namespace std;

int rest[101];
int area = INT_MAX;

struct rectangle
{
    int x, y;
}brick[4], rec;

void Transform(int k)
{
    if(k == 4){

        //case 1
        rec.x = 0; rec.y = 0;
        for (int i = 0; i < 4; ++i)
        {
            rec.x += brick[i].x;
            if (brick[i].y > rec.y) rec.y = brick[i].y;
        }
        if(rec.x*rec.y < area){
            area = rec.x*rec.y;
            fill_n(rest+1, 100, 0);
        }
        if(rec.x*rec.y == area){
            rest[min(rec.x, rec.y)] = 1;
        }

        //case 2
        rec.x = 0; rec.y = 0;
        for (int i = 1; i < 4; ++i)
        {
            rec.x += brick[i].x;
            if (brick[i].y > rec.y) rec.y = brick[i].y;
        }
        if (brick[0].x > rec.x) rec.x = brick[0].x;
        rec.y += brick[0].y;
        if(rec.x*rec.y < area){
            area = rec.x*rec.y;
            fill_n(rest+1, 100, 0);
        }
        if(rec.x*rec.y == area){
            rest[min(rec.x, rec.y)] = 1;
        }

        //case 3
        rec.x = max(brick[0].x+brick[1].x, brick[2].x)+brick[3].x;
        rec.y = max(max(brick[0].y, brick[1].y)+brick[2].y, brick[3].y);
        if(rec.x*rec.y < area){
            area = rec.x*rec.y;
            fill_n(rest+1, 100, 0);
        }
        if(rec.x*rec.y == area){
            rest[min(rec.x, rec.y)] = 1;
        }

        //case 4, 5
        rec.x = brick[0].x+max(brick[1].x, brick[2].x)+brick[3].x;
        rec.y = max(max(brick[0].y, brick[1].y+brick[2].y), brick[3].y);
        if(rec.x*rec.y < area){
            area = rec.x*rec.y;
            fill_n(rest+1, 100, 0);
        }
        if(rec.x*rec.y == area){
            rest[min(rec.x, rec.y)] = 1;
        }

        //case 6
        rec.x = brick[0].x+brick[1].x;
        rec.y = max(brick[0].y+brick[2].y, brick[1].y+brick[3].y);
        if (brick[0].y < brick[1].y)
            rec.x = max(rec.x, brick[2].x+brick[1].x);
        if (brick[0].y+brick[2].y > brick[1].y)
            rec.x = max(rec.x, brick[2].x+brick[3].x);
        if (brick[1].y < brick[0].y)
            rec.x = max(rec.x, brick[0].x+brick[3].x);
        rec.x = max(rec.x, brick[2].x);
        rec.x = max(rec.x, brick[3].x);
        if(rec.x*rec.y < area){
            area = rec.x*rec.y;
            fill_n(rest+1, 100, 0);
        }
        if(rec.x*rec.y == area){
            rest[min(rec.x, rec.y)] = 1;
        }

    }else{
        Transform(k+1); 
        swap(brick[k].x, brick[k].y);
        Transform(k+1); 
        swap(brick[k].x, brick[k].y);
    }
}
 
void Restort(int k)
{
    if(k == 4){
        Transform(0);
    }else{
        for (int i = k; i < 4; ++i){
            swap(brick[k], brick[i]);
            Restort(k+1);
            swap(brick[k], brick[i]);
        }
    }
}
 
int main()
{
    for(int i = 0; i < 4; ++i){
        cin>>brick[i].x>>brick[i].y;
    }
    Restort(0);
    cout<<area<<endl;
    for(int i = 1; i <= 100; ++i){
        if (rest[i]){
            cout<<i<<" "<<area/i<<endl;
        }
    }
}











// //参考来源
 

// /*
// ID: MasterRay
// LANG: C++
// TASK: packrec
// */
 
// #include <algorithm>
// #include <climits>
// #include <cstdio>
// using namespace std;
 
// bool flag[10] = {};
// int res[101], res_area = INT_MAX;
// struct rectangle
// {
// 	int x, y;
// }a[4], rec;
 
// void Record()
// {
// 	if (rec.x*rec.y < res_area)
// 	{
// 		res_area = rec.x*rec.y;
// 		fill_n(res+1, 100, 0);
// 	}
// 	if (rec.x*rec.y == res_area)
// 		res[min(rec.x, rec.y)] = 1;
// }
 
// void Calc()
// {
// 	//case 1
// 	rec.x = 0; rec.y = 0;
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		rec.x += a[i].x;
// 		if (a[i].y > rec.y) rec.y = a[i].y;
// 	}
// 	Record();
// 	//case 2
// 	rec.x = 0; rec.y = 0;
// 	for (int i = 1; i < 4; ++i)
// 	{
// 		rec.x += a[i].x;
// 		if (a[i].y > rec.y) rec.y = a[i].y;
// 	}
// 	if (a[0].x > rec.x) rec.x = a[0].x;
// 	rec.y += a[0].y;
// 	Record();
// 	//case 3
// 	rec.x = max(a[0].x+a[1].x, a[2].x)+a[3].x;
// 	rec.y = max(max(a[0].y, a[1].y)+a[2].y, a[3].y);
// 	Record();
// 	//case 4, 5
// 	rec.x = a[0].x+max(a[1].x, a[2].x)+a[3].x;
// 	rec.y = max(max(a[0].y, a[1].y+a[2].y), a[3].y);
// 	Record();
// 	//case 6
// 	rec.x = a[0].x+a[1].x;
// 	rec.y = max(a[0].y+a[2].y, a[1].y+a[3].y);
// 	if (a[0].y < a[1].y)
// 		rec.x = max(rec.x, a[2].x+a[1].x);
// 	if (a[0].y+a[2].y > a[1].y)
// 		rec.x = max(rec.x, a[2].x+a[3].x);
// 	if (a[1].y < a[0].y)
// 		rec.x = max(rec.x, a[0].x+a[3].x);
// 	rec.x = max(rec.x, a[2].x);
// 	rec.x = max(rec.x, a[3].x);
// 	Record();
// }
 
// void Rotate(int k)
// {
// 	if (k == 4) Calc();
// 	else
// 	{
// 		Rotate(k+1); swap(a[k].x, a[k].y);
// 		Rotate(k+1); swap(a[k].x, a[k].y);
// 	}
// }
 
// void Permutate(int k)
// {
// 	if (k == 4) Rotate(0);
// 	else
// 	{
// 		for (int i = k; i < 4; ++i)
// 		{
// 			swap(a[k], a[i]);
// 			Permutate(k+1);
// 			swap(a[k], a[i]);
// 		}
// 	}
// }
 
// int main()
// {
// 	freopen("packrec.in", "r", stdin);
// 	freopen("packrec.out", "w", stdout);
// 	for (int i = 0; i < 4; ++i)
// 		scanf("%d%d", &a[i].x, &a[i].y);
// 	Permutate(0);
// 	printf("%d\n", res_area);
// 	for (int i = 1; i <= 100; ++i)
//         if (res[i])
//             printf("%d %d\n", i, res_area/i);
// }

// ————————————————
// 版权声明：本文为CSDN博主「蓝亦」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/finded/article/details/22481911