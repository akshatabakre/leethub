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
    TreeNode* preorder(TreeNode* n,int p,int q){
        if(!n){
            return NULL;
        }
        if(n->val>=p && n->val<=q || n->val<=p && n->val>=q){
            return n;
        }
        if(n->val<p && n->val<q){
            return preorder(n->right,p,q);
        }
        return preorder(n->left,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return preorder(root,p->val,q->val);
    }
};