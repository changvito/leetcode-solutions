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
        int preIdx = 0;
        return build(preorder, inorder, preIdx, 0, preorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIdx, int inLeft, int inRight){
        if (inLeft > inRight) return nullptr;
        TreeNode* node =new TreeNode(preorder[preIdx++]);
        int inMid = inLeft;
        while(inorder[inMid] != node -> val){
            inMid++;
        }
        node -> left = build(preorder, inorder, preIdx, inLeft, inMid - 1);
        node -> right = build(preorder, inorder, preIdx, inMid + 1, inRight);
        return node;
    }
};