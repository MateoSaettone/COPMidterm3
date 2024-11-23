#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree(): root(nullptr) {} //Constructor

    void CreateTree (int rootValue) {
        root = new Node();
        root->value = rootValue;
        root->left = nullptr;
        root->right = nullptr;
    }
};
    


int main() {

    
    
    return 0;
}