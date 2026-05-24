#include<iostream>
#include<vector>
using namespace std;

void changeX(int &x){
    x=2;
}

void changevec(vector<int> &vec){
    vec[0]=100;
}

int main(){
    int x = 5;
    vector<int> vec = {1,2,3};

    //pass by refrence / address 

    cout<<x<<endl;

    changeX(x);

    cout<<x<<endl;

    cout<<vec[0]<<endl;

    changevec(vec); 

    cout<<vec[0]<<endl;
    
    return 0;
}