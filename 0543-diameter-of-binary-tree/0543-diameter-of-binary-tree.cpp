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
    int Longest = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return Longest;
    }
    int maxDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        else {
            int LeftMax = maxDepth(root -> left);
            int RightMax = maxDepth(root -> right);
            Longest = max(Longest, LeftMax + RightMax);
            return 1 + max(LeftMax, RightMax);
        }
    }
};