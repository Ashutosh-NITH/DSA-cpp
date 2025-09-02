#include<iostream>
#include<vector>
#include<list>
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
};


int main(){
    
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.print_Adjacency_List();
    return 0;
}