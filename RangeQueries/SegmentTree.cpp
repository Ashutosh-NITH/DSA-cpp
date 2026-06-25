#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class SegmentTree{
private:
    vector<int> seg;
    int n;

    void build(int idx , int low , int high, vector<int> &arr){ // TC 4n

        if(low==high){
            seg[idx] = arr[low];
            return;
        }
        int mid = low + (high-low)/2;
        
        build(2*idx+1  , low , mid , arr);
        build(2*idx+2  , mid+1 , high , arr);

        seg[idx] = min(seg[2*idx+1] , seg[2*idx+2]);
        return;
    }

public:
    SegmentTree(vector<int> arr){
        n = arr.size();
        seg.resize(4*n);  // SC 4n
        build(0 , 0 , n-1 , arr);
    }
    void updateHelper(int idx, int low, int high, int pos, int val) {

        if(low == high) {
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if(pos <= mid)
            updateHelper(2 * idx + 1, low, mid, pos, val);
        else
            updateHelper(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int pos, int val) {
        updateHelper(0, 0, n - 1, pos, val);
    }
    
    int queryHelper(int idx , int low , int high , int left , int right){
        
        if(low >= left && high <= right)    return seg[idx]; // complete overlap
        if(left>high || right<low) return INT_MAX; // no overlap

        int mid = low + (high-low)/2; // partial overlap
        int leftAns = queryHelper(2*idx+1  , low , mid , left , right);
        int rightAns = queryHelper(2*idx+2  , mid+1  , high , left , right);
    
    return min(leftAns , rightAns);
    }

    int query(int left , int right){ // logn TC

        return queryHelper(0 , 0 ,n-1 , left , right);
    }
};

int main(){ 
    vector<int> arr = {7,2,0,3,10,5,10,18};
    SegmentTree t(arr);

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