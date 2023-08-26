#include <iostream>
#include <vector>
using namespace std;

class knapsack{
    private:
        int l,c;
        vector<int> w;
        vector<int> p;
    public:
        void get_input();
        int max(int a, int b);
        void knap_sack();
};

void knapsack::get_input(){
    cout << "enter no. of items: ";
    cin >> l;
    w.resize(l);
    p.resize(l);
    cout << "enter the weights of the items: ";
    for(int i =0 ;i < l; i++){
        cin >> w[i];
    }
    cout << "enter the profits of the items: ";
    for(int i =0 ;i < l; i++){
        cin >> p[i];
    }
    cout << "enter the value of c: ";
    cin >> c;
}

int knapsack::max(int a, int b){
    return a > b? a:b;
}

void knapsack::knap_sack(){
    vector<vector<int> > T(l+1,vector<int>(c+1));
    int i,j;
    for(i=0;i<=l;i++){
        for(j=0;j<=c;j++){
            if(i == 0 || j == 0){
                T[i][j] = 0;
            }
            else if(j>=w[i-1]){
                T[i][j] = max(p[i-1]
                                    + T[i-1][j-w[i-1]],
                                T[i-1][j]);
            }
            else{
                T[i][j] = T[i-1][j];
            }
            
            cout<<T[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout << "max possible value: "<< T[l][c];
}

int main(void){
    knapsack solver;
    solver.get_input();
    solver.knap_sack();
}