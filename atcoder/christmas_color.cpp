#include <bits/stdc++.h>
using namespace std;
int rows, cols;
int idComp = 0;

int axisX[] = {0,1,0,-1};
int axisY[] = {1,0,-1,0};

bool isSafe(int& x, int& y){
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

void dfs(vector<string>& graph, vector<vector<bool>>& visited, vector<vector<int>>& idComponent, int x,int y){
    visited[x][y] = true;
    idComponent[x][y] = idComp;
    for(int i = 0; i  < 4; ++i){
        int nx = x + axisX[i];
        int ny = y + axisY[i];
        if(isSafe(nx,ny) && graph[nx][ny] == '#' && !visited[nx][ny]){
            dfs(graph, visited, idComponent, nx,ny);
        }
    }
}

int main(){

    cin >> rows >> cols;
    vector<string> graph;
    graph.assign(rows, "....");
    vector<vector<bool>> visited;
    visited.assign(rows, vector<bool>(cols, false));
    vector<vector<int>> idComponent;
    idComponent.assign(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; ++i){
        cin >> graph[i];
    }

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(graph[i][j] == '#' && !visited[i][j]){
                dfs(graph, visited,idComponent, i, j);
                idComp++;
            }
        }
    }

    // for(int i = 0; i < graph.size(); i++)
    // {
    //     cout << graph[i] << endl;
    // }
    // for(int i = 0; i < graph.size(); i++){
    //     for(int j = 0; j < cols; ++j){
    //         cout << visited[i][j];
    //     }
    //     cout << endl;
    // }


    // cout << "componentes #: "<< idComp << endl;

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            set<int> myAddedComponent;
            if(graph[i][j] == '.'){
                for(int k = 0; k < 4; ++k){
                    int nx = i + axisX[k];
                    int ny = j + axisY[k];
                    if(isSafe(nx,ny) && graph[nx][ny] == '#'){
                        // cout << "idComp: "<<idComponent[nx][ny] << endl;
                        myAddedComponent.insert(idComponent[nx][ny]);
                    }
                }
                int r = idComp - (myAddedComponent.size() -1);
                // cout <<"idComponents: "<<idComp<< " i,j: "<<i<<","<<j<<" myAddedComponents: "<<myAddedComponent.size()<<" r: "<<r << endl;
            }
        }
    }
    
    // cout << "ic: "<<idComp << " "<< endl;
    // for(int i = 0; i < graph.size(); i++)
    // {
    //     cout << graph[i] << endl;
    // }
    // for(int i = 0; i < graph.size(); i++){
    //     for(int j = 0; j < cols; ++j){
    //         cout << visited[i][j];
    //     }
    //     cout << endl;
    // }

    

}