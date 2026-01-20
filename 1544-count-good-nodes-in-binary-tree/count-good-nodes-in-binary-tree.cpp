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

    void helper(TreeNode* root, int max_node, int &count) {
        if (root == NULL) {
            return;
        }
        if (root->val >= max_node) {
            max_node = root->val;
            count++;
        }
        helper(root->left, max_node, count);
        helper (root->right, max_node, count);
    }

    int goodNodes(TreeNode* root) {
        int max_node = INT_MIN;
        int count = 0;
        helper (root, max_node, count); 
        return count;
    }
};