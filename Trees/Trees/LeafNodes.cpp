#include <iostream>
#include <vector>

// TreeNode class represents a node in the tree
template<typename T>
class TreeNode {
public:
    T data;
    std::vector<TreeNode*> children;

    TreeNode(T value) : data(value) {}

    // Destructor to clean up child nodes
    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }
};

// Tree class represents the entire tree
template<typename T>
class Tree {
private:
    TreeNode<T>* root;

    // Recursive helper function to count leaf nodes
    int countLeafNodesHelper(TreeNode<T>* node) const {
        if (node == nullptr) {
            return 0;
        }

        // If the node has no children, it's a leaf node
        if (node->children.empty()) {
            return 1;
        }

        int leafCount = 0;
        // Recursively count leaf nodes in all subtrees
        for (TreeNode<T>* child : node->children) {
            leafCount += countLeafNodesHelper(child);
        }

        return leafCount;
    }

public:
    Tree() : root(nullptr) {}

    void setRoot(T value) {
        root = new TreeNode<T>(value);
    }

    TreeNode<T>* getRoot() const {
        return root;
    }

    void addChild(TreeNode<T>* parent, T value) {
        if (parent) {
            parent->children.push_back(new TreeNode<T>(value));
        }
    }

    // Public function to count leaf nodes
    int countLeafNodes() const {
        return countLeafNodesHelper(root);
    }

    // Destructor
    ~Tree() {
        delete root;  // This will trigger recursive deletion of all nodes
    }
};

int main() {
    Tree<char> tree;
    tree.setRoot('A');

    TreeNode<char>* root = tree.getRoot();
    tree.addChild(root, 'B');
    tree.addChild(root, 'C');
    tree.addChild(root, 'D');

    tree.addChild(root->children[0], 'E');
    tree.addChild(root->children[0], 'F');
    tree.addChild(root->children[2], 'G');
    tree.addChild(root->children[2], 'H');

    int leafCount = tree.countLeafNodes();
    std::cout << "Number of leaf nodes: " << leafCount << std::endl;

    return 0;
}