#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;

class sqrtDecomp{
private:

    int n;
    int rootN;
    vector<int> arr;
    vector<int> blocks;

    void build(){
        for(int i=0; i<n; i++){

            blocks[i/rootN] += arr[i];
        }
    }
public:
    sqrtDecomp(vector<int> a){
        n = a.size();
        arr = a;
        rootN = ceil(sqrt(n));
        blocks.resize(rootN+1 , 0);

        build();
    }

    int query(int l , int r){

        int ans = 0;

        while(l%rootN!=0 && l<r){ // left part -> add individual elements
            ans+=arr[l];
            l++;
        }

        while(l+rootN - 1<=r){ // middle part -> take entire block sum
            ans+=blocks[l/rootN];
            l+=rootN;
        }

        while (l<=r){
            ans+=arr[l];
            l++;
        }
    return ans;
    }

    void update(int idx , int val){
        blocks[idx/rootN] = blocks[idx/rootN] - arr[idx] + val;
        arr[idx] = val;
    }

};

int main(){
    vector<int> arr = {7,2,0,3,10,5,10,18};
    sqrtDecomp sqrtD(arr);
    cout<<sqrtD.query(3,7)<<endl;
    return 0;
}