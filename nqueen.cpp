#include <iostream>
#include <vector>
using namespace std;

class nqueen{
    private:
        int n;
        vector<int> queen;
    public:
        int get_input();
        int place(int k);
        void n_queen();
};

int nqueen::get_input(){
    cout << "enter the board size(number of queens): ";
    cin >> n;
    if(n == 2 || n==3){
        cout << "no solution for given number of queens\n";
        return 0;
    }
    queen.resize(n+10);
    cout << "input received:";
    return 1;
}

int nqueen::place(int k){
    for(int i =1; i < k; i++){
        if(i + queen[i] == k + queen[k] || i - queen[i] == k - queen[k] || queen[i] == queen[k])
            return 0;
    }
    return 1;
}

void nqueen::n_queen(){
    int k = 1;
    int count = 0;
    queen[k] = 0;
    while(k != 0){
        queen[k]++;
        while(!place(k) && queen[k] <= n){
            queen[k]++;
        }
        if(queen[k] <= n){
            if(k == n){
                cout << "Solution: " << ++count << "\n";
                cout << "queen\tposition\n";
                for(int i = 1; i <= n; i++){
                    cout << i << "\t" << queen[i] << "\n";
                }
            }
            else{
                k++;
                queen[k] = 0;
            }
        }
        else{
            k--;
        }
    }
}

int main(void){
    nqueen solver;
    solver.get_input();
    solver.n_queen();
    return 0;
}