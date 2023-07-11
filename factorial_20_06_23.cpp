#include <iostream>
using namespace std;

class Factorial{
    public:
        int count = 0;
        int compute_fact(int n){
            count++;
            if(n == 0)
                return 1;
            return n*compute_fact(n-1);
        }
};

int main(){
    int n;
    Factorial fact;
    cout << "enter the number to find the Factorial: ";
    cin >> n;
    cout<<"Factorial is: "<<fact.compute_fact(n);
    cout <<"\n count: "<< fact.count;

}