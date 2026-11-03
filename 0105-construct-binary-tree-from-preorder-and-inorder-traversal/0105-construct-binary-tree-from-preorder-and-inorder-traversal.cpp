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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;          
        }
        int preIdx = 0;
        return build(preorder, preIdx, 0, inorder.size() - 1);
    }
private:
    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& preorder, int& preIdx, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        TreeNode* node = new TreeNode(preorder[preIdx++]);
        int inMid = pos[node->val];       
        node->left  = build(preorder, preIdx, inLeft, inMid - 1);
        node->right = build(preorder, preIdx, inMid + 1, inRight);
        return node;
    }
};