#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    Node* next[26];
    bool flag;

    bool containsKey(char ch ){
        return (next[ch-'a']!=NULL);
    }

    void put(char ch , Node* newNode){
        next[ch-'a'] = newNode;
    }

    Node* get(char ch){
        return next[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
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
        }

        currNode->setEnd();
    }

    bool searchWord(string str){ // TC => O(length)

        Node* currNode = root;

        for(int i=0; i<str.length(); i++){

            if(!currNode->containsKey(str[i])){
                return false;
            }

            currNode = currNode->get(str[i]);
        }

        return currNode->isEnd();
    }

    bool searchPrefix(string prefix){ // TC => O(length)

        Node* currNode = root;

        for(int i=0; i<prefix.length(); i++){

            if(!currNode->containsKey(prefix[i])){
                return false;
            }

            currNode = currNode->get(prefix[i]);
        }

        return true;
    }
};

int main(){
    Trie t;

    t.insert("batman");
    cout << t.searchWord("bat") << endl;      // 0
    cout << t.searchPrefix("bat") << endl;    // 1
    cout << t.searchWord("batman") << endl;   // 1
    return 0;
}