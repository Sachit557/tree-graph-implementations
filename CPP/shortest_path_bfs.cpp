/*
    Breath first search (bfs) can be used to find shortest path between 2 nodes assuming that weight of all edges is the same
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

const int MOD = 1e9 + 7;

void solve();

int main()
{
    fastio();

    solve();

    return 0;
}

void bfs(std::vector<std::vector<int>> &graph, int u)
{
    int n = graph.size() - 1;

    std::queue<int> q;
    std::vector<int> used(n + 1, 0);
    std::vector<int> parent(n + 1, -1);
    used[u] = 1;
    q.push(u);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        for (auto child : graph[vertex])
            if (!used[child])
            {
                used[child] = 1;
                q.push(child);
                parent[child] = vertex;
            }
    }

    if (!used[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    std::vector<int> path;
    for (int i = n; i != -1; i = parent[i])
        path.push_back(i);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (const auto &it : path)
        cout << it << ' ';
    cout << endl;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(graph, 1); // finds the shortest path from node 1 to n assuming a path exists
}
