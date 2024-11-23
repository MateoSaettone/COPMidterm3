
'''
Example tree implementation
'''
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm> // For std::find

// // TreeNode class represents a single node in the tree
// template<typename T>
// class TreeNode {
// public:
//     T data;                          // Data stored in the node
//     std::vector<TreeNode*> children; // Vector to store pointers to child nodes

//     // Constructor initializes a node with given data
//     TreeNode(T value) : data(value) {}
// };

// // Tree class represents the entire tree structure
// template<typename T>
// class Tree {
// private:
//     TreeNode<T>* root; // Pointer to the root node of the tree

// public:
//     // Constructor initializes an empty tree
//     Tree() : root(nullptr) {}

//     // Sets the root of the tree with given value
//     void setRoot(T value) {
//         root = new TreeNode<T>(value);
//     }

//     // Returns pointer to the root node
//     TreeNode<T>* getRoot() const {
//         return root;
//     }

//     // Adds a child node with given value to the specified parent node
//     void addChild(TreeNode<T>* parent, T value) {
//         if (parent == nullptr) {
//             std::cout << "Parent node is null. Cannot add child." << std::endl;
//             return;
//         }
//         parent->children.push_back(new TreeNode<T>(value));
//     }

//     // Removes a specified child node from its parent
//     void removeNode(TreeNode<T>* parent, TreeNode<T>* nodeToRemove) {
//         if (parent == nullptr || nodeToRemove == nullptr) {
//             std::cout << "Parent or node to remove is null." << std::endl;
//             return;
//         }

//         // Find the node to remove in the parent's children vector
//         auto it = std::find(parent->children.begin(), parent->children.end(), nodeToRemove);
//         if (it != parent->children.end()) {
//             delete *it; // Free the memory of the removed node
//             parent->children.erase(it); // Remove the pointer from the vector
//         } else {
//             std::cout << "Node not found as a child of the given parent." << std::endl;
//         }
//     }

//     // Performs a post-order traversal of the tree
//     void postOrderTraversal(TreeNode<T>* node) const {
//         if (node == nullptr) {
//             return;
//         }

//         // First, visit all children
//         for (TreeNode<T>* child : node->children) {
//             postOrderTraversal(child);
//         }
//         // Then, process the current node
//         std::cout << node->data << " ";
//     }

//     // Destructor
//     ~Tree() {
//         // TODO: Implement a proper destructor to free all allocated memory
//         // This should involve a recursive deletion of all nodes in the tree
//         // Current implementation may lead to memory leaks
//     }
// };

// // Example usage of the Tree class
// int main() {
//     // Create a tree and set its root
//     Tree<int> tree;
//     tree.setRoot(1);

//     // Get the root node and add children
//     TreeNode<int>* root = tree.getRoot();
//     tree.addChild(root, 2);
//     tree.addChild(root, 3);
//     tree.addChild(root, 4);

//     // Add grandchildren
//     tree.addChild(root->children[0], 5);
//     tree.addChild(root->children[0], 6);
//     tree.addChild(root->children[2], 7);

//     // Perform post-order traversal
//     std::cout << "\nPost-order Traversal:" << std::endl;
//     tree.postOrderTraversal(root);
//     std::cout << std::endl;

//     // Remove a node (node with value 3, which is the second child of root)
//     std::cout << "\nRemoving node with value 3..." << std::endl;
//     tree.removeNode(root, root->children[1]);

//     // Display tree structure after removal
//     std::cout << "\nTree Structure after removal:" << std::endl;
//     tree.postOrderTraversal(root);

//     // Attempt to remove a non-existent node
//     std::cout << "\nTrying to remove a non-existent node..." << std::endl;
//     TreeNode<int>* nonExistentNode = new TreeNode<int>(100);
//     tree.removeNode(root, nonExistentNode);
//     delete nonExistentNode;  // Clean up the temporary node

//     return 0;
// }
//-------------------
'''Find required sum path'''

// #include <iostream>
// #include <vector>

// // TreeNode class represents a node in the tree
// template<typename T>
// class TreeNode {
// public:
//     T data;
//     std::vector<TreeNode*> children;

//     TreeNode(T value) : data(value) {}

//     // Destructor to clean up child nodes
//     ~TreeNode() {
//         for (TreeNode* child : children) {
//             delete child;
//         }
//     }
// };

// // Tree class represents the entire tree
// template<typename T>
// class Tree {
// private:
//     TreeNode<T>* root;

//     // Recursive helper function for path sum
//     bool hasPathSumHelper(TreeNode<T>* node, T sum) const {
//         if (node == nullptr) {
//             return false;
//         }

//         // Subtract the current node's value from the sum
//         sum -= node->data;

//         // If it's a leaf node and the sum has become zero, we've found a valid path
//         if (node->children.empty() && sum == 0) {
//             return true;
//         }

//         // Recursively check all child nodes
//         for (TreeNode<T>* child : node->children) {
//             if (hasPathSumHelper(child, sum)) {
//                 return true;
//             }
//         }

//         return false;
//     }

// public:
//     Tree() : root(nullptr) {}

//     void setRoot(T value) {
//         root = new TreeNode<T>(value);
//     }

//     TreeNode<T>* getRoot() const {
//         return root;
//     }

//     void addChild(TreeNode<T>* parent, T value) {
//         if (parent) {
//             parent->children.push_back(new TreeNode<T>(value));
//         }
//     }

//     // Public function to check for path sum
//     bool hasPathSum(T sum) const {
//         return hasPathSumHelper(root, sum);
//     }

//     // Destructor
//     ~Tree() {
//         delete root;  // This will trigger recursive deletion of all nodes
//     }
// };

// int main() {
//     Tree<int> tree;
//     tree.setRoot(10);

//     TreeNode<int>* root = tree.getRoot();
//     tree.addChild(root, 5);
//     tree.addChild(root, 3);
//     tree.addChild(root, 7);

//     tree.addChild(root->children[0], 3);
//     tree.addChild(root->children[0], 2);
//     tree.addChild(root->children[1], 4);
//     tree.addChild(root->children[2], 8);
//     tree.addChild(root->children[2], 1);

//     int targetSum = 20;  // We're looking for a path sum of 20
    
//     if (tree.hasPathSum(targetSum)) {
//         std::cout << "Path found with sum " << targetSum << std::endl;
//     } else {
//         std::cout << "No path found with sum " << targetSum << std::endl;
//     }

//     targetSum = 25;  // Now we're looking for a path sum of 25
    
//     if (tree.hasPathSum(targetSum)) {
//         std::cout << "Path found with sum " << targetSum << std::endl;
//     } else {
//         std::cout << "No path found with sum " << targetSum << std::endl;
//     }

//     return 0;
// }
//-------
'''Count number of leaf nodes'''
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