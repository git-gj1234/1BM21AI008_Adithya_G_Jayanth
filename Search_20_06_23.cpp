#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
using namespace std;

class Search{
    public:
        int count_binary = 0, count_linear = 0;
        void BinarySearch(int arr[], int n, int key){
            int low = 0;
            int high = n-1;
            int mid = (low+high)/2;
            while(low <= high){
                count_binary++;
                if(arr[mid] == key){
                    cout << "key found\n";
                    cout <<"key value: "<<key<<"\n";
                    cout <<"key index(array index): "<<mid<<"\n";
                    return;
                }
                else if(key < arr[mid]){
                    high = mid - 1;
                }
                else{
                    low =mid + 1;
                }
                mid = (low + high)/2;
            }
            cout << "key not found in array";
        }
        void LinearSearch(int arr[], int size, int key){
            for(int i=0;i<size;i++){
                count_linear++;
                if(key == arr[i]){
                    cout << "Element found at index: "<<i<<"\n";
                    return;
                }
            }
            cout << "element not found\n";
        }
};

int main()
{
    int key;
    int low, mid, high;
    int arr[10],n;
    cout << "enter array size: ";
    cin >> n;
    cout << "enter array elements: ";
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }
    // int n = sizeof(arr)/sizeof(arr[0]);
    std::sort(arr,arr+n);
    // cout<<"sorted array:\n";
    // for(int i=0; i < n; i++){
    //     cout << arr[i]<<" ";
    // }
    cout << "\nenter key: ";
    cin >> key;
    Search search;

    cout <<"\nBinary search:\n";
    auto start1 = std::chrono::high_resolution_clock::now();
    search.BinarySearch(arr, n, key);
    auto finish1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t = finish1 - start1;
    std::cout << "Elapsed time: " << t.count() << " s\n";
    cout << "count: "<<search.count_binary<<"\n";


    cout <<"\nLinear search:\n";
    auto start2 = std::chrono::high_resolution_clock::now();
    search.LinearSearch(arr, n, key);
    auto finish2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t2 = finish2 - start2;
    std::cout << "Elapsed time: " << t2.count() << " s\n";
    cout << "count: "<<search.count_linear<<"\n";
    return 0;
}

