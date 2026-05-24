#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class DisjointSet{
    vector<int> rank , parent , size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }

    int ultimateParent(int node){

        if(parent[node]==node) return node;

        return parent[node] = ultimateParent(parent[node]);
    }

    void unionByRank(int a , int b){

        int pa = ultimateParent(a);
        int pb = ultimateParent(b);

        if(pa == pb) return;

        if(rank[pa]>rank[pb]){

            parent[pb] = pa; 

        }else if(rank[pa]<rank[pb]){

            parent[pa] = pb;

        }else{

            parent[pa] = pb;
            rank[pb]++;
        }
    }

    void  unionBySize(int a , int b){

        int pa = ultimateParent(a);
        int pb = ultimateParent(b);

        if(pa == pb) return;

        if(size[pa]>size[pb]){

            parent[pb] = pa;
            size[pa]+=size[pb];

        }else{

            parent[pa] = pb;
            size[pb]+=size[pa];
        }
    }
};

int main(){

    DisjointSet ds(7);

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.ultimateParent(7)==ds.ultimateParent(3)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }

    ds.unionBySize(3,7);

    if(ds.ultimateParent(7)==ds.ultimateParent(3)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }
    return 0;
}