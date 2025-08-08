#include<iostream>
#include<vector>
using namespace std;

//SC => O(n)
//TC => O(nlogn) => avg / practical cases
//TC => O(n^2) => worst case => when pivot element is largest or smallest

int pivot(vector<int> &vec , int st , int end){
    int piv = vec[end];
    int idx = st-1;

    for( int j=st; j<end; j++){

        if(vec[j]<=piv){

            idx++;

            swap(vec[j] , vec[idx]);
        }

    }

    idx++;
    
    swap(vec[idx], vec[end]);

    return idx;
}

void QuickSort(vector<int> &vec, int st , int end){

    if(st<end){

        int pivIdx = pivot(vec, st , end);

        QuickSort(vec , st , pivIdx-1); //left half

        QuickSort(vec , pivIdx+1 , end); //right half

    }
}


int main(){
    
    vector<int> vec1 = {6,8,0,1,3};
    vector<int> vec = {12,31,35,8,32,17};

    QuickSort(vec, 0 , vec.size()-1);
    
    for(int val : vec){
        cout<<val<<" ";
    }

    return 0;
}