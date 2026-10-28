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
        dfs(root, 0, Ans);
        return Ans;
    }
private:
    void dfs(TreeNode* t, int depth, vector<vector<int>>& Ans){
        if (!t){
            return;
        }
        if (depth == Ans.size()){
            Ans.push_back({});
        }
        Ans[depth].push_back(t -> val);
        dfs(t -> left, depth + 1, Ans);
        dfs(t -> right, depth + 1, Ans);
    }
};