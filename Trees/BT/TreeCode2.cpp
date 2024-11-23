#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // Base case: leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == 1;
        }
        
        // Evaluate left and right subtrees
        bool leftEval = evaluateTree(root->left);
        bool rightEval = evaluateTree(root->right);
        
        // Apply the boolean operation
        if (root->val == 2) {  // OR operation
            return leftEval || rightEval;
        } else {  // AND operation
            return leftEval && rightEval;
        }
    }
};

// Function to create a sample boolean expression tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(2);  // OR
    root->left = new TreeNode(1);      // True
    root->right = new TreeNode(3);     // AND
    root->right->left = new TreeNode(0);   // False
    root->right->right = new TreeNode(1);  // True
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution solution;
    bool result = solution.evaluateTree(root);
    std::cout << "The evaluation result is: " << (result ? "True" : "False") << std::endl;
    return 0;
}
