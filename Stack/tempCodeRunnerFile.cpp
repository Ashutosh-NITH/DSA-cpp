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

// INFIX TO PREFIX CONVERSION STEPS :
// 1. reverse the given infix expression
// 2. after reversing convert the opening bracket to closing bracket and closing bracket to opening bracket
// 3. then convert it from infix to postfix
// 4. then again reverse the postfix ans

string reverse(string str){
    string ans;
    for(int i=str.length()-1 ;i>=0 ; i--){
        ans+=str[i];
    }

    
return ans;
}
string infixToPrefix(string infix){

    string ans = reverse(infix); // step 1

    for(int i=0; i<ans.length(); i++){ //step 2
        if(ans[i]=='(') ans[i]=')';
        else if(ans[i]==')') ans[i]='(';
    }

    ans = infixToPostfix(ans); //step 3

    ans = reverse(ans); //step 4
    return ans;
}


int main(){
    string infix = "a+b*(c^d-e)";
    string infix2 = "(a+b)*c-d+f";

    string ans = infixToPostfix(infix);
    string ans2 = infixToPrefix(infix2);
    cout<<ans<<endl;
    cout<<ans2<<endl;

    return 0;
}