#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//  Topological sorting for Directed Acyclic Graph (DAG)
//  is a linear ordering of vertices such that for every directed edge u -> v,
//  vertex u comes before v in the ordering.

void dfsHelper(int node , vector<int> adjL[] ,vector<bool> &vis , vector<int> &topo){

    vis[node] = true;

    for(int neigh: adjL[node]){
        if(!vis[neigh]) dfsHelper(neigh , adjL , vis , topo);
    }
    topo.push_back(node);
}

vector<int> topologyOrderDFS(vector<int> adjL[] , int v){
    vector<int> topo;
    vector<bool> vis(v, false);

    for(int i=0; i<v; i++){
        if(!vis[i]) dfsHelper(i , adjL , vis , topo);
    }
    reverse(topo.begin(), topo.end());
return topo;
}

vector<int> KahnAlgoBFS(vector<int> adjL[] , int v){ // TC => O(V+E)

    vector<int> indegree(v, 0);
    queue<int> q;
    vector<int> topo;

    for(int i=0; i<v; i++ ){

        for(int x: adjL[i]){
            indegree[x]++;
        }
    }

    for(int i=0; i<v; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(q.size()>0){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int neigh: adjL[node]){

            indegree[neigh]--;

            if(indegree[neigh]==0) q.push(neigh);
        }
    }
return topo;
}


void printAdjacencyList(vector<int> adjL[] , int n ){

    for (int i = 0; i < n; i++) {

        cout << i << " -> ";

        for (int node : adjL[i]) {
            cout << node << " ";
        }

        cout << endl;
    }
}
int main() {

    const int n = 5;
    vector<int> adjL[n];

    // directed edges
    adjL[0].push_back(1);
    adjL[0].push_back(2);
    adjL[1].push_back(3);
    adjL[2].push_back(4);

    // DAG
    //  0
    // /  \
    // 1   2
    // |   |
    // 3   4

    printAdjacencyList(adjL , n);

    // valid on DIRECTED ACYCLIC GRAPH (DAG)

    vector<int> ans1 = KahnAlgoBFS(adjL , n);

    for(int x: ans1) cout<<x<<" ";
    cout<<endl;

    vector<int> ans2 = topologyOrderDFS(adjL , n);

    for(int x: ans2) cout<<x<<" ";
    return 0;
}