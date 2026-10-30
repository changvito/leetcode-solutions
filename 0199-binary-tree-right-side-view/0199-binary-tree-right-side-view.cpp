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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> Ans;
        if(!root) return Ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Ans.push_back(q.front() -> val);
            for (int i = 0; i < n; i++){
                TreeNode* Temp = q.front();
                q.pop();
                if (Temp -> right) q.push(Temp -> right);
                if (Temp -> left) q.push(Temp -> left);
            }
        }
        return Ans;
    }
};