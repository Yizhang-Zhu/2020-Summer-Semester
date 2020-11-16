//Check Challenge
#include<bits/stdc++.h>

using namespace std;

int N = 0;//输入的N
int chess[15];//棋盘
int cnt = 0;//计数器

void dfs(int column, int main_diag, int anti_diag, int x)
{
    if (x == N) {
        if (cnt++ < 3) {
            for (int i = 0; i < N; i++) {
				if(i == 0){
					cout << chess[i] + 1;
				}else{
					cout << " " << chess[i] + 1 ;
				}
            }
            cout << endl;
        }
        return;
    }
    for (int j = 0; j < N; j++)
    {
        if ((!(column & (1 << j))) && (!(main_diag & (1 << x - j + N - 1))) && (!(anti_diag & (1 << x + j))))
        {
            chess[x] = j;
            dfs(column | (1 << j), main_diag | (1 << x - j + N - 1), anti_diag | (1 << x + j), x + 1);
        }
    }
}
int main()
{
    cin >> N;
    dfs(0, 0, 0, 0);
    cout << cnt << endl;
}




