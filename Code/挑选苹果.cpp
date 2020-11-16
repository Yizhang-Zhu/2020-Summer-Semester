#include <iostream>
using namespace std;
int end1;
class Apple{
private:
public:
    string id;
    int weight;
    int diameter;
    int place;
    Apple(int place=0,string id="N/A",int weight=0,int diameter=0){
        this->place = place;
        this->id = id;
        this->weight=weight;
        this->diameter = diameter;
    }
    ~Apple(){}
};

int main(){
    int n;
    cin >> n;
    Apple A[n];
    int a,c,d;
    int max=0;
    int MAX=0;
    string b;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c >> d;
        if(a>max)
            max=a;
        Apple X(a,b,c,d);
        A[i]=X;
    }
    for(int j=1;j<=max;j++){
        MAX=0;
        bool judge=false;
        for(int k=0;k<n;k++){
            if(A[k].place==j){
                judge=true;
                if(A[k].weight>MAX){
                    MAX = A[k].weight;
                    end1 = k;
                }
            }
        }
        if(judge)
            cout << A[end1].place << " " << A[end1].id << " " << A[end1].weight << " " << A[end1].diameter << endl;

    }

}