// #include <iostream>
// #include <stack>

// using namespace std;

// // Structure for BST node
// struct node {
//   int key;
//   struct node *left, *right;
// };

// // Create a new node
// struct node *newNode(int item) {
//   struct node *temp = new struct node;
//   temp->key = item;
//   temp->left = temp->right = NULL;
//   return temp;
// }

// // Inorder Iterator for BST
// class InorderIterator {
// private:
//   stack<node*> s; // Stack to keep track of nodes

// public:
//   // Constructor, initializes the iterator
//   InorderIterator(node* root) {
//     // Initialize the stack with leftmost nodes until reaching null
//     while (root != NULL) {
//       s.push(root);
//       root = root->left;
//     }
//   }

//   // Check if there's another node to visit
//   bool hasNext() {
//     return !s.empty(); // Returns true if stack is not empty
//   }

//   // Get the value of the next node in inorder traversal
//   int next() {
//     node* current = s.top(); // Get the top node from stack
//     s.pop(); // Remove the top node from stack
//     int key = current->key; // Get the key of the current node
//     current = current->right; // Move to the right child of the current node
//     // Push leftmost nodes of the right subtree onto the stack
//     while (current != NULL) {
//       s.push(current);
//       current = current->left;
//     }
//     return key; // Return the key of the current node
//   }
// };

// // Inorder Traversal (recursive)
// void inorder(node *root) {
//   if (root != NULL) {
//     // Traverse left subtree
//     inorder(root->left);
//     // Visit current node
//     cout << root->key << " -> ";
//     // Traverse right subtree
//     inorder(root->right);
//   }
// }

// // Insert a node into BST
// struct node *insert(struct node *node, int key) {
//   // If tree is empty, create new node
//   if (node == NULL) return newNode(key);
//   // Traverse left or right based on key value
//   if (key < node->key)
//     node->left = insert(node->left, key);
//   else
//     node->right = insert(node->right, key);
//   return node; // Return updated node
// }

// // Find the inorder successor (helper function for deleteNode)
// struct node *minValueNode(struct node *node) {
//   struct node *current = node;
//   // Find the leftmost leaf
//   while (current && current->left != NULL)
//     current = current->left;
//   return current;
// }

// // Delete a node from BST
// struct node *deleteNode(struct node *root, int key) {
//   // Return if tree is empty
//   if (root == NULL) return root;
//   // Find node to be deleted
//   if (key < root->key)
//     root->left = deleteNode(root->left, key);
//   else if (key > root->key)
//     root->right = deleteNode(root->right, key);
//   else {
//     // If node has only one child or no child
//     if (root->left == NULL) {
//       struct node *temp = root->right;
//       delete root;
//       return temp;
//     } else if (root->right == NULL) {
//       struct node *temp = root->left;
//       delete root;
//       return temp;
//     }
//     // If node has two children
//     struct node *temp = newNode(root->right->key);
//     while (temp->left != NULL)
//       temp = temp->left;
//     // Replace node to be deleted with inorder successor
//     root->key = temp->key;
//     // Delete inorder successor
//     root->right = deleteNode(root->right, temp->key);
//   }
//   return root; // Return updated root
// }

// // Driver code
// int main() {
//   struct node *root = NULL;
//   // Insert nodes into BST
//   root = insert(root, 8);
//   root = insert(root, 3);
//   root = insert(root, 1);
//   root = insert(root, 6);
//   root = insert(root, 7);
//   root = insert(root, 10);
//   root = insert(root, 14);
//   root = insert(root, 4);

//   // Print inorder traversal using InorderIterator
//   cout << "Inorder traversal: ";
//   InorderIterator it(root);
//   while (it.hasNext()) {
//     cout << it.next() << " ";
//   }

//   // Delete node with key 10
//   cout << "\nAfter deleting 10\n";
//   root = deleteNode(root, 10);

//   // Print inorder traversal after deletion
//   cout << "Inorder traversal: ";
//   InorderIterator it2(root);
//   while (it2.hasNext()) {
//     cout << it2.next() << " ";
//   }

//   return 0;
// }
//---
// #include <iostream>

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//     TreeNode* successor = nullptr;
//     while (root) {
//         if (p->val < root->val) {
//             successor = root;
//             root = root->left;
//         } else {
//             root = root->right;
//         }
//     }
//     return successor;
// }

// int main() {
//     // Constructing a sample BST
//     TreeNode* root = new TreeNode(20);
//     root->left = new TreeNode(10);
//     root->right = new TreeNode(30);
//     root->left->left = new TreeNode(5);
//     root->left->right = new TreeNode(15);

//     TreeNode* p = root->left; // Node with value 10

//     TreeNode* successor = inorderSuccessor(root, p);
//     if (successor) {
//         std::cout << "Inorder Successor of " << p->val << " is " << successor->val << std::endl;
//     } else {
//         std::cout << "Inorder Successor of " << p->val << " does not exist" << std::endl;
//     }

//     // Clean up
//     delete root->left->left;
//     delete root->left->right;
//     delete root->left;
//     delete root->right;
//     delete root;
//     return 0;
// }
//----
// #include <iostream>

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
//     TreeNode* predecessor = nullptr;
//     while (root) {
//         if (p->val > root->val) {
//             predecessor = root;
//             root = root->right;
//         } else {
//             root = root->left;
//         }
//     }
//     return predecessor;
// }

// int main() {
//     // Constructing a sample BST
//     TreeNode* root = new TreeNode(20);
//     root->left = new TreeNode(10);
//     root->right = new TreeNode(30);
//     root->left->left = new TreeNode(5);
//     root->left->right = new TreeNode(15);

//     TreeNode* p = root->left; // Node with value 10

//     TreeNode* predecessor = inorderPredecessor(root, p);
//     if (predecessor) {
//         std::cout << "Inorder Predecessor of " << p->val << " is " << predecessor->val << std::endl;
//     } else {
//         std::cout << "Inorder Predecessor of " << p->val << " does not exist" << std::endl;
//     }

//     // Clean up
//     delete root->left->left;
//     delete root->left->right;
//     delete root->left;
//     delete root->right;
//     delete root;
//     return 0;
// }
//-------
// #include <iostream>
// #include <limits>

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
//     if (!root) return true;
//     if (root->val <= minVal || root->val >= maxVal) return false;
//     return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
// }

// bool isValidBST(TreeNode* root) {
//     return isValidBST(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
// }

// int main() {
//     // Constructing a sample BST
//     TreeNode* root = new TreeNode(20);
//     root->left = new TreeNode(10);
//     root->right = new TreeNode(30);
//     root->left->left = new TreeNode(5);
//     root->left->right = new TreeNode(15);

//     if (isValidBST(root)) {
//         std::cout << "The tree is a valid BST." << std::endl;
//     } else {
//         std::cout << "The tree is not a valid BST." << std::endl;
//     }

//     // Clean up
//     delete root->left->left;
//     delete root->left->right;
//     delete root->left;
//     delete root->right;
//     delete root;
//     return 0;
// }
//-----
// #include <iostream>
// #include <limits>
// #include <cassert>

// // Definition for a binary tree node
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// private:
//     int minDiff;
//     TreeNode* prev;
    
//     void inorder(TreeNode* node) {
//         if (!node) return;
        
//         // Traverse left subtree
//         inorder(node->left);
        
//         // Process current node
//         if (prev) {
//             minDiff = std::min(minDiff, node->val - prev->val);
//         }
//         prev = node;
        
//         // Traverse right subtree
//         inorder(node->right);
//     }
    
// public:
//     int minDiffInBST(TreeNode* root) {
//         minDiff = std::numeric_limits<int>::max();
//         prev = nullptr;
//         inorder(root);
//         return minDiff;
//     }
// };

// // Function to clean up the tree
// void deleteTree(TreeNode* root) {
//     if (!root) return;
//     deleteTree(root->left);
//     deleteTree(root->right);
//     delete root;
// }

// void test_min_diff_bst() {
//     // Test case 1:
//     //       4
//     //      / \
//     //     2   6
//     //    / \
//     //   1   3
//     TreeNode* root1 = new TreeNode(4);
//     root1->left = new TreeNode(2);
//     root1->right = new TreeNode(6);
//     root1->left->left = new TreeNode(1);
//     root1->left->right = new TreeNode(3);
    
//     Solution solution;
//     assert(solution.minDiffInBST(root1) == 1);  // Minimum difference is 1 (between 1-2, 2-3, 3-4)
    
//     // Clean up memory for first test case
//     deleteTree(root1);
    
//     // Test case 2:
//     //       90
//     //      /  
//     //     69   
//     //      \
//     //       89
//     TreeNode* root2 = new TreeNode(90);
//     root2->left = new TreeNode(69);
//     root2->left->right = new TreeNode(89);
    
//     assert(solution.minDiffInBST(root2) == 1);  // Minimum difference is 1 (between 89-90)
    
//     // Clean up memory for second test case
//     deleteTree(root2);
    
//     std::cout << "All test cases passed!" << std::endl;
// }

// int main() {
//     test_min_diff_bst();
//     return 0;
// }
//-------

#include <iostream>
#include <cassert>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Base case: empty tree
        if (!root) {
            return 0;
        }
        
        // If current node's value is less than low,
        // we only need to consider the right subtree
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        
        // If current node's value is greater than high,
        // we only need to consider the left subtree
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        
        // If current value is within range,
        // include it and recurse on both subtrees
        return root->val + 
               rangeSumBST(root->left, low, high) + 
               rangeSumBST(root->right, low, high);
    }
};

// Helper function to clean up memory
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void test_range_sum_bst() {
    // Create test tree:
    //       10
    //      /  \
    //     5   15
    //    / \    \
    //   3   7    18
    
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    
    Solution solution;
    
    // Test case 1: range [7, 15]
    assert(solution.rangeSumBST(root, 7, 15) == 32);  // 7 + 10 + 15
    
    // Test case 2: range [3, 7]
    assert(solution.rangeSumBST(root, 3, 7) == 15);  // 3 + 5 + 7
    
    // Test case 3: range [18, 18]
    assert(solution.rangeSumBST(root, 18, 18) == 18);  // just 18
    
    std::cout << "All test cases passed!" << std::endl;
    
    // Clean up memory
    deleteTree(root);
}

int main() {
    test_range_sum_bst();
    return 0;
}