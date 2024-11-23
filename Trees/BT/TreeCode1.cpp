#include <iostream>
#include <algorithm>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode* root) {
    // Base case: if the node is null, its height is -1
    // (We use -1 here so that leaf nodes have a height of 0)
    if (root == nullptr) {
        return 0;
    }
    
    // Recursively calculate the height of left and right subtrees
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    // The height of the current node is the maximum of left and right subtree heights, plus 1
    return std::max(leftHeight, rightHeight) + 1;
}

// Function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    
    int height = getHeight(root);
    std::cout << "The height of the binary tree is: " << height << std::endl;
    
    return 0;
}