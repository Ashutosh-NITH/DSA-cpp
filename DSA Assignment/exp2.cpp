#include<iostream>
using namespace std;

class Node{
public:
    Node* next;
    int val;

    Node(int data){
        val = data;
        next = NULL;
    }
};

class CircularLinkedList{
public:

    Node* head;
    Node* tail;

    CircularLinkedList(){
        tail = head = NULL;
    }

    void push_back(int data){

        Node* newNode = new Node(data);

        if(tail==NULL){

            head = tail = newNode;
            tail->next = head;

        }else{

            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            
        }
    }

    void push_front(int data){
        
        Node* newNode = new Node(data);

        if(head==NULL){

            head = tail = newNode;
            tail->next = head;

        }else{

            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void traverse(){

        if(tail==NULL) return;

        cout<<head->val<<" -> ";
        Node* temp = head->next;

        

        while(temp!=head){
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }

        cout<<temp->val<<endl;
    }

};

int main(){

    CircularLinkedList cll;

    cll.push_back(4);
    cll.push_back(5);
    cll.push_back(7);
    cll.push_back(10);
    cll.push_back(15);
    cll.push_front(2);
    cll.push_front(1);

    cll.traverse();
    
    return 0;
}