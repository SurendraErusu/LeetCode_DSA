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

    void helper(TreeNode* root, vector<int> &level, int depth) {
        if (root == NULL) {
            return;
        }
        if (depth == level.size()) {
            level.push_back(root->val);
        }
        helper(root->right, level, depth+1);
        helper(root->left, level, depth+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> level;
        helper(root,level, 0);
        return level;
    }

};