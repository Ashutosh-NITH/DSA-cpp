#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
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

void iterative_preorder(Node* root){

    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* curr = s.top();
        s.pop();
        cout<<curr->data<<" ";

        
        if(curr->right!=NULL){ // first right
            s.push(curr->right);
        }
        if(curr->left!=NULL){
            s.push(curr->left);
        }
    }
}

void iterative_inorder(Node* root){

    stack<Node*> s;
    Node* node = root;
    while(1){
        if(node!=NULL){
            s.push(node);
            node = node->left;
        }else{
            if(s.empty()) break;
            Node* curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            node = curr->right;
        }
    }
}

void iterative_postorder_2stack(Node* root){

    stack<Node*> s;
    stack<Node*> ans;
    s.push(root);

    while (!s.empty()){
        Node* curr = s.top();
        s.pop();
        ans.push(curr);

        if(curr->left!=NULL) s.push(curr->left);
        if(curr->right!=NULL) s.push(curr->right);
    }
    while (!ans.empty()){
        cout<<ans.top()->data<<" ";
        ans.pop();
    }
}

void iterative_postorder_1stack(Node* root){
    stack<Node*> s;
    Node* curr = root;
    while (!s.empty() || curr!=NULL){
        if(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }else{  
            Node* temp = s.top()->right;
            if(temp==NULL){
                temp = s.top();
                s.pop();
                cout<<temp->data<<" ";
                while (!s.empty() && s.top()->right==temp){
                    temp = s.top();
                    s.pop();
                    cout<<temp->data<<" ";
                }
            }else{
                curr=temp;
            }
        }
    }    
}

void iterative_all_in_one(Node* root){
    stack<pair<Node* , int>> s;
    vector<Node*> preOrder;
    vector<Node*> inOrder;
    vector<Node*> postOrder;
    s.push({root , 1});
    while(!s.empty()){
        auto it = s.top();
        Node* node = it.first;
        int num = it.second;
        s.pop();
        if(num==1){
            preOrder.push_back(node);
            s.push({node , 2});
            if(node->left!=NULL) s.push({node->left , 1});
        }else if(num==2){
            inOrder.push_back(node);
            s.push({node , 3});
            if(node->right!=NULL) s.push({node->right , 1});
        }else{
            postOrder.push_back(node);
        }
    }
    cout<<endl<<"PreOrder"<<endl;
    for(auto x: preOrder) cout<<x->data<<" ";
    cout<<endl<<"InOrder"<<endl;
    for(auto x: inOrder) cout<<x->data<<" ";
    cout<<endl<<"PostOrder"<<endl;
    for(auto x: postOrder) cout<<x->data<<" ";
    
}
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
    // iterative_preorder(root);
    // cout<<endl;
    // inOrder_traversal(root);
    // cout<<endl;
    // iterative_inorder(root);
    // cout<<endl;
    // postOrder_traversal(root);
    // cout<<endl;
    // iterative_postorder_2stack(root);
    // cout<<endl;
    // iterative_postorder_1stack(root);
    // cout<<endl;
    // iterative_all_in_one(root);
    // normal_levelOrder_traversal(root);
    // cout<<endl;
    // levelOrder_traversal(root);
    // cout<<endl;
    // cout<<height(root);
    // cout<<endl;
    // cout<<height_2(root);
    // cout<<endl;
    // cout<<countNodes(root);
    // cout<<endl;
    // cout<<sumOfNodes(root);
    return 0;
}