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
    // void postord(TreeNode* n,vector<int>& ans){
        // if(n==NULL){
        //     return;
        // }
        // postord(n->left,ans);
        // postord(n->right,ans);
        // ans.push_back(n->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // postord(root,ans);
        stack<TreeNode*> st1, st2;
        if(!root)   return ans;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node = st1.top();
            st1.pop();
            if(node->left!=NULL)
                st1.push(node->left);
            if(node->right!=NULL)
                st1.push(node->right);
            st2.push(node);
        }
        while(!st2.empty()){
            TreeNode* n = st2.top();
            ans.push_back(n->val);
            st2.pop();
        }
        return ans;
    }
};