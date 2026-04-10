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
    bool isValidBSThelper(TreeNode* node, long minValue, long maxValue){
        if(!node) return true;
        if(node->val <= minValue) return false;
        if(node->val >= maxValue) return false;
        return isValidBSThelper(node->left, minValue, node->val) && isValidBSThelper(node->right, node->val, maxValue);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSThelper(root, LONG_MIN, LONG_MAX);
    }
};