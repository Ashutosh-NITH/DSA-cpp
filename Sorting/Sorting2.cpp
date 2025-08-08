#include<iostream>
#include<vector>
using namespace std;


//TC =>O(N)

void  Merge (vector<int> &vec , int st, int mid , int end){

    int i=st ;
    int j=mid+1;
    vector<int> temp;

    while(i<=mid && j<=end){

        if(vec[i]<=vec[j]){
            temp.push_back(vec[i]);
            i++;
        }else{
            temp.push_back(vec[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(vec[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(vec[j]);
        j++;
    }

    for(int idx = 0; idx < temp.size(); idx++){
        vec[st+idx] = temp[idx];
    }
}

void MergeSort(vector<int> &vec, int st , int end){

    if(st<end){

        int mid = st + (end-st)/2;
        
        MergeSort(vec, st , mid); //left part

        MergeSort(vec, mid+1, end); //right part

        Merge(vec, st,  mid, end);
    }

}


int main(){
    
    vector<int> vec1 = {6,8,0,1,3};
    vector<int> vec = {12,31,35,8,32,17};

    MergeSort(vec , 0 , vec.size()-1);
    
    for(int val : vec){
        cout<<val<<" ";
    }

    return 0;
}