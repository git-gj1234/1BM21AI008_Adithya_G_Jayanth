#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; 

class floyd_war{
    private:
        int V,E;
        vector<vector<int>> graph;
    public:
        void get_graph();
        void floydWarshall();
        void print_output();
};

void floyd_war::get_graph(){
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    graph.resize(V, vector<int>(V, INF));
    cout << "Enter edge information (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    for (int i = 0; i < V; ++i) {
        graph[i][i] = 0;
    }
}

void floyd_war::floydWarshall(){
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (graph[i][k] < INF && graph[k][j] < INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

void floyd_war::print_output(){
    cout << "Shortest distances between all pairs of vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main(void){
    floyd_war solver;
    solver.get_graph();
    solver.floydWarshall();
    solver.print_output();
    return 0;
}