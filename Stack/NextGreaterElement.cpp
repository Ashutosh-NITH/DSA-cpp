#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//TC =>O(N)
//SC =>O(N)


void NextGreaterElement(vector<int> &vec){
    vector<int> ans(vec.size() , -1);
    stack<int> s;
    
    for(int i=vec.size()-1; i>=0; i--){

        while (s.size()>0 && s.top()<vec[i]){
            s.pop();
        }

        if(s.size()>0 && s.top()>vec[i]){
            ans[i] = s.top();
        }
        

       s.push(vec[i]);
        
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}


int main(){
    
    vector<int> vec = {6,8,0,1,3};

    NextGreaterElement(vec);

    return 0;
}