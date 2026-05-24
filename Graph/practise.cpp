#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int v){
        V=v;
        l = new list<int>[V];
    }


    void addEdge(int a , int b){

        l[a].push_back(b);
        l[b].push_back(a);
    }

    void print_Adjacency_List(){

        for(int i=0; i<V; i++){

            cout<<i<<" : ";

            for(int neigh: l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(){

        queue<int> q;
        vector<int> visited(V, false);

        q.push(0);
        visited[0]=true;
        cout<<"BFS : ";

        while (q.size()>0){    

            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            for (int neigh: l[curr]){

                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh]=true;
                }
            }  
        }
        cout<<endl;   
    }

    void DFShelper(int node , vector<int> &visited ){

        cout<<node<<" ";
        visited[node] = true;

        for (int neigh: l[node]){

                if(!visited[neigh]){
                   DFShelper(neigh, visited);
                }
            }  
    }

    void DFS(){

        cout<<"DFS : ";
        vector<int> visited(V, false);
        DFShelper(0, visited);
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
}