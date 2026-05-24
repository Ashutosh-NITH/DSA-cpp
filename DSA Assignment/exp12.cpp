#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    char c;
    int f;

    Node(char ch, int freq) {
        c = ch;
        f = freq;
        left = right = NULL;
    }
};

void swapNodes(Node* &a, Node* &b) {
    Node* temp = a;
    a = b;
    b = temp;
}

void heapifyMin(vector<Node*> &heap, int heapSize, int i) {

    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < heapSize && heap[left]->f < heap[smallest]->f)
        smallest = left;

    if(right < heapSize && heap[right]->f < heap[smallest]->f)
        smallest = right;

    if(smallest != i) {
        swapNodes(heap[i], heap[smallest]);
        heapifyMin(heap, heapSize, smallest);
    }
}

Node* extractMin(vector<Node*> &heap, int &heapSize) {

    if(heapSize <= 0)
        return NULL;

    Node* minNode = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heap.pop_back();


    heapifyMin(heap, heapSize, 0);

    return minNode;
}

void buildMinHeap(vector<Node*> &heap, int heapSize) {
    for(int i = (heapSize - 2) / 2; i >= 0; i--) {
        heapifyMin(heap, heapSize, i);
    }
}

Node* buildHuffmanTree(vector<char> chars, vector<int> freq) {

    vector<Node*> heap;

    // Step 1: Create leaf nodes
    for(int i = 0; i < chars.size(); i++) {
        heap.push_back(new Node(chars[i], freq[i]));
    }

    int heapSize = heap.size();
    buildMinHeap(heap, heapSize);

    // Build Huffman tree
    while(heapSize > 1) {

        Node* x = extractMin(heap, heapSize);
        Node* y = extractMin(heap, heapSize);

        Node* newNode = new Node('$', x->f + y->f);
        newNode->left = x;
        newNode->right = y;

        heap.push_back(newNode);
        heapSize++;

        // Percolate up to maintain min-heap
        int i = heapSize - 1;
        while(i != 0 && heap[(i - 1) / 2]->f > heap[i]->f) {
            swapNodes(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    return heap[0];
}

void printCodes(Node* root, string code) {

    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL && root->c != '$') {
        cout << root->c << " : " << code << endl;
        return;
    }

    printCodes(root->left,  code + "0");
    printCodes(root->right, code + "1");
}

int main() {

    vector<char> chars = {'a','b','c','d','e','f'};
    vector<int> freq  = {5,  9,  12, 13, 16, 45};

    Node* root = buildHuffmanTree(chars, freq);

    cout << "\nHuffman Codes:\n";
    printCodes(root , "");

    return 0;
}
