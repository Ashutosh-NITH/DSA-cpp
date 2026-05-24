#include<iostream>
using namespace std;

class ThreeStacks {
public:
    int *arr;
    int n;
    int top1, top2, top3;
    int size;

    ThreeStacks(int capacity) {
        n = capacity;
        arr = new int[n];

        size = n / 3;

        top1 = -1;
        top2 = size - 1;
        top3 = 2*size - 1;
    }

    void push1(int x) {
        if(top1 + 1 >= size) { cout << "Stack 1 Overflow\n"; return; }
        arr[++top1] = x;
    }

    void push2(int x) {
        if(top2 + 1 >= 2*size) { cout << "Stack 2 Overflow\n"; return; }
        arr[++top2] = x;
    }

    void push3(int x) {
        if(top3 + 1 >= n) { cout << "Stack 3 Overflow\n"; return; }
        arr[++top3] = x;
    }

    int pop1() {
        if(top1 < 0) { cout << "Stack 1 Underflow\n"; return -1; }
        return arr[top1--];
    }

    int pop2() {
        if(top2 < size) { cout << "Stack 2 Underflow\n"; return -1; }
        return arr[top2--];
    }

    int pop3() {
        if(top3 < 2*size) { cout << "Stack 3 Underflow\n"; return -1; }
        return arr[top3--];
    }

    
};

int main() {
    ThreeStacks ts(9);

    ts.push1(1);
    ts.push2(20);
    ts.push3(300);

    cout << ts.pop1() << endl; 
    cout << ts.pop2() << endl;
    cout << ts.pop3() << endl;

    return 0;
}
