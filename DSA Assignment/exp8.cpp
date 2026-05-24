#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int val;

    Node(int v){
        val = v; left = NULL; right = NULL; 
    }
};

static int comparisons = 0;

Node* insert(Node* root , int key){

    if(root == NULL) return new Node(key);

    comparisons++;

    if(key < root->val ){

        comparisons++;

        root->left = insert(root->left , key);

    }else{

        comparisons++;
        root->right = insert(root->right , key);
    }

return root;
}
Node* construct_BST(vector<int> arr){

    Node* root = NULL;

    for(int val: arr){
        root = insert(root, val);
    }

    cout<<"total comparisons : "<<comparisons<<endl;
return root;
}

//SC O(N)
vector<int> remove_dublicate(vector<int> arr){
    unordered_map<int , int> m;
    vector<int> ans;

    for(int i=0; i<arr.size();i++){

        if(m.find(arr[i])  == m.end()){
            m[arr[i]]++;
            ans.push_back(arr[i]);
        }
        
    }

return ans;
}

// sort with const SC
int remove_dublicates_with_const_SC(vector<int> &arr){

    sort(arr.begin() , arr.end());

    int j=0;

    for(int i=1; i<arr.size(); i++){

        if(arr[i]!=arr[j]){
            j++;
            arr[j] = arr[i];
        }

    }
return j+1;
}

int main(){
    
    vector<int> arr = {14, 10, 17, 12, 10, 11, 20, 12, 18, 25, 20, 8, 22, 11, 23};

    construct_BST(arr);

    vector<int> ans = remove_dublicate(arr);
    
    for(int val: ans){
        cout<<val<<" ";
    }

    cout<<endl;

    int newSize = remove_dublicates_with_const_SC(arr);

    for(int i=0; i<newSize; i++){
        cout<<arr[i]<<" ";
    }

    
return 0;
}