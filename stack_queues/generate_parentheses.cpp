

class Solution {
public:
    vector<string> ans;
    
    void generate(int n, int openCount, int closeCount, string current) {
        if (openCount == n && closeCount == n) {
            ans.push_back(current);
            return;
        }
        
        if (openCount < n) {
            generate(n, openCount + 1, closeCount, current + '(');
        }
        
        if (closeCount < openCount) {
            generate(n, openCount, closeCount + 1, current + ')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        generate(n, 0, 0, "");
        return ans;
    }
};
