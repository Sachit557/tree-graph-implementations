/*
    Breadth First Search (BFS) using a queue to traverse an
    undirected graph level by level.

    Uses a visited array to avoid revisiting nodes.

    Traversal starts from a given source vertex.
*/
#include <bits/stdc++.h>
using namespace std;

void bfs(int vertex, vector<vector<int>> &graph);
void Sachit0007();

int main(){
    int t = 1;
    while(t--)Sachit0007();
    return 0;
}

void bfs(int vertex, vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> used(n, 0);
    queue<int> q;
    q.push(vertex);
    used[vertex] = 1;

    while (!q.empty())
    {
        vertex = q.front();
        q.pop();

        cout << vertex << endl;

        for (int child : graph[vertex])
        {
            if (!used[child])
            {
                used[child] = 1;
                q.push(child);
            }
        }
    }
}

void Sachit0007()
{
    int n, k;
    cin >> n>> k;

    vector<vector<int>> graph(n+ 1);

    for (int i = 0; i < k; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }


    // BFS from node 1
    bfs(1, graph);

    return 0;
}

