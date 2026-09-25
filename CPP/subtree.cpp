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
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

void dfs(vector<vector<int>> &graph , int vertex , int parent , vector <int> &subtree){
    subtree[vertex] += vertex;
    for (int child : graph[vertex]){
        if (child != parent){
            dfs(graph , child , vertex);
            subtree[vertex] += subtree[child];
        }
    }
}

int main()
{
    fastio();
    

    return 0;
}



