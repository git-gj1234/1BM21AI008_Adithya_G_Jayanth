#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int key;
    int low, mid, high;
    int arr[] = {34,56,45,78,91,38,96,43,76};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::sort(arr,arr+n);
    cout<<"sorted array:\n";
    for(int i=0; i < n; i++){
        cout << arr[i]<<" ";
    }
    cout << "\nenter key: ";
    cin >> key;
    low = 0;
    high = n-1;
    mid = (low + high)/2;
    while(low <= high){
        if(arr[mid] == key){
            cout << "key found\n";
            cout <<"key value: "<<key<<"\n";
            cout <<"key index(array index): "<<mid;
            return 0;
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

    return 0;
}