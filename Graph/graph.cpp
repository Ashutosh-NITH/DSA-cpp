#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

// vertices symbol -> V
// Edges symbol - E

// Adjacency List => store neighbors for all V 

class Graph{
    int V;
    list<int> *l; // just like int *arr // dynamic array

public:

    Graph(int size){
        V = size;
        l = new list<int> [V];
    }

    void addEdge(int u ,int v){
        l[u].push_back(v);
        l[v].push_back(u);

    }

    void print_Adjacency_List(){

        for(int i=0; i<V; i++){

            cout<<i<<" : ";

            for(int neigh: l[i] ){
                cout<<neigh<<" ";
            }

            cout<<endl;
        }
    }

    // BFS => travel to immediate neighbors first 

    void BFS(){ // TC => O(V+E)

        queue<int> q;
        vector<bool> vis(V,false);

        q.push(0);
        vis[0] = true;

        cout<<"BFS : ";

        while (q.size()>0){

            int u = q.front();
            q.pop();
            cout<<u<<" ";

            for(int v : l[u]){ // v ->immediate neighbours

                if(vis[v]==false){

                    vis[v] = true;
                    q.push(v); 
                }
            }
        }

        cout<<endl;
        
        
    }


    // DFS => keep going to first uvisited neighbour

    void DFShelper(int src , vector<bool> vis){

        cout<<src<<" ";
        vis[src] = true;

        for(int v : l[src]){

            if(!vis[v]){
                DFShelper(v , vis);
            }
        }


    }

    void DFS(){
        int src = 0;
        vector<bool> vis (V, false);

        cout<<"DFS"<<" : ";

        DFShelper(src , vis);

        cout<<endl;
    }
};


int main(){
    
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.print_Adjacency_List();
    g.BFS();
    g.DFS();
    return 0;
}