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
    // void preord(TreeNode* node,vector<int>& ans){
    //     if(node==NULL){
    //         return;
    //     }
    //     ans.push_back(node->val);
    //     preord(node->left,ans);
    //     preord(node->right,ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        // preord(root,ans);
        // return ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* n = s.top();
            ans.push_back(n->val);
            s.pop();
            if(n->right!=NULL)
                s.push(n->right);
            if(n->left!=NULL)
                s.push(n->left);
        }
        return ans;
    }
};