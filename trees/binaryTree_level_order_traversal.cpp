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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        vector<int> tem;
        queue<TreeNode*> q;
        if(root==nullptr)
        {
            return ans;
        }

        q.push(root);
        q.push(nullptr);

        while(!q.empty())
        {
            
            TreeNode* temp = q.front();
            
            q.pop();

            if(temp==nullptr)
            {
                ans.push_back(tem);
                tem.clear();
                if(!q.empty())
                {
                    q.push(nullptr);
                }
            }
            else
            {
                tem.push_back(temp->val);
                if(temp->left!=nullptr)
                {
                    q.push(temp->left);
                }
                if(temp->right!=nullptr)
                {
                    q.push(temp->right);
                }
            }

            

            
        }
        return ans;
        
    }
};