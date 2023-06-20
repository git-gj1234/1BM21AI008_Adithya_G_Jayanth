#include <iostream>
using namespace std;

class TowerOfHanoi{
    public:
        void solve(int n, char start, char intermediate, char stop){
            if(n == 0)
                return;
            solve(n-1, start, stop, intermediate);
            cout << "move disk from "<<start<<" to "<<stop<<"\n";
            solve(n-1, intermediate, start, stop);
        }
};

int main(){
    int n;
    TowerOfHanoi toh;
    cout << "enter the number of disks: ";
    cin >> n;
    toh.solve(n,'A','B','C');
    return 0;
}