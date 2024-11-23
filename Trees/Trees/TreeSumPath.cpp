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

    // Recursive helper function for path sum
    bool hasPathSumHelper(TreeNode<T>* node, T sum) const {
        if (node == nullptr) {
            return false;
        }

        // Subtract the current node's value from the sum
        sum -= node->data;

        // If it's a leaf node and the sum has become zero, we've found a valid path
        if (node->children.empty() && sum == 0) {
            return true;
        }

        // Recursively check all child nodes
        for (TreeNode<T>* child : node->children) {
            if (hasPathSumHelper(child, sum)) {
                return true;
            }
        }

        return false;
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

    // Public function to check for path sum
    bool hasPathSum(T sum) const {
        return hasPathSumHelper(root, sum);
    }

    // Destructor
    ~Tree() {
        delete root;  // This will trigger recursive deletion of all nodes
    }
};

int main() {
    Tree<int> tree;
    tree.setRoot(10);

    TreeNode<int>* root = tree.getRoot();
    tree.addChild(root, 5);
    tree.addChild(root, 3);
    tree.addChild(root, 7);

    tree.addChild(root->children[0], 3);
    tree.addChild(root->children[0], 2);
    tree.addChild(root->children[1], 4);
    tree.addChild(root->children[2], 8);
    tree.addChild(root->children[2], 1);

    int targetSum = 20;  // We're looking for a path sum of 20
    
    if (tree.hasPathSum(targetSum)) {
        std::cout << "Path found with sum " << targetSum << std::endl;
    } else {
        std::cout << "No path found with sum " << targetSum << std::endl;
    }

    targetSum = 25;  // Now we're looking for a path sum of 25
    
    if (tree.hasPathSum(targetSum)) {
        std::cout << "Path found with sum " << targetSum << std::endl;
    } else {
        std::cout << "No path found with sum " << targetSum << std::endl;
    }

    return 0;
}