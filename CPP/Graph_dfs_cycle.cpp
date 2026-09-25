#include <bits/stdc++.h>
using namespace std;

int dfs(int s , vector <int> &used , vector <vector <int>> &graph , int p);

int main()
{
    int nodes , k;
    cin >> nodes >> k;
    
    vector <vector <int >> graph(nodes  + 1);

    for (int i = 0;i < k; i++){
        int v1 , v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    int ans = 0 , cnt = 0;
    vector <int> used(nodes+1 , 0);
    for (int i = 1 ; i <= nodes ; i++){
        if (used[i] ==0){
            ans++;
            int val = dfs(i ,used , graph , -1);
            if (val == 1){cnt++;}
        }
    }

    cout << "Number of cycles are :" << cnt << endl;
    cout << "Number of different nodes not connected :" << ans << endl;
        
    return 0;
}

int dfs(int s , vector <int> &used , vector <vector <int>> &graph , int p){
    used[s] = 1;


    for (int child : graph[s]){
        if (child == p) continue;
        else if (!used[child]){
            if (dfs(child , used , graph , s)) return 1;
        }
        else{
            return 1;
        }

    }
    return 0;
}
