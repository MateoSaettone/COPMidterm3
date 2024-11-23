#include <iostream>
#include <cmath>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int tiltSum = 0;

    int order(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate sum of left and right subtrees
        int leftSum = order(root->left);
        int rightSum = order(root->right);

        // Calculate tilt of current node and add to tiltSum
        tiltSum += std::abs(leftSum - rightSum);

        // Return sum of current subtree
        return leftSum + rightSum + root->val;
    }

public:
    int findTilt(TreeNode* root) {
        tiltSum = 0;
        order(root);
        return tiltSum;
    }
};

// Function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution solution;
    int result = solution.findTilt(root);
    std::cout << "The sum of tilt of the binary tree is: " << result << std::endl;
    return 0;
}