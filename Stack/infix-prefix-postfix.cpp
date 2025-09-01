// operators => { ^ > * , / > +,- }
// operands => A-Z , a-z , 0-9 

// when operators are between the operands => INFIX => (p+q)*(m-n)
// when operators are before the operands => PREFIX  => * + p q - m n
// when operators are after the operands => POSTFIX => p q + m n - *

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string ans = "";

    for(int i = 0; i < infix.size(); i++) {
        char c = infix[i];

        // If operand → add to result
        if((c >= 'A' && c <= 'Z') || 
           (c >= 'a' && c <= 'z') || 
           (c >= '0' && c <= '9')) {
            ans += c;
        }
        // If '(' → push
        else if(c == '(') {
            s.push(c);
        }
        // If ')' → pop until '('
        else if(c == ')') {
            while(!s.empty() && s.top() != '(') {
                ans += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop(); // pop '('
        }
        // Operator
        else {
            while(!s.empty() && 
                 ((priority(c) < priority(s.top())) || 
                  (priority(c) == priority(s.top()) && c != '^'))) {
                ans += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main(){
    string  infix = "a+b*(c^d-e)";

    string ans = infixToPostfix(infix);
    cout<<ans<<endl;

    return 0;
}