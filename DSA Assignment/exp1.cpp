#include<iostream>
using namespace std;

class Node{
public: 

    Node* next;
    int coeff;
    int power;

    Node(int c , int p){
        coeff = c;
        power = p;
        next = NULL;
    }
};

class Polynomial{
public: 
    Node* head;

    Polynomial(){
        head = NULL;
    }

    void insert(int c , int p ){

        if(c==0) return;

        Node* newNode = new Node(c , p);

        if(head==NULL){

            head = newNode;
            return;
        }

        if(head->power<p){

            newNode->next = head;
            head=newNode;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while(temp && p < temp->power){
            prev = temp;
            temp = temp->next;
        }

        if(temp && temp->power == p){

            temp->coeff+=c;

            delete newNode;
            return ;

        }else{
            prev->next = newNode;
            newNode->next = temp;

            return;
        }
        
    }

    void print(){

        Node* temp = head;

        while(temp!=NULL){

            if(temp->power == 0 ){

                cout<<temp->coeff;

            }else{
                cout<<temp->coeff<<"x^"<<temp->power<<" + ";
            }
            
            temp = temp->next;
        }
        cout<<endl;
    }
};

Polynomial addTwoPolynomial(Polynomial& p1, Polynomial& p2){

    Polynomial result;
    Node* t1 = p1.head;
    Node* t2 = p2.head;

    while(t1 && t2){

        if(t1->power == t2->power){

            int coefficient = t1->coeff + t2->coeff;
            
            result.insert(coefficient , t1->power);

            t1 = t1->next;
            t2 = t2->next;

        }else if(t1->power < t2->power){

            result.insert(t2->coeff , t2->power);

            t2 = t2->next;

        }else{

            result.insert(t1->coeff , t1->power);

            t1 = t1->next;

        }
    }

    while(t1){
       result.insert(t1->coeff , t1->power);

        t1 = t1->next;
    }
    while(t2){
       result.insert(t2->coeff , t2->power);

        t2 = t2->next;
    }
return result;
}

int main(){

    Polynomial p1;
    Polynomial p2;

    // 1st polynomial: 2x⁸ − 5x⁷ − 3x² + 4
    p1.insert(2, 8);
    p1.insert(-5, 7);
    p1.insert(-3, 2);
    p1.insert(4, 0);

    // 2nd polynomial: x⁷ + 5x² + x + 3
    p2.insert(1, 7);
    p2.insert(5, 2);
    p2.insert(1, 1);
    p2.insert(3, 0);

    p1.print();
    p2.print();
    
    Polynomial result = addTwoPolynomial(p1, p2);
    result.print();

    return 0;
}