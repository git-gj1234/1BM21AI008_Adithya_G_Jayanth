#include <iostream>
using namespace std;

class ComputeGCD{
    public:
        int get_gcd(int n, int m){
            if(m == 0)
                return n;
            else return get_gcd(m, n%m);
        }
};

int main(){
    int n,m,res;
    ComputeGCD gcd;
    cout<<"enter the numbers to find the gcd: ";
    cin >> n >> m;
    res = gcd.get_gcd(n,m);
    cout <<"res: "<<res;
}
