#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

class Search{
    public:
        void BinarySearch(int arr[], int n, int key){
            int low = 0;
            int high = n-1;
            int mid = (low+high)/2;
            while(low <= high){
                if(arr[mid] == key){
                    // cout << "key found\n";
                    // cout <<"key value: "<<key<<"\n";
                    // cout <<"key index(array index): "<<mid;
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
            // cout << "key not found in array";
        }
        void LinearSearch(int arr[], int size, int key){
            for(int i=0;i<size;i++){
                if(key == arr[i]){
                    // cout << "Element found at index: "<<i<<"\n";
                    return;
                }
            }
            // cout << "element not found\n";
        }
};

int main()
{
    int key;
    int low, mid, high;
    int arr[100000];
    for(int i = 0; i< 100000; i++){
        arr[i] = i;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    // std::sort(arr,arr+n);
    // cout<<"sorted array:\n";
    // for(int i=0; i < n; i++){
    //     cout << arr[i]<<" ";
    // }
    cout << "\nenter key: ";
    cin >> key;
    Search search;

    clock_t start = clock();
    for(int i = 0; i< 1000; i++)
    search.BinarySearch(arr, n, key);
    clock_t stop = clock();
    double duration = (stop - start) / (double) CLOCKS_PER_SEC * 1000;
    std::cout << "Time taken by BinarySearch: " << duration << " milliseconds\n";

    clock_t start2 = clock();
    for(int i = 0; i< 1000; i++)
    search.LinearSearch(arr, n, key);
    clock_t stop2 = clock();
    double duration2 = (stop2 - start2) / (double) CLOCKS_PER_SEC * 1000;
    std::cout << "Time taken by LinearSearch: " << duration2 << " milliseconds\n";

    return 0;
}