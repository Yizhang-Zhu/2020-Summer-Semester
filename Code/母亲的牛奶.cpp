//ĸ�׵�ţ�� -- alg: Depth First Search
#include<bits/stdc++.h>

using namespace std;

bool repeat[100][100][100] = {false};//�ж�·���Ƿ��ظ� 
bool pos[1000] = {false};//Ͱ����¼������������λ�ã���pos[i]Ϊ����
int A, B, C;//Ͱ�����������⣬Сд��abc�Ǹ���Ͱ��ţ�̵�ʣ���� 

void dfs(int a, int b, int c)
{
	if(repeat[a][b][c] == 1){
		return;//·���ظ� 
	}else{
		repeat[a][b][c] = 1;//���·�� 
	}
	if(a == 0){//a == 0:��ĿҪ��AͰ��
		pos[c] = 1;//��Ǵ� 
	}
	if(c){//C not empty: C->A C->b
		//C->A (A should not full)
		if(a<A) dfs(min(A, a+c), b, max(0, c-(A-a)));
		//C->B (B should not full)
		if(b<B) dfs(a, min(B, c+b), max(0, c-(B-b)));
	}
	if(b){//B not empty
		//B->A (A should not full)
		if(a<A) dfs(min(A, b+a), max(0, b-(A-a)), c);
		//B->C (C should not full)
		if(c<C) dfs(a, max(0, b-(C-c)), min(C, b+c));
	}
	if(a){//A not empty
		//A->B (B should not full)
		if(b<B) dfs(max(0, a-(B-b)), min(B, a+b), c);
		//A->C (C should not full)
		if(c<C) dfs(max(0, a-(C-c)), b, min(C, a+c));
	}
} 

int main()
{
	cin>>A>>B>>C;
	dfs(0, 0, C);
	//PTA���û�пո�
	int cnt = 0; 
	for(int i = 0; i<=C; i++){
		if(pos[i] == 1){
			cnt++;
			if(cnt == 1){
				cout<<i;
			}else{
				cout<<" "<<i;
			}
		}
	}
} 
