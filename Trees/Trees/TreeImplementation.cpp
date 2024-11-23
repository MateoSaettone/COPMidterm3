#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // For std::find

// TreeNode class represents a single node in the tree
template<typename T>
class TreeNode {
public:
    T data;                          // Data stored in the node
    std::vector<TreeNode*> children; // Vector to store pointers to child nodes

    // Constructor initializes a node with given data
    TreeNode(T value) : data(value) {}
};

// Tree class represents the entire tree structure
template<typename T>
class Tree {
private:
    TreeNode<T>* root; // Pointer to the root node of the tree

public:
    // Constructor initializes an empty tree
    Tree() : root(nullptr) {}

    // Sets the root of the tree with given value
    void setRoot(T value) {
        root = new TreeNode<T>(value);
    }

    // Returns pointer to the root node
    TreeNode<T>* getRoot() const {
        return root;
    }

    // Adds a child node with given value to the specified parent node
    void addChild(TreeNode<T>* parent, T value) {
        if (parent == nullptr) {
            std::cout << "Parent node is null. Cannot add child." << std::endl;
            return;
        }
        parent->children.push_back(new TreeNode<T>(value));
    }

    // Removes a specified child node from its parent
    void removeNode(TreeNode<T>* parent, TreeNode<T>* nodeToRemove) {
        if (parent == nullptr || nodeToRemove == nullptr) {
            std::cout << "Parent or node to remove is null." << std::endl;
            return;
        }

        // Find the node to remove in the parent's children vector
        auto it = std::find(parent->children.begin(), parent->children.end(), nodeToRemove);
        if (it != parent->children.end()) {
            delete *it; // Free the memory of the removed node
            parent->children.erase(it); // Remove the pointer from the vector
        } else {
            std::cout << "Node not found as a child of the given parent." << std::endl;
        }
    }

    // Performs a post-order traversal of the tree
    void postOrderTraversal(TreeNode<T>* node) const {
        if (node == nullptr) {
            return;
        }

        // First, visit all children
        for (TreeNode<T>* child : node->children) {
            postOrderTraversal(child);
        }
        // Then, process the current node
        std::cout << node->data << " ";
    }

    // Destructor
    ~Tree() {
        // TODO: Implement a proper destructor to free all allocated memory
        // This should involve a recursive deletion of all nodes in the tree
        // Current implementation may lead to memory leaks
    }
};

// Example usage of the Tree class
int main() {
    // Create a tree and set its root
    Tree<int> tree;
    tree.setRoot(1);

    // Get the root node and add children
    TreeNode<int>* root = tree.getRoot();
    tree.addChild(root, 2);
    tree.addChild(root, 3);
    tree.addChild(root, 4);

    // Add grandchildren
    tree.addChild(root->children[0], 5);
    tree.addChild(root->children[0], 6);
    tree.addChild(root->children[2], 7);

    // Perform post-order traversal
    std::cout << "\nPost-order Traversal:" << std::endl;
    tree.postOrderTraversal(root);
    std::cout << std::endl;

    // Remove a node (node with value 3, which is the second child of root)
    std::cout << "\nRemoving node with value 3..." << std::endl;
    tree.removeNode(root, root->children[1]);

    // Display tree structure after removal
    std::cout << "\nTree Structure after removal:" << std::endl;
    tree.postOrderTraversal(root);

    // Attempt to remove a non-existent node
    std::cout << "\nTrying to remove a non-existent node..." << std::endl;
    TreeNode<int>* nonExistentNode = new TreeNode<int>(100);
    tree.removeNode(root, nonExistentNode);
    delete nonExistentNode;  // Clean up the temporary node

    return 0;
}