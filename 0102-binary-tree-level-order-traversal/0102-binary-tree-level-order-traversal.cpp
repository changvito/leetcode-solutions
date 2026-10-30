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
        vector<vector<int>> Ans;
        if (!root) return Ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> Level;
            int n = q.size();
            for (int i = 0; i < n; i++ ){
                TreeNode* Temp = q.front();
                q.pop();
                Level.push_back(Temp -> val);
                if(Temp -> left) q.push(Temp -> left);
                if(Temp -> right) q.push(Temp -> right);
            }
            Ans.push_back(Level);
        }
        return Ans;
    }
};