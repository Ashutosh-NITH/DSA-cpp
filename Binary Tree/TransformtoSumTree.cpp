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

int toSumTree(Node* root){ 

   if(root==NULL) return 0;
        
    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    if(root->left == NULL && root->right == NULL){
        int currval = root->data;
        root->data = 0;
    return currval;

    }else{
        root->data = root->data + leftSum + rightSum;
    return root->data;
    
    }
          
}


int main(){

    vector<int> preOrder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder); 

    preOrder_traversal(root);
    cout<<endl;
    cout<<toSumTree(root);
    cout<<endl;
    preOrder_traversal(root);
    
    return 0;
}