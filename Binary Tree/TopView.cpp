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

void TopView(Node* root){ // level order traversal TC =>O(nlogn)
    queue<pair<Node*,int>> q;
    q.push({root , 0}); // node and hd 
    map<int , int > m; // hd and node 

    while(!q.empty()){

        Node* curr = q.front().first;
        int hd = q.front().second;

        q.pop();

        if(m.find(hd)==m.end()){
            m[hd] = curr->data;
        }

        if(curr->left!=NULL) q.push({curr->left , hd-1});
        if(curr->right!=NULL) q.push({curr->right , hd+1});

    }

    for(auto val : m){
        cout<<val.second<<" ";
    }

    cout<<endl;
}

void BottomView(Node* root){ // level order traversal TC =>O(nlogn)
    queue<pair<Node*,int>> q;
    q.push({root , 0}); // node and hd 
    map<int , int > m; // hd and node 

    while(!q.empty()){

        Node* curr = q.front().first;
        int hd = q.front().second;

        q.pop();

        
        m[hd] = curr->data;
        

        if(curr->left!=NULL) q.push({curr->left , hd-1});
        if(curr->right!=NULL) q.push({curr->right , hd+1});

    }

    for(auto val : m){
        cout<<val.second<<" ";
    }

    cout<<endl;
}


int main(){

    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder); 
    TopView(root);
    BottomView(root);

    return 0;
}