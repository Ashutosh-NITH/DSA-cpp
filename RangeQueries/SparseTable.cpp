#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

class SparseTable{
private:
    vector<vector<int>> table;
    int k; // log2 of array size
    int n; // array size
public:
    SparseTable(vector<int> arr){
        n = arr.size();
        k = log2(n) ; // dont use this 
        // k = bit_width(n)-1; // constant time ... dont use log2

        table.resize(n , vector<int>(k+1));

        for(int i=0; i<n; i++) table[i][0] = arr[i];

        for(int j=1; j<=k; j++){

            for(int i=0; i + (1<<j) <= n ; i++){

                table[i][j] = min(table[i][j-1] , table[i+(1<<(j-1))][j-1] );
            }
        }

    }
    int query(int l , int r){
        int len = r-l+1;
        int k = log2(len); // dont use this
        // int k = bit_width(len)-1; // use this -> constant time

        return min( table[l][k], table[r-(1<<k)+1][k] );
    }
};

int main(){
    vector<int> arr = {7,2,0,3,10,5,10,18};
    SparseTable t(arr);
    cout << t.query(0,0) << endl;
    cout << t.query(0,1) << endl;
    cout << t.query(0,3) << endl;
    cout << t.query(2,5) << endl;
    cout << t.query(4,7) << endl;
    cout << t.query(5,6) << endl;
    cout << t.query(6,7) << endl;
    // 7
    // 2
    // 0
    // 0
    // 5
    // 5
    // 10
    return 0;
}