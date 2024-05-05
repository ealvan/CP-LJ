#include <bits/stdc++.h>
using namespace std;

void dfs(int init, vector<bool>& visited, const vector<vector<int>>& graf){
    cout << init << " -> ";
    visited[init] = true;
    for(int child: graf[init]){
        if(!visited[child]) 
            dfs(child, visited, graf);
    }
}


int main(){
    int n = 0,c = 0;
    cin >> n >> c;
    vector<vector<int>> graf(n, vector<int>());
    int a,b;
    for(int i = 0; i < c; ++i){
        cin >> a >> b;
        graf[a-1].push_back(b-1);
        graf[b-1].push_back(a-1);
    }
    for(int i = 0; i < n; ++i){
        printf("[%d] -> ", i);
        for(int j = 0; j < graf[i].size(); ++j){
            cout << graf[i][j] << " -> ";
        }
        cout << endl;
    }
    vector<bool> visited(n, false);
    int start = 0;
    dfs(start, visited, graf);
    cout << " fin" << endl;
}