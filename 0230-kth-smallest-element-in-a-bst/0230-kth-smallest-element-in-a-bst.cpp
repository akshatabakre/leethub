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
    void pre(TreeNode* root, int& k,int& ans){
        if(!root || k<=0)   return;
        pre(root->left,k,ans);
        k--;
        if(k==0){
            ans = root->val;
            return;
        }
        pre(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        //preorder, ans
        int ans = 0;
        pre(root,k,ans);
        return ans;
    }
};