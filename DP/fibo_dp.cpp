#include<iostream>
#include<vector>
using namespace std;

// memosation => topp to bottom approach
int fibonaciiUsingDP(int n , vector<int> &dp){
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = fibonaciiUsingDP(n-1 , dp) + fibonaciiUsingDP(n-2 , dp);
}

// tabulation => bottom to up approach

// int fibonacciiUsingTabDP(int n){
//     vector<int> dp(n+1, -1);
//     dp[0]=0;
//     dp[1]=1;

//     for(int i=2; i<=n; i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
// return dp[n];
// }

// optimisation 
int fibonacciiUsingTabDP(int n){
   int prev = 1;
   int prev2 = 0;

    for(int i=2; i<=n; i++){
        int curr = prev + prev2;
        prev2=prev;
        prev=curr;
    }
return prev;
}
int main(){
    int n=6;
    vector<int> dp(n+1, -1);
    cout<<fibonaciiUsingDP(n,dp);
    cout<<endl;
    cout<<fibonacciiUsingTabDP(n);
    return 0;
}