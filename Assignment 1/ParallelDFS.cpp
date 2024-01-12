#include <iostream>
#include <stack>
#include <vector>
#include <omp.h>

using namespace std;

const int N = 6; // number of vertices
vector<int> adj[N]; // adjacency list

void dfs(int start, vector<bool>& visited) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!visited[u]) {
            visited[u] = true;

            #pragma omp parallel for
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (!visited[v]) {
                    s.push(v);
                }
            }
        }
    }
}

int main() {
    // initialize adjacency list
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(2);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(3);
    adj[5].push_back(4);

    // run parallel DFS
    vector<bool> visited(N, false);
    dfs(0, visited);

    // output visited vertices
    cout << "Visited vertices: ";
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
