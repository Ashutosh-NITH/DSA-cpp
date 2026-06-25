#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//shortest path on DAG topo sort 

void dfs(int node ,vector<bool> &vis, stack<int> &s,vector<vector<pair<int,int>>> &adj){
    vis[node] = true;

    for(auto edge: adj[node]){
        int neigh = edge.first;
        if(!vis[neigh]) dfs(neigh , vis , s, adj);
    }
s.push(node);
}

vector<int> shortestPathDAG(int src , vector<vector<pair<int,int>>> &adj){
    int n = adj.size();
    vector<bool> vis(n, false);
    stack<int> s;

    for(int i=0; i<n; i++){
        if(!vis[i]) dfs(i , vis , s, adj);
    }

    vector<int> dist(n , 1e9);

    dist[src] = 0;

    while(!s.empty()){
        int curr = s.top();
        s.pop();

        if(dist[curr] == 1e9) continue;

        for(auto edge :  adj[curr]){

            int neigh = edge.first;
            int w = edge.second;

            if(dist[curr] + w < dist[neigh]){
                dist[neigh] = dist[curr]+w;
            }
        }
    }

return dist;
}

int main() {

    int V = 7;
    vector<vector<pair<int,int>>> adj(V);

    adj[6].push_back({4, 2});
    adj[6].push_back({5, 3});

    adj[5].push_back({4, 1});

    adj[4].push_back({0, 3});
    adj[4].push_back({2, 1});

    adj[0].push_back({1, 2});

    adj[1].push_back({3, 1});

    adj[2].push_back({3, 3});


    vector<int> ans = shortestPathDAG( 6 , adj) ;
    for(int x: ans){
        cout<<x<<" ";
    }
    return 0;
}
