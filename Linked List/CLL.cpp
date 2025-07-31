#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;
    Node* tail;

public:

    CircularLinkedList(){
        head=tail=NULL;
    }

    void insert_at_head(int val){

        Node* newNode = new Node(val);

        if(tail==NULL){

            tail = head = newNode;
            tail->next = head;

        }else{

            newNode->next = head;
            head = newNode;
            tail->next = newNode;
        }
    }

    void insert_at_tail(int val){

        Node* newNode = new Node(val);

        if(tail==NULL){

            tail = head = newNode;
            tail->next = head;

        }else{

          tail->next = newNode;
          newNode->next = head;
          tail = newNode;
        }
    }

    void delete_at_head(){
        if(head==NULL){
            return;
        }else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void delete_at_tail(){
        if(head==NULL){
            return;
        }else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            Node* temp = head;
            
            while(temp->next->next != head ){
                temp =  temp->next;
            }

            tail = temp;
            temp = temp->next;
            tail ->next = head;
            temp->next = NULL;
            delete  temp;
        }
    }

    void printCLL(){

        if(tail==NULL){
            return;
        }

        cout<<head->data<<" -> ";
        Node* temp = head->next;

        

        while(temp!=head){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }

        cout<<temp->data<<endl;
        
    }

};


int main(){

    CircularLinkedList cll;
    cll.insert_at_head(7);
    cll.insert_at_head(5);
    cll.insert_at_head(3);
    cll.insert_at_tail(1);

    cll.printCLL();

    cll.delete_at_head();

    cll.printCLL();
    
    cll.delete_at_tail();

    cll.printCLL();
    
    return 0;
}