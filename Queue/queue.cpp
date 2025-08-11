#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int v){
        val = v;
        next = NULL;
    }

};

class Queue{

    Node* head;
    Node* tail;

public:

    Queue(){
        tail = head = NULL;
    }

    int front(){
        if(head == NULL) return -1;
        return (head->val);
    }

    void push(int val){

        Node* newNode = new Node(val);

        if(head==NULL){

            head = tail = newNode;

        }else{

            tail->next = newNode;
            tail = newNode;
        }
        
    }

    void pop(){

        if(head == NULL ) return ;

        Node* temp = head;

        head = head->next;

        temp->next = NULL;

        delete temp;

    }

    bool empty(){

        if(head == NULL) return true;
        else return false;
        
    }
    

};

int main(){

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    while(!q.empty()){
        cout<<q.front();
        q.pop();
        
    }
    
    return 0;
}