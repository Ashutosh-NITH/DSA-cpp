#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> vec;

public: 

    void push(int val){ //O(n)

        vec.push_back(val);

    }

    int top(){ //O(n)
        return vec[vec.size()-1];
    }

    void pop(){ //O(n)
        vec.pop_back();
    }

    bool empty(){ //O(n)
        return vec.size()==0;
    }

};

int main(){

    Stack stk;

    stk.push(7);
    stk.push(10);
    stk.push(12);
    stk.push(20);

    
    while(!stk.empty()){
        cout<<stk.top()<<endl;
        stk.pop();
        
    }

    return 0;
}