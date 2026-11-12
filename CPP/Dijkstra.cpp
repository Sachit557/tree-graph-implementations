/*  
    Dijkstra's Shortest Path Algorithm using an adjacency list and ordered set . ordered set is used to get the node with lowest weight (can be swapped for a priority queue).
    Finds shortest distances from a source vertex in a weighted graph with non-negative edge weights.
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

void Dijkstra(std::vector<std::vector<std::pair<int,int>>> &graph , int u , int v){
    // u to v
    std::priority_queue<std::pair<int,int> , std::vector<std::pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0 , u});
    std::vector<int> dist(graph.size() , INT_MAX);
    dist[u]=0;

    std::pair<int,int> vertex ;int wt;
    while(!pq.empty()){
        vertex = pq.top();
        pq.pop();

        if (vertex.first != dist[vertex.second])  // it may have multiple entries of weight of same node . so if an entry in pq is outdated we dont consider it again
            continue;

        if (vertex.second == v) // shortest distance to v is found so we can break early
            break;
        
        for (auto child : graph[vertex.second]){
            if (dist[vertex.second]+child.second < dist[child.first]){
                dist[child.first]=dist[vertex.second]+child.second;
                pq.push({dist[child.first] , child.first});
            }
        }

    }

    cout << dist[v] << endl;
}

void Sachit0007(){
    int n , m , w , u , v;
    cin >> n >> m;
    std::vector<std::vector<std::pair<int,int>>> graph(n+1);    
    for (int i = 0 ; i < m ; ++i){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    // finding shorted distance between 1 and 6
    Dijkstra(graph , 1 , 6);
}

