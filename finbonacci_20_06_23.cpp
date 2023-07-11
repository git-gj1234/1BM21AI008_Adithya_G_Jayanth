#include <iostream>
using namespace std;

class FIB{
  public:
    int count = 0;
    int fib(int x){
        count++;
        if(x == 1)
            return 0;
        if(x == 2)
            return 1;
        return fib(x-1) + fib(x-2);
    }


    void printfib(int n){
        cout << "first "<<n<<" fibonacci numbers are:\n";
        for(int i=1; i <= n; i++){
            cout << fib(i)<<" ";
        }
    }

};

int main(){
    FIB fib_num;
    int n;
    cout <<"enter number of fibonacci numbers: ";
    cin >> n;
    fib_num.printfib(n);
    cout <<"\ncount: "<<fib_num.count;
    return 0;

}