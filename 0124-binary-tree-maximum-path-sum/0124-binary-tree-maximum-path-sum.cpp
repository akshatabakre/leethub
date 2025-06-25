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
    int leafToNodeSum(TreeNode* root,int& maxsum){
        if(!root)   return 0;
        int leftsum = max(0,leafToNodeSum(root->left,maxsum));
        int rightsum = max(0,leafToNodeSum(root->right,maxsum));
        maxsum = max(root->val + leftsum + rightsum, maxsum);
        return root->val + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = -1e9;
        int s = leafToNodeSum(root,maxsum);
        return maxsum;
    }
};