#include<iostream>
using namespace std;

class Node {
public:
    int data ;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

class Linked_List {
public:
    Node* head;
    Node* tail;
 
    Linked_List(){
        head = tail = NULL;
    }

    void push_front(int val){

        Node* newNode = new Node(val); 
        if(head == NULL){
            head = tail = newNode;
        }else{
            (*newNode).next = head;
            head = newNode;
        }
    }

    void push_back(int val){ 
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
        }else{
            (*tail).next = newNode;
            tail = newNode;

        }
    }

    void print_linked_list(){
        Node* temp = head;

        while(temp != NULL){
            cout<<(*temp).data<<" -> ";
            temp = (*temp).next; 
        }
        cout<<"NULL"<<endl;
    }

    void pop_front(){ //O(1)

        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = (*head).next;
        delete temp;
    }

    void  pop_back(){   //O(n)
        if(tail == NULL){
            return;
        }else{
            Node* temp = head;
            while( (*((*temp).next)).next != NULL ){
                temp = (*temp).next;
            }
            (*temp).next = NULL;
            delete tail;
            tail = temp;
        }
    }
};

void reverseLinkedList(Linked_List& l){

    if(l.head==NULL) return;

    Node* prev = NULL;
    Node* curr = l.head;
    Node* next = NULL;

    l.tail = curr;

    while (curr!=NULL){

        next = curr->next;
        
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    l.head = prev;

}

int main(){
    Linked_List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.print_linked_list();
    reverseLinkedList(ll);
    ll.print_linked_list();
return 0;
}