#include <iostream> 
#include <algorithm> 
#include <vector>

using namespace std;

int graph_represent[][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

void print_board() {
    for (int x = 0; x < 4; x++) {
        cout << endl; 

        for (int y = 0; y < 4; y++) {
            cout << graph_represent[x][y] << ", ";
        }
    }
}

void add_edge(int con_1, int con_2) {
    graph_represent[con_1][con_2] = 1;

    graph_represent[con_2][con_1] = 1;
}

vector<int> list_connections(int from) {
    vector<int> destination = {}; 
    int start = from; 

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if ((x == start) && (graph_represent[x][y] == 1)) {
                destination.push_back(y); 
            }
        }
    }

    return destination; 
}

void dfs(vector<bool> &visited, int s, vector<int> &res, int to) {
    visited[s] = true;
    res.push_back(s);

    for (int i : list_connections(s)) {
        if (i == to) {
            for (int element : res) {
                cout << element << " ";
            }
            std::cout << "found" << std::endl; 
            return;
        }
        if (visited[i] == false)
            dfs(visited, i, res, to);
    }
}

void show_path(int from, int to){ 
    vector<bool> visited(4, false);
    vector<int> res;
    dfs(visited, 0, res, to);
    
    // print_board();
}



int main() {
    /*
        0, 1, 1, 0
        1, 0, 1, 0
        1, 1, 0, 1
        0, 0, 1, 0
    */

    // create a connection between nodes
    add_edge(0, 1);
    add_edge(0, 2); 
    add_edge(1, 2);
    add_edge(2, 3);

    // Print the board
    print_board();
    cout << endl; 

    // List destinations which have connect to the provide node
    vector<int> fromZero = list_connections(0); // 1, 2
    for (int desZero: fromZero) {
        cout << desZero << ", ";
    }

    cout << endl; 

    vector<int> fromTwo = list_connections(2); // 0, 1, 3
    for (int desTwo: fromTwo) {
        cout << desTwo << ", ";
    }

    // Show the path from start -> destination
    // show_path(0, 1); // 0->1
    cout << endl;
    show_path(0, 3); // 0->2->3 ; 0->1->2->3
    
    return 0; 
}