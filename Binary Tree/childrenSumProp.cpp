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

void preOrder_traversal(Node* root){ // TC => O(n)

    if(root == NULL) return;

    cout<<root->data<<" ";

    preOrder_traversal(root->left);
    preOrder_traversal(root->right);

}

bool isLeaf(Node* node){
    return (node->left==NULL )&&( node->right==NULL );
}

void childrenSum(Node* root){ 
    int child = 0;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }
    if(child>=root->data){
        root->data = child;
    }else{
        root->left->data = root->data;
        root->right->data = root->data;
    }

    childrenSum(root->left);
    childrenSum(root->right);

    int total = 0;
    if(root->left){
        total+=root->left->data;
    }
    if(root->right){
        total+=root->right->data;
    }
    if(!isLeaf(root)) root->data = total;
          
}


int main(){

    vector<int> preOrder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder); 

    
    return 0;
}