#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class LinearSearch{
    public:
        void search(int arr[], int key){
            for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
                if(key == arr[i]){
                    cout << "Element found at index: "<<i;
                    return;
                }
            }
            cout << "element not found";
        }
};

int main(){
    int key;
    int arr[] = {45,12,34,89,56,3,55};
    LinearSearch LS;
    cout << "enter key to search for: ";
    cin >> key;
    clock_t start = clock();
    LS.search(arr, key);
    clock_t stop = clock();
    double duration = (stop - start) / (double) CLOCKS_PER_SEC * 1000;

    // Print the duration
    std::cout << "Time taken: " << duration << " milliseconds";
}