/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(!root)   return NULL;
        // if(root==p) return root;
        // if(root==q) return root;
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        // if(left && right)           return root;
        // else if(!left && !right){
        //     return NULL;
        // }else{
        //     if(left)   return left;
        //     else
        //         return right;
        // }
        return (!left)? right : (!right)? left : root;
    }
};