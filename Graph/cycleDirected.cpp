#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node ,vector<vector<int>> &adjL,vector<bool> &vis,vector<bool> &pathVis){

    vis[node] = true;
    pathVis[node] = true;

    for(int neigh: adjL[node]){

        if(!vis[neigh]) {

            if(dfs(neigh, adjL, vis, pathVis)) return true;

        }else if(pathVis[neigh]){
            return true;
        }
    }

    pathVis[node] = false;

return false;
}


bool cycleDirectedDFS(vector<vector<int>> &adjL){

    int v = adjL.size();
    vector<bool> vis(v , false);
    vector<bool> pathVis(v , false);

    for(int i=0; i<v; i++){
       if(!vis[i]) if(dfs(i ,adjL , vis , pathVis)) return true;
    }
return false;
}

int main(){

const int n = 5;
vector<vector<int>> adjL(n);

// Directed edges
adjL[0].push_back(1);
adjL[1].push_back(2);
adjL[2].push_back(3);
adjL[3].push_back(4);

// Create a cycle: 1 -> 2 -> 3 -> 1
adjL[3].push_back(1);

    cout<<cycleDirectedDFS(adjL)<<endl;
    return 0;
}