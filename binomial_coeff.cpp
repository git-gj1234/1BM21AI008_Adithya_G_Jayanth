#include <iostream>
using namespace std;

class binomial{
    private:
        int n,k;
    public:
        void get_n_k();
        int minimum(int a, int b);
        void BC();
};

void binomial::get_n_k(){
    cout<<"Enter value of n: ";
    cin>>n;
    cout<<"Enter value of k: ";
    cin>>k;
}

int binomial::minimum(int a,int b){
    return a<b ? a:b ;
}

void binomial::BC(){
    int C[n+1][k+1];
    int i,j,l=2;
    for(i=0;i<n+1;i++){
        if(i<k+1){
            C[i][i] = 1;
        }
        C[i][0] = 1;
    }
    for(i=2;i<=n;i++){
        j = 1;
        while(j<l){
            if(l<=minimum(i-1,k)){
                l++;
            }
            C[i][j] = C[i-1][j-1]+C[i-1][j];
            j++;
        }
    }
    cout << "Value of "<<n<<"C"<<k<<" is: " << C[n][k];
}





int main(void){
    binomial solver;
    solver.get_n_k();
    solver.BC();
}

