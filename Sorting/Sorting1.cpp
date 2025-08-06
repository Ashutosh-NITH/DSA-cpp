#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int> &arr){ //TC =>O(n^2)
    int n = arr.size();
    //push the max to the last

    for(int i=0;  i<n-1; i++){

        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    

}

void SelectionSort(vector<int> &arr){ //TC =>O(n^2)
    
    int n = arr.size();

    for(int i=0; i<=n-2; i++){

        int min = i;

        for(int j = i; j<=n-1 ; j++){

            if(arr[j]<arr[min]) min = j;
        }

        swap(arr[i], arr[min]);
    }

}

void InsertionSort(vector<int> &arr){ //TC =>O(n^2)

    for(int i=1; i<arr.size(); i++){

        int curr = arr[i];
        int prev = i-1;

        while(prev>=0 && arr[prev]>curr){
            
            arr[prev+1] = arr[prev];
            prev--;

        }

        arr[prev+1] = curr;

    }
}

int main(){
    vector<int> vec;
    vec.push_back(15);
    vec.push_back(5);
    vec.push_back(25);
    vec.push_back(20);
    vec.push_back(7);

    cout<<"before sorting "<<endl;
    for(int i=0 ; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    



    // SelectionSort(vec);

    // BubbleSort(vec);

    InsertionSort(vec);


    cout<<endl<<"after sorting "<<endl;
    for(int i=0 ; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    
    return 0;
}