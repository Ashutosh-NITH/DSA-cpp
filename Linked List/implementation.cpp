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
    Node* head;
    Node* tail;
public: 
    Linked_List(){
        head = tail = NULL;
    }

    void push_front(int val){  //O(1)

        Node* newNode = new Node(val); // new keyword gives instance(address) of the object created which what lhs wants
        if(head == NULL){
            head = tail = newNode;
        }else{
            (*newNode).next = head;
            head = newNode;
        }
    }

    void push_back(int val){ //O(1)
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
        }else{
            (*tail).next = newNode;
            tail = newNode;

        }
    }

    void print_linked_list(){ //O(n)
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

    void insert_at(int val , int pos){  //O(n)
        if(pos<0){
            cout<<"invalid postion"<<endl;
            return ;
        }else if(pos == 0){
            push_front(val);
        }else{
            Node* newNode = new Node(val);

            Node* temp = head;

            for(int i=0 ; i<pos-1; i++){
                if(temp == NULL){
                    cout<<"invalid position"<<endl;
                    return ;
                }
                temp = (*temp).next ;
            }
            (*newNode).next = (*temp).next;
            (*temp).next = newNode;
        }
    }



    int search (int target){ //O(n)
        Node* temp = head ;
        int index = 0 ;

        while(temp !=NULL){
            if((*temp).data == target ){
                return index;
            }
            index ++;
            temp = (*temp).next;
           
        }
        return index;

        return -1;
    }
};


int main(){
    Linked_List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.insert_at(7,1);
    ll.insert_at(3,50);
    ll.print_linked_list();
    cout<<ll.search(7);

return 0;
}