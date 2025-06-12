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
    int traverse(TreeNode* root,int& maxsum){
        if(!root)   return 0;
        int l = max(0,traverse(root->left,maxsum));
        int r = max(0,traverse(root->right,maxsum));
        maxsum = max(maxsum,root->val + l + r);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = -1e9;
        traverse(root,maxsum);
        return maxsum;
    }
};