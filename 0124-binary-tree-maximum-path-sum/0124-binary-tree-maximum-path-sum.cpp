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
    int solve(TreeNode* root,int& maxi){
        if(!root)   return 0;
        int l = solve(root->left,maxi);
        int r = solve(root->right,maxi);
        l = max(0,l);
        r = max(0,r);
        maxi = max(maxi,root->val+l+r);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        int root_to_leaf_max_sum = solve(root,maxi);
        return maxi;
    }
};