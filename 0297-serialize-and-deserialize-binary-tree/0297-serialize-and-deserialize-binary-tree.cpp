/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root -> val) + "," + serialize(root -> left) + "," + serialize(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return build(in);
    }
private:
    TreeNode* build(istringstream& in){
        string token;
        getline(in, token, ',');
        if (token == "#") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(token));
        node -> left = build(in);
        node -> right = build(in);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));