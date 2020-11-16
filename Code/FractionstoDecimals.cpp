//Fractions to Decimals
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n = 0;//分子 
	int d = 0;//分母 
	int t = 0;//小数点前 
	int r = 0;//余数（暂存） 
	int right = 0;//右括号的位置 
	int left = 0;//左括号的位置 
	//int x = 0;//小数的某一位（暂存） 
	int k = 0;//小数部分的位数 
	int cnt = 0;//记录位数，题目要求超过79位要换行输出 
	int decimal[100005] = {0};//decimal[i]代表除下来结果小数部分第i位（从0开始）
	//如果余数出现重复，说明出现循环项 
	map<int, int> remainder;//记录之前出现过的余数 
	int start = 0;//小数循环部分开始位置
	int temp = 0;//小数循环当前正在判断的位置
	int end = 0;//小数循环部分结束位置 
	bool flag = 0;//是否整除 整除1，不整除0 
	cin>>n>>d;

	t = n/d;//整数部分 
    int integer = t;
	r = n%d;//最初的余数 
	cnt = 2;//位数从1开始，因为一定有小数点 
	r = n%d*10; 
	
	if(n/d!=0)cnt+=log10(n/d);
//	while(t != 0){//计算整数部分需要的字符数
//		cnt++;
//		t /= 10;
//	}
	
	for(int i = 1; i<=d*2; i++){
		decimal[++k] =  r/d;//小数
		if(remainder[r]){//某个余数之前出现过了 
			left = remainder[r];//左括号等于上一个的位置
			right = i-1;//右括号-1 
			break;//over 
		} 
		remainder[r] = i;
		if(r%d == 0){
			break;//能整除，over 
		}
		r = r%d*10;//下一位 
	}
	//先输出整数部分和小数点 	
	cout<<integer<<".";
	for(int i = 1; i<=k; i++){
		cnt++;
		if(i == left){
			cnt++;
			cout<<"(";
		}
		cout<<decimal[i];
		if(i == right){
			cout<<")";
			break;
			return 0;//“）”是最后的字符，输出后程序结束 
		}
		if(cnt%76 == 0){
			cout<<"\n";
			cnt = 0;//换行，cnt清零重新开始计数 
		}
	}
	
}



	







//有bug 
////Fractions to Decimals
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;//分子 
//	int d = 0;//分母 
//	int t = 0;//小数点前 
//	int r = 0;//余数（暂存） 
//	//int x = 0;//小数的某一位（暂存） 
//	int k = 0;//小数部分的位数 
//	int cnt = 0;//记录位数，题目要求超过79位要换行输出 
//	int decimal[100005] = {0};//decimal[i]代表除下来结果小数部分第i位（从0开始）
//	//如果余数出现重复，说明出现循环项 
//	int remainder[10000] = {0};//remainder[i]表示余数i第一次出现的位置
//	int start = 0;//小数循环部分开始位置
//	int temp = 0;//小数循环当前正在判断的位置
//	int end = 0;//小数循环部分结束位置 
//	bool flag = 0;//是否整除 整除1，不整除0 
//	cin>>n>>d;
//	memset(remainder, -1, sizeof(remainder));//初始化 
//	t = n/d;//整数部分 
//	int integer = t; 
//	r = n%d;//最初的余数 
//	
//	//循环判断处理 
//	while(true){
//		if(remainder[r] != -1){//某个余数第二次出现，预示着循环部分 
//			end = temp;
//			temp = remainder[r];
//		}
//		remainder[r] = temp;
//		r = r*10;//余数*10即末尾补0
//		decimal[temp] = r/d; //当前除出来的商就是下一个小数 
//		r = r%d;
//		if(r == 0){//整除 
//			flag = 1;
//			break;
//		}
//		temp++;//移动到下一位处理 		
//	}
//	
//	//折腾输出格式
//	cnt = 1;//位数的初始从1开始，因为小数点 
//	cout<<integer<<"."; //先输出整数部分和小数点
//	while(t != 0){//计算整数部分需要的字符数
//		cnt++;
//		t /= 10;
//	} 
//	for(int i = 0; i<temp; i++){
//		cout<<decimal[i];
//		cnt++;
//		if(cnt%76 == 0){
//			cout<<"\n";
//		}
//	}
//	//如果flag == 0，即不能整除
//	if(flag == 0){
//		//循环部分开始 
//		cout<<"(";
//		cnt++;
//		if(cnt%76 == 0){
//			cout<<"\n";
//		}
//		for(int i = temp; i<end; i++){
//			cout<<decimal[i];
//			cnt++;
//			if(cnt%76 == 0){
//				cout<<"\n";
//			}
//		}
//		cout<<")";
//		cnt++;
//		if(cnt%76 == 0){
//			cout<<"\n";
//		}
//	}
//	return 0;
//	
//	 
//	
//	
//	
//	
//}
