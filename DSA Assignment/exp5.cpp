#include<iostream>
#include<vector>
using namespace std;

/* ==================================================
   MERGE SORT
   TC: O(N log N), SC: O(N)
====================================================== */
void merge(vector<int> &arr, int l, int mid, int r) {
    vector<int> temp;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[l + k] = temp[k];
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    vector<int> arr={351, 285, 310, 254, 179, 861, 423, 652, 450, 520};

    for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;

    mergeSort(arr, 0 , arr.size()-1);
    
    for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}