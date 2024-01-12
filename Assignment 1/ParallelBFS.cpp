#include <iostream>
#include <queue>
#include <vector>
#include <omp.h>

using namespace std;

const int N = 6;    // number of vertices
vector<int> adj[N]; // adjacency list

void bfs(int start, vector<int> &distance)
{
    queue<int> q;
    distance[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

#pragma omp parallel for
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (distance[v] == -1)
            {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
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

    // run parallel BFS
    vector<int> distance(N, -1);
    bfs(0, distance);

    // output distances
    for (int i = 0; i < N; i++)
    {
        cout << "Distance from 0 to " << i << " is " << distance[i] << endl;
    }

    return 0;
}
