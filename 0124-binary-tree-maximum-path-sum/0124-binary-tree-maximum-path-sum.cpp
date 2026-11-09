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
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        gain(root, best);
        return best;
    }
private:
    int gain(TreeNode* node, int& best){
        if (!node) return 0;
        int left = max(gain(node -> left, best), 0);
        int right = max(gain(node -> right, best), 0);
        best = max(best, node -> val + left + right);
        return node -> val + max(left, right);
    }
};