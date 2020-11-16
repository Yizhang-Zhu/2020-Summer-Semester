//the clocks
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int clock[10] = {0};//9个时钟
    int change[10] = {0};//9种变换
    for(int i = 1; i<=9; i++){
        cin>>clock[i];
        clock[i] /= 3;//9->3 6->2 3->1 每个时钟转到12需要（12-k）%4次移动
    }

    //暴力搜索，每种改变方式最少0次，最多三次（3:00变成12:00要3次）
    //m1表示第一种改变方式
    for(int m1 = 0; m1<=3; m1++){
        for(int m2 = 0; m2<=3; m2++){
            for(int m3 = 0; m3<=3; m3++){
                for(int m4 = 0; m4<=3; m4++){
                    for(int m5 = 0; m5<=3; m5++){
                        for(int m6 = 0; m6<=3; m6++){
                            for(int m7 = 0; m7<=3; m7++){
                                for(int m8 = 0; m8<=3; m8++){
                                    for(int m9 = 0; m9<=3; m9++){
                                        //判断是否满足题意
                                        if((m1+m2+m4)%4==(4-clock[1]) &&
                                        (m1+m2+m3+m5)%4==(4-clock[2]) &&
                                        (m2+m3+m6)%4==(4-clock[3]) &&
                                        (m1+m4+m5+m7)%4==(4-clock[4]) &&
                                        (m1+m3+m5+m7+m9)%4==(4-clock[5]) &&
                                        (m3+m5+m6+m9)%4==(4-clock[6]) &&
                                        (m4+m7+m8)%4==(4-clock[7]) &&
                                        (m5+m7+m8+m9)%4==(4-clock[8]) &&
                                        (m6+m8+m9)%4==(4-clock[9])){
                                            int method[10] = {0,m1,m2,m3,m4,m5,m6,m7,m8,m9};
                                            for(int c = 1; c<=9; c++){//记录每种变换方式使用了几次
                                                change[c] = method[c];
                                            }
                                            //输出
                                            int cnt = 0;
                                            for(int i = 0; i<=9; i++){
                                                if(change[i]>0){
                                                    for(int j = 1; j<=change[i]; j++){
                                                        cnt++;
                                                        //结尾不能有空格
                                                        if(cnt == 1){
                                                            cout<<i;
                                                        }else{
                                                            cout<<" "<<i;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}