#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SOS{
    private:
        int n, desired_sum, count = 1;
        vector<int> set;
        vector<bool> included;
    public: 
        void get_input();
        void sum_of_subsets();
        void sum_of_subsets(int cs, int k, int r);
};

void SOS::sum_of_subsets(){
    int sum  = 0;
    for(int i = 0; i<n; i++)
        sum += set[i];
    if(sum < desired_sum){
        cout << "no solution: ";
        return;
    }
    sum_of_subsets(0, 0, sum);
}

void SOS::sum_of_subsets(int current_sum, int current_index, int remaining_sum){
    // cout << current_sum << "\n";
    included[current_index] = true;
    if(current_sum + set[current_index] == desired_sum){
        cout << "solution: " << count++ << "\n";
        for(int i = 0; i<= current_index; i++){
            if(included[i])
                cout << set[i] << " ";
        }
        cout << "\n";
    }
    else if(current_sum + set[current_index] + set[current_index +1 ] <= desired_sum){
        sum_of_subsets(current_sum + set[current_index], current_index+1, remaining_sum-set[current_index]);
    }
    if(current_sum + remaining_sum - set[current_index] >= desired_sum && current_sum + set[current_index+1] <=desired_sum){
        included[current_index] = false;
        sum_of_subsets(current_sum, current_index+1, remaining_sum-set[current_index]);
    }
}

void SOS::get_input(){
    cout << "enter the number of set elements: ";
    cin >> n;
    cout << "enter the array elements: ";
    set.resize(n);
    included.resize(n, false);
    for(int i = 0;i<n;i++){
        cin >> set[i];
    }
    sort(set.begin(),set.end());
    cout << "enter the desired sum: ";
    cin >> desired_sum; 
}

int main(void){
    SOS solver;
    solver.get_input();
    solver.sum_of_subsets();

}