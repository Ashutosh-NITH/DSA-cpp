#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void PrimsAlgo(vector<vector<pair<int , int>>> &adjL , int n, int e){


    priority_queue< pair<int , int> ,  vector<pair<int , int>>  , greater<pair<int , int>>> pq; // weight(first) , Node 
    //sorted with minimum weight (first)

    vector<int> key(n , 1e9); // contains min weight of vertice connecting to mst // initially with inifinty weight to each node
    vector<bool> visited(n , false);

    key[0] = 0;

    pq.push({0,0});

    int totalCost = 0;

    while(!pq.empty()){

        int curr = pq.top().second;
        pq.pop();

        if(visited[curr]) continue; // very imp

        visited[curr] = true;
        totalCost+=key[curr];

        for(auto &p: adjL[curr]){
            
            int v = p.first;
            int w = p.second;

            if(!visited[v] && w<key[v]){
                pq.push({w , v});
                key[v] = w;
            }
        }

    }

    cout<<"Total Cost : "<<totalCost<<endl;
}


int main(){

    int v = 5;

    int e = 8;


    vector< vector<pair<int , int>> > adjL(v);

    // edge , weight



    adjL[0] = { {1,2}, {2,4} };
    adjL[1] = { {0,2}, {2,1}, {3,7}, {4,10} };
    adjL[2] = { {0,4}, {1,1}, {3,5}, {4,6} };
    adjL[3] = { {1,7}, {2,5}, {4,3} };
    adjL[4] = { {1,10}, {3,3}, {2,6} };


    PrimsAlgo(adjL, v, e);

    
return 0;
}