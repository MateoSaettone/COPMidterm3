// #include <iostream>
// #include <algorithm>

// // Definition for a binary tree node
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// int getHeight(TreeNode* root) {
//     // Base case: if the node is null, its height is -1
//     // (We use -1 here so that leaf nodes have a height of 0)
//     if (root == nullptr) {
//         return 0;
//     }
    
//     // Recursively calculate the height of left and right subtrees
//     int leftHeight = getHeight(root->left);
//     int rightHeight = getHeight(root->right);
    
//     // The height of the current node is the maximum of left and right subtree heights, plus 1
//     return std::max(leftHeight, rightHeight) + 1;
// }

// // Function to create a sample binary tree
// TreeNode* createSampleTree() {
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->right->left = new TreeNode(6);
//     root->left->left->left = new TreeNode(7);
//     return root;
// }

// int main() {
//     TreeNode* root = createSampleTree();
    
//     int height = getHeight(root);
//     std::cout << "The height of the binary tree is: " << height << std::endl;
    
//     return 0;
// }

//g++ -std=c++11  binary_tree_codes.cpp -o bt
//------

// #include <iostream>

// // Definition for a binary tree node
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     bool evaluateTree(TreeNode* root) {
//         // Base case: leaf node
//         if (root->left == nullptr && root->right == nullptr) {
//             return root->val == 1;
//         }
        
//         // Evaluate left and right subtrees
//         bool leftEval = evaluateTree(root->left);
//         bool rightEval = evaluateTree(root->right);
        
//         // Apply the boolean operation
//         if (root->val == 2) {  // OR operation
//             return leftEval || rightEval;
//         } else {  // AND operation
//             return leftEval && rightEval;
//         }
//     }
// };

// // Function to create a sample boolean expression tree
// TreeNode* createSampleTree() {
//     TreeNode* root = new TreeNode(2);  // OR
//     root->left = new TreeNode(1);      // True
//     root->right = new TreeNode(3);     // AND
//     root->right->left = new TreeNode(0);   // False
//     root->right->right = new TreeNode(1);  // True
//     return root;
// }

// int main() {
//     TreeNode* root = createSampleTree();
//     Solution solution;
//     bool result = solution.evaluateTree(root);
//     std::cout << "The evaluation result is: " << (result ? "True" : "False") << std::endl;
//     return 0;
// }

//-------
// #include <iostream>
// #include <cmath>

// // Definition for a binary tree node
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// private:
//     int tiltSum = 0;

//     int order(TreeNode* root) {
//         if (root == nullptr) {
//             return 0;
//         }

//         // Recursively calculate sum of left and right subtrees
//         int leftSum = order(root->left);
//         int rightSum = order(root->right);

//         // Calculate tilt of current node and add to tiltSum
//         tiltSum += std::abs(leftSum - rightSum);

//         // Return sum of current subtree
//         return leftSum + rightSum + root->val;
//     }

// public:
//     int findTilt(TreeNode* root) {
//         tiltSum = 0;
//         order(root);
//         return tiltSum;
//     }
// };

// // Function to create a sample binary tree
// TreeNode* createSampleTree() {
//     TreeNode* root = new TreeNode(4);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(9);
//     root->left->left = new TreeNode(3);
//     root->left->right = new TreeNode(5);
//     root->right->right = new TreeNode(7);
//     return root;
// }

// int main() {
//     TreeNode* root = createSampleTree();
//     Solution solution;
//     int result = solution.findTilt(root);
//     std::cout << "The sum of tilt of the binary tree is: " << result << std::endl;
//     return 0;
// }
//-----

// #include <iostream>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// int height(TreeNode* root) {
//     if (root == nullptr) return 0;
//     return max(height(root->left), height(root->right)) + 1;
// }

// bool isBalanced(TreeNode* root) {
//     if (root == nullptr) return true;
//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
// }

// int main() {
//     TreeNode* root = new TreeNode(3);
//     root->left = new TreeNode(9);
//     root->right = new TreeNode(20);
//     root->right->left = new TreeNode(15);
//     root->right->right = new TreeNode(7);

//     if (isBalanced(root)) {
//         cout << "The tree is balanced." << endl;
//     } else {
//         cout << "The tree is not balanced." << endl;
//     }

//     return 0;
// }
//-------

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int depth = maxDepth(root);
    cout << "The maximum depth of the tree is: " << depth << endl;

    return 0;
}
