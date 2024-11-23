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