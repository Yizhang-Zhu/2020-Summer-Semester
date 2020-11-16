//feed ratios -- 非齐次线性方程组，克莱姆法则
#include<bits/stdc++.h>

using namespace std;

int cnt = 0;//计数器
int p = 0, q = 0, r = 0;//目标比例
int a, b, c, d, e, f, g, h, i;//输入的买进饲料的信息
double x, y, z;//所求各买进配料的混合比
double xc, yc, zc;//a copy of xyz

int A, Dx, Dy, Dz;//克莱姆法则的矩阵

//非齐次线性方程组构造行列式
void det()
{
    A = a*e*i+d*h*c+b*f*g-c*e*g-b*d*i-a*h*f;
    Dx = p*e*i+d*h*r+g*q*f-r*e*g-d*q*i-p*h*f;
    Dy = a*q*i+p*h*c+g*b*r-g*q*c-p*b*i-a*h*r;
    Dz = a*e*r+d*q*c+p*b*f-p*e*c-d*b*r-a*q*f; 
    return;
}

//克莱姆法则解非齐次线性方程组
void Cramer()
{
	xc = (double)Dx/A;
	yc = (double)Dy/A;
	zc = (double)Dz/A;
    x = xc;
    y = yc;
    z = zc;
}

int main()
{
    //数据读入
    cin>>p>>q>>r;
    cin>>a>>b>>c;
    cin>>d>>e>>f;
    cin>>g>>h>>i;
    det();//生成矩阵
    if(A == 0 || A == -0){
        cout<<"NONE";
    }else{
        Cramer();//克莱姆法则解方程
        if(x<0 || y<0 || z<0){
            cout<<"NONE";
            return 0;
        }
        cnt = 1;
        while(x-floor(x) != 0 || y-floor(y) != 0 || z-floor(z) != 0){
            cnt++;
            x = xc*cnt;
            y = yc*cnt;
            z = zc*cnt;
        }
        //以下：不然会输出 -0
		if(x == -0) x = 0;
		if(y == -0) y = 0;
		if(z == -0) z = 0;
        cout<<x<<" "<<y<<" "<<z<<" "<<cnt;
    }
    return 0;


}