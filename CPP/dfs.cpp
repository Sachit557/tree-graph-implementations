#include <bits/stdc++.h>
using namespace std;

void dfs(int s , vector <int> &used , vector <vector <int>> &graph);


int main(){
    int nodes , k;
    cin >> nodes >> k;
    
    vector <vector <int >> graph(nodes  + 1);

    for (int i = 0;i < k; i++){
        int v1 , v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    // dfs
        
    return 0;
}

void dfs(vector<vector<int>> &graph, vector<int> &used, int start){
    stack<int> st;
    st.push(start);

    while (!st.empty()){
        int vertex = st.top();
        st.pop();

        if (used[vertex])
            continue;

        used[vertex] = 1;
        cout << vertex << endl;

        for (int child : graph[vertex])
            if (!used[child])
                st.push(child);
            
    }
}

void dfs(int s , vector <int> &used , vector <vector <int>> &graph) {
    used[s] = 1;
    for (int child : graph[s]){
        if (!used[child]){
            dfs(child , used , graph); 
        }
    }
}

