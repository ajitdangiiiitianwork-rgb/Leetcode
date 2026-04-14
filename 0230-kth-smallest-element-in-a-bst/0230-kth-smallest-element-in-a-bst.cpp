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
        vector<int> ans;

        while(curr != NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            // curr is null now
            curr = st.top();
            st.pop();

            ans.push_back(curr->val);
            curr = curr->right;
        }
        int data;
        for(int i = 0; i < k; i++){
            data = ans[i];
        }

        return data;
    }
};