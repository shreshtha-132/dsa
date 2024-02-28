/**




// intuition : traverse the tree in level order and add the last element from every level 




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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        // vector<int> temp;
        if(root==nullptr)
        {
            return ans;
        }
        else
        {
            q.push(root);
            q.push(nullptr);
            while(!q.empty())
            {
                TreeNode* top = q.front();
                q.pop();
                if(top==nullptr)
                {
                    if(!q.empty())
                    {
                        q.push(nullptr);
                    }
                }
                else 
                {
                    if(q.front()==nullptr)
                    {
                        ans.push_back(top->val);
                    }
                    if(top->left!=nullptr)
                    {
                        q.push(top->left);
                    }
                    if(top->right!=nullptr)
                    {
                        q.push(top->right);
                    }
                    
                }
                
                
                
            }
            return ans;
        }
        
    }
};