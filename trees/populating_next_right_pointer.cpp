/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node*>> ans;
    vector<Node*> v;
    void help(Node* root)
    {
        if(root==nullptr)
        {
            return;
        }
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp==nullptr)
            {
                ans.push_back(v);
                v.clear();
                if(!q.empty())
                {
                    q.push(nullptr);
                }
            }
            else
            {
                v.push_back(temp);
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
    }
    Node* connect(Node* root) {
        if(root==nullptr)
        {
            
        }
        else
        {
            help(root);
            //performm level ordering and for each level the vectors present, the 
            // elements would point to next element until last.
            for (auto& subvector : ans) {
                for (size_t i = 0; i < subvector.size() - 1; ++i) {
                    subvector[i]->next = subvector[i + 1];
                }
                // Set the last node's next to nullptr
                if (!subvector.empty()) {
                    subvector.back()->next = nullptr;
                }
        }


        }
        return root;
    }
};