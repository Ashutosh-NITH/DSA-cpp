#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool dfshelper(int node , int parent ,vector<vector<int>> &adjL, vector<bool> &vis){

    vis[node] = true;

    for(int neigh: adjL[node]){

        if(neigh!=parent && vis[neigh]==true) return true;
        
        if(!vis[neigh]){
            if( dfshelper(neigh , node , adjL , vis) == true) return true;
        }
    }
return false;
}

bool detectCycleDFS(int src , int par , vector<vector<int>> &adjL){
    int n = adjL.size();
    vector<bool> vis(n , false); 

    return dfshelper(src , par , adjL , vis);
}

bool detectCycleBFS(int src , int par , vector<vector<int>> &adjL){

    int n = adjL.size();

    vector<bool> vis(n , false);

    queue<pair<int,int>> q;

    q.push({src , par});
    vis[src] = true;

    while(q.size()>0){

        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int neigh: adjL[curr]){

            if(neigh!=parent && vis[neigh]==true){
                return true;
            }
            if(!vis[neigh]){
                vis[neigh] = true;
                q.push({neigh , curr});
            }
        }
    }

return false;
}

int main(){
    int n = 5;
    vector<vector<int>> adjL(n);

    // undirected edges
    adjL[0].push_back(1);
    adjL[1].push_back(0);

    adjL[0].push_back(2);
    adjL[2].push_back(0);

    adjL[1].push_back(3);
    adjL[3].push_back(1);

    adjL[2].push_back(4);
    adjL[4].push_back(2);
    adjL[3].push_back(4);
    adjL[4].push_back(3);
    cout<<detectCycleBFS( 0 , -1 , adjL )<<endl;
    cout<<detectCycleDFS( 0 , -1 , adjL )<<endl;
    return 0;
}