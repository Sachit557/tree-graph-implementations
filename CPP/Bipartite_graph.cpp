/*
    Checks whether an undirected graph is bipartite using DFS.

    Colours the graph using two colours (1 and 2), ensuring that
    no two adjacent vertices belong to the same team.

    If two adjacent vertices have the same colour, the graph is
    not bipartite and "IMPOSSIBLE" is printed.

    CSES Problem: Building Teams
    https://cses.fi/problemset/task/1668/
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

const int MOD = 1e9 + 7;

void Sachit0007();

int main()
{
    fastio();
    Sachit0007();
    return 0;
}

void dfs(int node, int parent, std::vector<std::vector<int>> &graph, std::vector<bool> &used, int team, std::vector<int> &ans)
{
    used[node] = 1;
    ans[node] = (team == 1 ? 2 : 1);
    for (auto child : graph[node])
    {
        if (child == parent)
            continue;
        else if (used[child])
        {
            if (ans[child] == ans[node])
            {
                cout << "IMPOSSIBLE" << endl;
                exit(0);
            }
        }
        else
        {
            dfs(child, node, graph, used, ans[node], ans);
        }
    }
}

void Sachit0007()
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

    std::vector<bool> used(n + 1, 0);
    std::vector<int> ans(n + 1, 0);
    int team = 2;
    for (int i = 1; i <= n; ++i)
    {
        if (!used[i])
            dfs(i, 0, graph, used, team, ans);
    }

    for (int i = 1; i <= n; ++i) // prints out the colour of each node (if bipartite)
        cout << ans[i] << ' ';
    cout << endl;
}
