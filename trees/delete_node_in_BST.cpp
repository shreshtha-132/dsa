class Solution {
public:
    void help(TreeNode* &root, int key) {
        if (root == nullptr) {
            return;
        } else if (key < root->val) {
            help(root->left, key);
        } else if (key > root->val) {
            help(root->right, key);
        } else {
            // Node with the given key found
            if (root->left == nullptr && root->right == nullptr) {
                // Case: 0 child
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                // Case: 1 child (right)
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                // Case: 1 child (left)
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            } else {
                // Case: 2 children
                TreeNode* successor = findMin(root->right);
                root->val = successor->val;
                help(root->right, successor->val);
            }
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        help(root, key);
        return root;
    }
};
