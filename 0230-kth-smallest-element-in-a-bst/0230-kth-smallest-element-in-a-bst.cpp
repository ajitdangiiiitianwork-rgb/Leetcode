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
        // using the concept of inorder traversal
        // kth node in inorder traversal

        stack<TreeNode*> st;
        TreeNode* curr = root;

        int data;
        while((curr != NULL || !st.empty()) && k != 0){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            // curr is null now
            curr = st.top();
            st.pop();

            data = curr->val;
            k--;
            curr = curr->right;
        }
        

        return data;
    }
};