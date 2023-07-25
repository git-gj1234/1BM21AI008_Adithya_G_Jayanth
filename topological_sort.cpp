#include <iostream>
#include <vector>
using namespace std;

class sort{
    private:
        vector<vector <int>> a;
        vector<int> sorted;
        int n; 
    public:
        void get_adjacency_matrix();
        void topological_sort();
        void display();
};

void sort::display(){
    cout << "sorted nodes order:\n";
    for(int i = 0; i<n; i++)
        cout << sorted[i] << "\n"; 
}

void sort::get_adjacency_matrix(){
    cout << "enter the number of nodes: ";
    cin >> n;
    a.resize(n, vector<int>(n));
    sorted.resize(n);
    cout << "enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j<n; j++)
            cin >> a[i][j];
}

void sort::topological_sort(){
    int s[n], indegree[n],u,v;
    int top = -1, top_sorted = 0, sum;

    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j< n; j++){
            sum += a[j][i];
        }
        indegree[i] = sum;
        if(sum == 0)
            s[++top] = i;
    }

    while(top != -1){
        u = s[top--];
        sorted[top_sorted++] = u;
        for(int i = 0; i < n; i++){
            if(a[u][i] == 1){
                indegree[i] = indegree[i]-1;
                if(indegree[i] == 0)
                    s[++top] = i;
            }
        }        
    }
}

int main(void){
    sort sorter;
    sorter.get_adjacency_matrix();
    sorter.topological_sort();
    sorter.display();
}