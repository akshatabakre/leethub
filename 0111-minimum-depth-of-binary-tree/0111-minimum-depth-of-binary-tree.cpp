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
    int solve(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        int l = 1e9, r = 1e9;
        if(root->left!=NULL){
            l = 1 + solve(root->left);
        }
        if(root->right!=NULL){
            r = 1 + solve(root->right);
        }
        return min(l,r);
    }
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        return 1+solve(root);
    }
};