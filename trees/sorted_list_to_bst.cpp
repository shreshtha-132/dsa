/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> temp;
    TreeNode* help(int s,int e)
    {
        if(s>e)
        {
            return nullptr;
        }
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(temp[mid]);
        root->left = help(s,mid-1);
        root->right = help(mid+1,e);
        return root;

    }

    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* ans;
        if(head==nullptr)
        {
            return ans;
        }
        else
        {
            
            while(head!=nullptr)
            {
                temp.push_back(head->val);
                head= head->next;
                
            }
            ans = help(0,temp.size()-1);
            return ans;
        }


        
    }
};