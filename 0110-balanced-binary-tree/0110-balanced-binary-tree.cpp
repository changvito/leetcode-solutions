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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        else if (abs(maxDepth(root -> right) - maxDepth(root -> left)) > 1){
            return false;
        }
        else {
            return isBalanced(root -> left) && isBalanced(root -> right);
        }
        return true;
    }
private:
    int maxDepth(TreeNode* root){
        int Max = 0;
        if (root == nullptr){
            return 0;
        }
        else {
            int LeftMax = maxDepth(root -> left);
            int RightMax = maxDepth(root -> right);
            return 1 + max(LeftMax, RightMax);
        }

    }
};