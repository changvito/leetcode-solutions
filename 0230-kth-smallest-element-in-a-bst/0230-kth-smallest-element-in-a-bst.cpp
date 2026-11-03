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
    int kthSmallest(TreeNode* root, int k) {
        Count = k;
        inorder(root);
        return Ans;
    }
private:
    int Ans;
    int Count;
    void inorder(TreeNode* node){
        if (!node || Count == 0) return;
        inorder(node -> left);
        if(--Count == 0){
            Ans = node -> val;
            return;
        }
        inorder(node -> right);
    }
};