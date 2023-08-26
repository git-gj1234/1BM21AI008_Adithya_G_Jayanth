#include<iostream>
#include<vector>
using namespace std;

class heap{
    private:
        vector<int> a;
    public:
        void heapify();
        void heapify(int end);
        void heap_sort();
        void get_input();
        void print_heap();
};

void heap::heap_sort(){
    int n = a.size();
    for(int i = n-1; i > 1; i--){
        int root = a[1];
        if(a[1] > a[i]){
            a[1] = a[i];
            a[i] = root;
            heapify(i-1);
            print_heap();
        }
    }
    cout << "heapsort done\n";
}

void heap::print_heap(){
    int n = a.size();
    cout << "current heap: ";
    for(int i = 1; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

void heap::heapify(){
    int n = a.size();
    heapify(n);
}

void heap::heapify(int end){
    int n = a.size();
    for(int i = end/2; i > 0; i--){
        int k = i, v = a[k];
        bool is_heap = false;
        while(!is_heap && 2*k < end){
            int j = 2*k;
            if(j < n){
                if(a[j] < a[j+1])
                    j = j+1;
            }
            if(v > a[j])
                is_heap = true;
            else{
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

void heap::get_input(){
    int x;
    cout << "enter the number of elements: ";
    cin >> x;
    x = x+1;
    a.resize(x);
    cout << "enter the elements: ";
    for(int i = 1; i< x; i++){
        cin >> a[i];
    }
}

int main(void){
    heap heap_obj;
    heap_obj.get_input();
    heap_obj.heapify();
    heap_obj.print_heap();
    heap_obj.heap_sort();
    heap_obj.print_heap();
}