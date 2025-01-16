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
    void postord(TreeNode* n,vector<int>& ans){
        if(n==NULL){
            return;
        }
        postord(n->left,ans);
        postord(n->right,ans);
        ans.push_back(n->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postord(root,ans);
        return ans;
    }
};