class Solution {
public:
    bool isBST(TreeNode* root, long long min, long long max) {
        if (root == nullptr) {
            return true;
        } else if (root->val > min && root->val < max) {
            return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
        } else {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};
