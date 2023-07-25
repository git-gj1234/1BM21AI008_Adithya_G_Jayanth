#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class sortc{
    private:
        vector<int> a;
        int n, count_insertion;
    public:
        void get_input();
        void insertion_sortc();
        void display();
};

void sortc::get_input(){
    cout << "enter number of elements: ";
    cin >> n;
    a.resize(n);
    int choice;
    cout << "Select choice:\n1. Enter manually\n2. Random array\nEnter choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            cout << "enter array elements: \n";
            for(int i=0;i<n;i++){
                cin >> a[i];
            }
            break;
        case 2:
            for(int i=0;i<n;i++){
                a[i] = rand()%100;
            }
            break;            
    }    
}

void sortc::display(){
    cout << "sorted array: ";
    for(int i =0; i<n; i++){
        // cout << a[i] << " ";
    }
    cout << "\ncount: " << count_insertion;
}

void sortc::insertion_sortc(){
    int j;
    for(int i = 1; i<n ; i++){
        j = i-1;
        int key = a[i];
        while((j)>=0 && (a[j] > key)){
            count_insertion++;
            a[j+1] = a[j];
            j--;      
        }
        a[j+1] = key;
    }
}

int main(void){
    sortc sortcer;
    sortcer.get_input();
    sortcer.insertion_sortc();
    sortcer.display();

    return 0;
}