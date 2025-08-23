#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
       data = val;
       left = right = NULL; 
    }
};

Node* insert( Node* root , int val ){

    if(root==NULL) {
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left , val); 
    }else{
        root->right = insert(root->right , val); 
    }
    
return root;  
}

Node* buildTree( vector<int> &vec ){
    Node* root = NULL;

    for(int val : vec){
        root = insert( root , val );
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildTree(arr);

    inorder(root);
    
    return 0;
}