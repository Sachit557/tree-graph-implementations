/*
    using bfs with path reconstruction to find the shortest path in a maze where paths are marked by a '.' and a wall is marked by a '#'. starting position is 'A' and ending position is 'B'
    for more info check out https://cses.fi/problemset/task/1193/ .
    L (left), R (right), U (up) and D (down)

    Sample input
    
    5 8
    ########
    #.A#...#
    #.##.#B#
    #......#
    ######## 

    Output
    YES
    9
    LDDRRRRRU
*/
#include <bits/stdc++.h>
using namespace std;
 
#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
 
void Sachit0007();
 
int main()
{
    fastio();
 
    int t=1;
 
    auto start = chrono::high_resolution_clock::now();
    while (t--) Sachit0007();
    auto end = chrono::high_resolution_clock::now();
 
    cerr << "\nTime: "
         << chrono::duration<double, milli>(end - start).count()
         << " ms\n";
 
    return 0;
}
 
void bfs(std::vector<std::vector<char>> &graph , std::pair<int,int> &source , std::pair<int,int> &dest){
    int n = graph.size() , m = graph[0].size();
    std::vector<std::vector<bool>> used(n , std::vector<bool>(m , 0));
    used[source.first][source.second] = 1;
    std::vector<std::vector<char>> parent(n , std::vector<char>(m , ' '));
    std::queue<std::pair<int,int>> q;
    q.push(std::make_pair(source.first , source.second));
    std::pair<int,int> vertex;
    int i , j;
    while(!q.empty()){
        vertex = q.front();
        q.pop();
        i = vertex.first; j = vertex.second;
        if (i == dest.first && j == dest.second)
            break;
 
        if (i-1 >= 0 && graph[i-1][j] == '.' && !used[i-1][j]){
            used[i-1][j] = 1;
            parent[i-1][j] = 'U';
            q.push(std::make_pair(i-1 , j));
        }
 
        if (i+1 < n && graph[i+1][j] == '.' && !used[i+1][j]){
            used[i+1][j] = 1;
            parent[i+1][j] = 'D';
            q.push(std::make_pair(i+1 , j));
        }
 
        if (j+1 < m && graph[i][j+1] == '.' && !used[i][j+1]){
            used[i][j+1] = 1;
            parent[i][j+1] = 'R';
            q.push(std::make_pair(i , j+1));
        }
 
        if (j-1 >= 0 && graph[i][j-1] == '.' && !used[i][j-1]){
            used[i][j-1] = 1;
            parent[i][j-1] = 'L';
            q.push(std::make_pair(i , j-1));
        }
 
    }
 
    i = dest.first;
    j = dest.second;
    std::vector<char> ans;
    while((i != source.first || j != source.second)){
        ans.push_back(parent[i][j]);
        if (parent[i][j] == 'L')
            ++j; 
        else if (parent[i][j] == 'R')
            --j;
        else if (parent[i][j] == 'D')
            --i;
        else if (parent[i][j] == 'U')
            ++i;
        else
            break;
    }
 
    if (i == source.first && j == source.second){
        cout << "YES" << endl;
        int sz = ans.size();
        cout << sz << endl;
        for (int i = sz-1 ; i >= 0 ; --i) 
            cout << ans[i];
        cout << endl;
    }
    else 
        cout << "NO" << endl;
 
}
 
void Sachit0007(){
    int n , m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> graph(n , std::vector<char>(m , ' '));
    std::pair<int,int> source , dest;
    for (int i = 0; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j){
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                source.first = i;
                source.second = j;
                graph[i][j] = '.';
            }
            if (graph[i][j] == 'B'){
                dest.first = i;
                dest.second = j;
                graph[i][j] = '.';
            }
        } 
 
    bfs(graph , source , dest);
 
}
