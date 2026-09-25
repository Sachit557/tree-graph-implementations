#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define pb push_back
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ld = long double;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif


void dfs(int vertex , vector<vector<int>> &graph ,int parent , vector <int> &depth , vector <int> &height){
    for (auto child : graph[vertex]){
        if (child == parent) continue;
            depth[child] = depth[vertex]+1;
            dfs(child , graph , vertex , depth , height);
            height[vertex] = max(height[vertex] , height[child]+1);
    }
}

int main(void){
    int n;
    cin >> n;
    vector <vector <int>> graph(n+1);
   for (int i = 0; i < n-1; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
   }
    
    vector <int> depth(n+1) , height(n+1);
   dfs(1 , graph , -1 , depth , height );
    for (int i = 1;i<n+1;++i){
        cout << "depth of " << i << " is " << depth[i] << endl << "Height of " << i << " is " << height[i] << endl;
    }


}
