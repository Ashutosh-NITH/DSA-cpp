#include<iostream>
using namespace std;


class Node{
public:
    int data ;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DLL {
    Node* head;
    Node* tail;

public:
    DLL(){
        head=tail=NULL;
    }

    void push_front(int val){

        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }else{
            newNode->next  = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(tail==NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;

       if(head!=NULL){
         head->prev = NULL;
       }
        temp->next = NULL;

        delete temp;
    }

    void pop_back(){
        if(tail==NULL){
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        
        if(tail!=NULL){
            tail->next =  NULL;
        }

        temp->prev =NULL;

        delete temp;

    }

    void printDLL(){

        Node* temp = head;

        while(temp!=NULL){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }

        cout<<" NULL "<<endl;

    }

};
int main(){
    DLL dll;

    dll.push_front(7);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_back(0);
    dll.push_back(1);

    dll.printDLL();
    dll.pop_back();
    dll.printDLL();
    dll.pop_back();
    dll.printDLL();
    dll.pop_back();
    dll.printDLL();

    return 0;
}