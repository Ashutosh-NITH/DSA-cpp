#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//TC => O(n)
//SC => O(n) 

// In total, you do at most n pushes and at most n pops to/from the stack across the entire loop.

// Every element enters and leaves the stack only once.
//  Total operations = 2n ⇒
// ✅ Time Complexity = O(n)

void StockSpan(vector<int> &price){

    vector<int> ans (price.size(),0);
    stack<int> PrevHigh;

    for(int i=0; i<price.size(); i++){

        while (PrevHigh.size()>0 && price[PrevHigh.top()] <= price[i] ){
            PrevHigh.pop();
        }
        if(PrevHigh.size()==0){ // no prev high => span = i+1;
            ans[i] =  i+1;
        }else{ // when there is prev High => span = i - prevHigh ;
            ans[i] = i - PrevHigh.top();
        }

        PrevHigh.push(i);
        
    }

    for(int val : ans){
        cout<<val<<" ";
    }

}

int main(){

    vector<int> prices = {100,80,60,70,65,75,85};

    StockSpan(prices);

    
    return 0;
}