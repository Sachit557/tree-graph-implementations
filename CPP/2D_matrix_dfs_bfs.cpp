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
void solve();

int main()
{
    fastio();

    auto start = chrono::high_resolution_clock::now();

    solve();

    auto end = chrono::high_resolution_clock::now();

    cerr << "\nTime: "
         << chrono::duration<double, milli>(end - start).count()
         << " ms\n";

    return 0;
}

void bfs(std::vector<std::vector<int>> &graph , int i , int j ){
    std::queue<std::pair<int , int>> qu;
    int m = graph.size() , n = graph[0].size();
    qu.push(std::make_pair(i , j));

    while(!qu.empty()){
        std::pair<int , int> temp = qu.front();
        qu.pop();
        if (temp.first < 0 || temp.second < 0 || temp.first >= m || temp.second >= n) continue;
        if (!graph[temp.first][temp.second]) continue;
        
        cout << temp.first << ' ' << temp.second << endl;
        graph[temp.first][temp.second] = 0;

        qu.push(std::make_pair(temp.first+1 , temp.second));
        qu.push(std::make_pair(temp.first-1 , temp.second));
        qu.push(std::make_pair(temp.first , temp.second+1));
        qu.push(std::make_pair(temp.first , temp.second-1));

    }
    
}

void dfs_recursive(std::vector<std::vector<int>> &graph , int i , int j){
    int m = graph.size() , n = graph[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n) return;
    if (!graph[i][j]) return;

    graph[i][j]=0;

    dfs_recursive(graph , i+1 , j);
    dfs_recursive(graph , i-1 , j);
    dfs_recursive(graph , i , j+1);
    dfs_recursive(graph , i , j-1);
}

void dfs_stack(std::vector<std::vector<int>> &graph , int i , int j){
    int m = graph.size() , n = graph[0].size();
        
    std::stack<std::pair<int , int>> st;
    st.push(std::make_pair(i , j));
    
    while(!st.empty()){
        
        std::pair temp = st.top();
        st.pop();
        
        if (temp.first < 0 || temp.second < 0 || temp.first >= m || temp.second >= n) continue;
        if (!graph[temp.first][temp.second]) continue;
        
        cout << temp.first << ' ' << temp.second << endl;
        graph[temp.first][temp.second]=0;

        st.push(std::make_pair(temp.first+1 , temp.second));
        st.push(std::make_pair(temp.first-1 , temp.second));
        st.push(std::make_pair(temp.first , temp.second+1));
        st.push(std::make_pair(temp.first , temp.second-1));
    }
}

void solve(){
    int n , m;
    cin >> n >> m ;
    std::vector<std::vector<int>> graph(n , std::vector<int>(m , 0));
    for (auto &it:graph)for (auto &iter : it) cin>>iter;
    for (int i = 0 ; i < n ; ++i){
        for (int j = 0 ; j < m ; ++j){
            if (graph[i][j]) 
                dfs_stack(graph , i , j);
        }
    }

}
