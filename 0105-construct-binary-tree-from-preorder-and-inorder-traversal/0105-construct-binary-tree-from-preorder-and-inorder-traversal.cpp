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
        for (int i = 0; i < inorder.size(); i++){
            pos[inorder[i]] = i;
        }
        int preInd = 0;
        return build(preorder, inorder, preInd, 0, inorder.size() - 1);
    }
private:
    unordered_map<int, int> pos;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preInd, int left, int right){
        if (left > right) return nullptr;
        TreeNode* node = new TreeNode(preorder[preInd++]);
        int mid = pos[node -> val];
        node -> left = build(preorder, inorder, preInd, left, mid - 1);
        node -> right = build(preorder, inorder, preInd, mid + 1, right);
        return node;
    }
};