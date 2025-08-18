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

static int idx = -1;

Node* buildTree(vector<int> &preOrder){ // TC => O(n)

    idx++;

    if(preOrder[idx]==-1) return NULL;

    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);

    root->right = buildTree(preOrder);

return root;
}







// Traversal => total = 4 
// 3 => recursion based => DFS
// 1 => iterator based = level order => BFS

void preOrder_traversal(Node* root){ // TC => O(n)

    if(root == NULL) return;

    cout<<root->data<<" ";

    preOrder_traversal(root->left);
    preOrder_traversal(root->right);

}

void inOrder_traversal(Node* root){ // TC => O(n)

   if(root==NULL) return;

   inOrder_traversal(root->left);

   cout<<root->data<<" ";

   inOrder_traversal(root->right);

}

void postOrder_traversal(Node* root){ // TC => O(n)

    if(root==NULL) return;

    postOrder_traversal(root->left);

    postOrder_traversal(root->right);

    cout<<root->data<<" ";

}


//Level Order Search (iterative) => BFS

void normal_levelOrder_traversal(Node* root){ //TC =>O(n)

    queue<Node*> q;

    q.push(root);

    while(q.size()>0){

        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";

        if (curr->left!=NULL ){
            q.push(curr->left);
        }
        if (curr->right!=NULL ){
            q.push(curr->right);
        }
        
    }
    
}

void levelOrder_traversal(Node* root){ //TC =>O(n) & SC =>O(n)

    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    

    while(q.size()>0){

        Node* curr = q.front();
        q.pop();

        if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }

        cout<<curr->data<<" ";

        if (curr->left!=NULL ){
            q.push(curr->left);
        }
        if (curr->right!=NULL ){
            q.push(curr->right);
        }
        
    }
    
}


int height(Node* root){ // post order traversal // TC => O(n)

    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (max(leftHeight , rightHeight) + 1 ); 

}


int height_2(Node* root){ // level order traversal //TC =>O(n) & SC =>O(n))

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int count = 1;
    
    while(q.size()>0){

        Node* curr = q.front();
        q.pop();

        if(curr==NULL){

            if(!q.empty()){
                count++;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }

        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }

return count;
}

int countNodes(Node* root){ // post order traversal // TC => O(n)

    if(root==NULL) return 0;

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

return (leftCount+rightCount+1);
}

int sumOfNodes(Node* root){ // post order traversal // TC => O(n)

    if(root==NULL)  return 0;

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

return (leftSum + rightSum + root->data);

}

int main(){

    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder); 
    // preOrder_traversal(root);
    // cout<<endl;
    // inOrder_traversal(root);
    // cout<<endl;
    // postOrder_traversal(root);
    // cout<<endl;
    // normal_levelOrder_traversal(root);
    // cout<<endl;
    // levelOrder_traversal(root);
    // cout<<endl;
    // cout<<height(root);
    // cout<<endl;
    // cout<<height_2(root);
    // cout<<endl;
    cout<<countNodes(root);
    cout<<endl;
    cout<<sumOfNodes(root);
    return 0;
}