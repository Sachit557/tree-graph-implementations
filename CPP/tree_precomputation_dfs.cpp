#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define pb push_back
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) std::cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif
void solve();

int main()
{
    fastio();

    auto start = chrono::high_resolution_clock::now();

    solve();
    auto end = chrono::high_resolution_clock::now();

    std::cerr << "\nTime: "
              << chrono::duration<double, milli>(end - start).count()
              << " ms\n";

    return 0;
}

// subtree_sum maintains sum of subtree of a node . O(1) access after 1 precomputation (dfs)
// even_nodes maintain how many nodes in subtree of a node are even . here index of a node is taken as value for simplicity . O(1) acess after precomputation (dfs)

void dfs(vector<vector<int>> &graph, int node, int parent, vector<int> &subtree_sum, vector<int> &even_nodes)
{
    subtree_sum[node] += node;
    if (node % 2 == 0)
        even_nodes[node]++;

    for (auto child : graph[node])
    {
        if (child == parent)
            continue;
        dfs(graph, child, node, subtree_sum, even_nodes);

        subtree_sum[node] += subtree_sum[child];
        even_nodes[node] += even_nodes[child];
    }
}

void solve()
{
    int n, m, x, y;
    std::cin >> n >> m;
    std::vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; ++i)
    {
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    std::vector<int> subtree_sum(n + 1, 0);
    std::vector<int> even_nodes(n + 1, 0);

    dfs(graph, 1, 0, subtree_sum, even_nodes);
    // call dfs once to precompute stuff

    int q;
    cin >> q;
    while (q--)
    {
        int v;
        cin >> v;
        std::cout << "Subtree sum of node " << v << " is " << subtree_sum[v] << std::endl;
        std::cout << "Number of even nodes in subtree of " << v << " is " << even_nodes[v] << std::endl;
    }
}
