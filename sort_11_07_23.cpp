#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

class sort{
    private:
        int n, a[20];
    public:
        int count_selection = 0, count_bubble = 0;
        int get_n();
        void selection_sort();
        void bubble_sort();
        void getInput();
        void print();
        void swap(int *a, int *b);
        void merge_sort(int start, int end);
        void merge(int start, int mid, int end);
        void quick_sort(int start, int end);
        int partition(int start, int end);
};

int sort::get_n(){
    return n;
}

void sort::getInput(){
    cout << "enter the number of elements: ";
    cin >> n;
    cout << "enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void sort::print(){
    cout << "sorted array:\n";
    for(int i= 0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

void sort::swap(int *a , int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort::selection_sort(){
    for(int cur = 0; cur < n-1; cur++){
        for(int i = cur+1; i < n; i ++){
            count_selection++;
            if(a[i] < a[cur])
                swap(a + i, a + cur);
        }
    }
}

void sort::bubble_sort(){
    for(int k = n-1; k > 0; k--){
        for(int i = 0; i < k; i++){
            count_bubble++;
            if(a[i] > a[i+1])
                swap(a+i , a+i+1);
        }
    }
}

void sort::merge(int start, int mid, int end){
    int n = mid - start + 1;
    int m = end - mid;
    int left_array[n], right_array[m];
    int p1 = 0, p2 = 0, p = start;

    for(int i = 0; i < n; i++)
        left_array[i] = a[start + i];
    for(int j = 0; j < m; j++)
        right_array[j] = a[mid + j + 1];
    
    while(p1 < n && p2 < m){
        if(left_array[p1] < right_array[p2]){
            a[p] = left_array[p1];
            p1++;
        }
        else{
            a[p] = right_array[p2];
            p2++;
        }
        p++;
    }
    while(p1 < n){
        a[p] = left_array[p1];
        p1++;
        p++;
    }
    while(p2 < m){
        a[p] = right_array[p2];
        p2++;
        p++;
    }
}

void sort::merge_sort(int start, int end){
    if(start >= end)
        return;
    int mid = start + (end - start)/2;
    merge_sort(start, mid);
    merge_sort(mid+1, end);
    merge(start, mid, end);
}

int sort::partition(int start, int end){
    int pivot = a[start];
    int i = start + 1;
    int j = end;

    while(true){
        while(i <= j && a[i] <= pivot)
            i++;
        while(i <= j && a[j] >= pivot)
            j--;
        if(i > j)
            break;
        swap(a+i,a+j);
    }
    swap(a+j,a+start);
    return j;
}

void sort::quick_sort(int start, int end){
    if(start < end){
        int partition_index = partition(start, end);
        quick_sort(start, partition_index - 1);
        quick_sort(partition_index + 1, end);
    }
}

int main(void){
    int arr_size, choice;
    sort sorter;
    cout << "Cpp program for sorting\n";
    sorter.getInput();
    arr_size = sorter.get_n();

    auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t;

    while(true){
        cout << "select choice:\n";
        cout << "1. selection_sort\n2. Bubble_sort\n3. merge_sort\n4. quick_sort\nEnter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            {
                sort copy_sorter = sorter;
                start = std::chrono::high_resolution_clock::now();
                copy_sorter.selection_sort();
                cout << "count: "<< copy_sorter.count_selection << "\n";
                finish = std::chrono::high_resolution_clock::now();
                t = finish - start;
                std::cout << "Elapsed time: " << t.count() << " s\n";
                copy_sorter.print();
                break;
            }
            case 2:
            {
                sort copy_sorter = sorter;
                start = std::chrono::high_resolution_clock::now();
                copy_sorter.bubble_sort();
                cout << "count: "<< copy_sorter.count_bubble << "\n";
                finish = std::chrono::high_resolution_clock::now();
                t = finish - start;
                std::cout << "Elapsed time: " << t.count() << " s\n";
                copy_sorter.print();
                break;
            }
            case 3:
            {
                sort copy_sorter = sorter;
                start = std::chrono::high_resolution_clock::now();
                copy_sorter.merge_sort(0, arr_size - 1);
                finish = std::chrono::high_resolution_clock::now();
                t = finish - start;
                std::cout << "Elapsed time: " << t.count() << " s\n";
                copy_sorter.print();
                break;
            }
            case 4:
            {
                sort copy_sorter = sorter;
                start = std::chrono::high_resolution_clock::now();
                copy_sorter.quick_sort(0, arr_size - 1);
                finish = std::chrono::high_resolution_clock::now();
                t = finish - start;
                std::cout << "Elapsed time: " << t.count() << " s\n";
                copy_sorter.print();
                break;
            }
            default:
                cout << "Invalid choice\n";
                break;
        }
    }
    return 0;
}

