#include<iostream>
#include<list>
using namespace std;

//top element of stack will be our head of linked list
class Stack{
    list<int> l;

public: 
     void push(int val){ //O(n)

        l.push_front(val);

    }

    int top(){ //O(n)
        return l.front();
    }

    void pop(){ //O(n)
        l.pop_front();
    }

    bool empty(){ //O(n)
        return l.size()==0;
    }

};

int main(){
    Stack s;

    s.push(7);
    s.push(10);
    s.push(12);
    s.push(20);

    
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
        
    }
    return 0;
}