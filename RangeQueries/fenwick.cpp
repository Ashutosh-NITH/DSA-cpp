#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class FenwickTree{

    vector<int> bit;
    int n;
public:
    FenwickTree(vector<int> &arr){
        n = arr.size();
        bit.resize(n+1, 0); 

        for (int i = 0; i < n; i++) {
            update(i + 1, arr[i]); // Fenwick Tree uses 1-based indexing
        }
    }

    void update(int i , int val){

        while(i<=n){
            bit[i] += val;

            i = i + (i&-i);
        }
    }

    // returns sum from (1 , i)

    int prefixSum(int i){

        int sum = 0;

        while(i>0){
            sum += bit[i];

            i = i - (i&-i);
        }
        return sum;
    }
    int rageQuery(int l , int r){

        return prefixSum(r) - prefixSum(l-1);
    }
};

int main(){

    int n = 5;

    vector<int> arr = {1, 2, 3, 4, 5};
    FenwickTree ft( arr);

    cout << ft.prefixSum(3) << "\n";   // 1+2+3 = 6
    cout << ft.rageQuery(2, 4) << "\n"; // 2+3+4 = 9

    ft.update(3, 5); // arr[3] += 5

    cout << ft.rageQuery(1, 5) << "\n"; // 20
}