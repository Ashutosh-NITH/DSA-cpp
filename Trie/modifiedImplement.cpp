#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    Node* next[26];
    int endCount = 0;
    int prefixCount = 0;

    Node(){
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
    }

    bool containsKey(char ch ){
        return (next[ch-'a']!=NULL);
    }

    void put(char ch , Node* newNode){
        next[ch-'a'] = newNode;
    }

    Node* get(char ch){
        return next[ch-'a'];
    }

    void incEndCount(){
        endCount++;
    }
    void incPrefixCount(){
        prefixCount++;
    }
    void decPrefixCount(){
        prefixCount--;
    }
    void decEndCount(){
        endCount--;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string str){ // TC => O(length)

        Node* currNode = root;
        for(int i=0; i<str.length(); i++){

            if(!currNode->containsKey(str[i])){
                
                currNode->put(str[i] , new Node());
            }
            currNode = currNode->get(str[i]);
            currNode->incPrefixCount();
        }

        currNode->incEndCount();
    }

    int countWordsEqualTo(string str){ // TC => O(length)

        Node* currNode = root;

        for(int i=0; i<str.length(); i++){

            if(!currNode->containsKey(str[i])){
                return 0;
            }

            currNode = currNode->get(str[i]);
        }

        return currNode->endCount;
    }

    int countPrefixStartingWith(string prefix){ // TC => O(length)

        Node* currNode = root;

        for(int i=0; i<prefix.length(); i++){

            if(!currNode->containsKey(prefix[i])){
                return 0;
            }

            currNode = currNode->get(prefix[i]);
        }

        return currNode->prefixCount;
    }

    void erase(string word){

        if(countWordsEqualTo(word) == 0) return;

        Node* currNode = root;

        for(int i=0; i<word.length(); i++){

            currNode = currNode->get(word[i]);
            currNode->decPrefixCount();
        }

        currNode->decEndCount();
    }
};

int main(){
    Trie t;

    t.insert("apple");
    t.insert("apple");
    t.insert("apps");
    t.insert("appl");
  
    cout << t.countWordsEqualTo("apple") << endl;    
    cout << t.countPrefixStartingWith("app") << endl;
    t.erase("apple");
    t.erase("app");
    cout << t.countWordsEqualTo("apple") << endl;
    cout << t.countPrefixStartingWith("app") << endl;
    return 0;
}