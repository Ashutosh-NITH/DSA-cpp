#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


// SC => O (n^2)
// TC => O(n^2 * log n) 
bool isSum0_optimised(vector<int> a , vector<int> b , vector<int> c){

    vector<int> temp ;

    // TC => O(n^2) ... SC => O(n^2)
    for(int i=0;  i<a.size(); i++){

        for (int j = 0; j < b.size(); j++){
            
            int sum = a[i] + b[j];
            temp.push_back(-sum);
        }   
    }

    // Here .. SORTING TC => O(n^2 * log n^2) => O(n^2 * log n) 
    sort(temp.begin() , temp.end());
    
    // TC => O(n*log n^2) => O(n*log n) 
    for (int val: c){

        int st = 0;
        int end = temp.size()-1;

        while (st<=end){
            
            int mid = st + (end-st)/2;

            if (temp[mid] < val){

                st = mid+1;

            }else if(temp[mid] > val){

                end = mid-1;

            }else{

                return true;
            }
            
        } 
    }

    /// SO EFFECTIVE TIOME COMPLEXITY IS :
    // TC => O(n^2) + O(n^2 * log n)  + O(n*log n) 
    // TC => O(n^2 * log n) 

return false;
}

//TC => O(n^2)
bool isSum0_Optimal(vector<int> a , vector<int> b , vector<int> c){

    // TC => O(nlogn)
    sort(a.begin(), a.end() , greater<int>());
    sort(b.begin(), b.end());

    // TC => O(n^2)
    for(int v: c){

        int val = -v;

        auto a_st = a.begin();
        auto b_st = b.begin();

        while (a_st != a.end() && b_st != b.end() ){
            
            int sum = *a_st + *b_st;

            if (sum < val){
                
                b_st++; //left 

            }else if(sum > val){

                a_st++; // down 

            }else{
                return true;
            }
        }
        
        
    }
return false; 
}

// SC => O(n)
// TC => O(n^2)
bool isSum0_Optial_usinghasing(vector<int> a , vector<int> b , vector<int> c){

    unordered_set<int> setC(c.begin() , c.end());

    for(int i=0;  i<a.size(); i++){

        for (int j = 0; j < b.size(); j++){
            
            int sum = a[i] + b[j];

            if (setC.find(-sum)!=setC.end()){ // beacuse unordered set uses constant time complexity to search  
                return true;
            }
            
        }   
    }
return false;
}

int main(){
    vector<int> a = {3 , 6 , -9 , -12 , 15};
    vector<int> b = {2, -5 , 8 , 13 , 17};
    vector<int> c = {1 , -3 , 5 , -10 , 15};

    // take one element from each array and find if sum is equal to 0 .. all three vector s are of same size

    cout<<isSum0_Optimal(a,b,c);

    return 0;
}