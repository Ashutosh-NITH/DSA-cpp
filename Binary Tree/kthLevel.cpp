#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

static int idx = -1;

Node* buildTree(vector<int> &preOrder){ // TC => O(n)

    idx++;

    if(preOrder[idx]==-1) return NULL;

    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);

    root->right = buildTree(preOrder);

return root;
}


void kthLevel(Node* root , int k){ // TC =>O(n)

    if(root==NULL) return;

    if(k==1) {
        cout<<root->data<<" ";
        return;
    }
    kthLevel(root->left , k-1);
    kthLevel(root->right , k-1);
}

int main(){

    vector<int> preOrder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder); 
    
    kthLevel(root , 3);

    return 0;
}