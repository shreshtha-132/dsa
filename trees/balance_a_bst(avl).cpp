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
    vector<int> vect;
    void help(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        else
        {
            help(root->left);
            vect.push_back(root->val);
            help(root->right);
        }
    }
    TreeNode* create(int s,int e)
    {
        if(s>e)
        {
            return nullptr;
        }
        int mid = (s+e)/2;
        TreeNode* temp = new TreeNode(vect[mid]);
        temp->left = create(s,mid-1);
        temp->right = create(mid+1,e);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root==nullptr)
        {
            return root;
        }
        help(root);
        root = create(0,vect.size()-1);
        return root;
        
    }
};