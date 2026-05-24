#include<iostream>
#include<stack>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int val;
};

void inorder_goto(Node* root){
    
    const int MAX = 100;
    Node* s[MAX];
    int top = -1;
    Node* curr = root;

start: 

    while(curr!=NULL){

        s[++top] = curr;
        curr = curr->left;

    }

    if(top==-1) return;

    curr = s[top--];
    cout<<curr->val<<" "<<endl;

    curr = curr->right;

goto start;

}
void inorder(Node* root ){

    stack<Node*> s;
    Node* curr = root;

    while(curr!=NULL || !s.empty()){

        while(curr!=NULL){

            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout<<curr->val<<" ";

        curr = curr->right;
    }
}


int main(){
    
    
return 0;
}