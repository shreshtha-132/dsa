/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;

    void help(TreeNode* root, int currentSum) {
        if (root == nullptr) {
            return;
        }

        currentSum = currentSum * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            // Handle Leaf Nodes
            sum += currentSum;
        } else {
            help(root->left, currentSum);
            help(root->right, currentSum);
        }
    }

    int sumNumbers(TreeNode* root) {
        help(root, 0);
        return sum;
    }
};
