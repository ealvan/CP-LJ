#include <bits/stdc++.h>
using namespace std;


void dfs(const vector<vector<int>>& graf,vector<bool>& vertices, int v, int& nodes){
    cout << v+1 << " -> ";
    vertices[v] = true;
    nodes++;
    for(int j = 0; j < graf[v].size(); ++j){
        if(graf[v][j] == 1){
            if(!vertices[j]){
                dfs(graf, vertices, j, nodes);
            }
        }
    }
}

int main(){
    vector<vector<int>> graf = {
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 0, 0},
        {1, 1, 0, 0}
    };
    int cont = 0;
    vector<bool> vertices = {0,0,0,0};
    for(int v = 0; v < vertices.size(); ++v){
        int nodes = 0;
        if(!vertices[v]){
            dfs(graf, vertices, v, nodes);
            cont++;
            cout << "Componente "<<cont << " nodos: " << nodes << endl;
        }
    }
    cout << endl;
    cout << "Componentes: "<< cont << endl;

}